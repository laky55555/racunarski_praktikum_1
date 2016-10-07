#include <map>
#include <utility>
#include <list>
#include "graf.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
void ispisMape(map<pair<string, string>, int> p)
{
    map<pair<string, string>, int>::iterator i;
    for(i=p.begin();i!=p.end();i++)
        cout << i->first.first<<" - "<<i->first.second<<"  "<< i->second<<endl;
    cout<<endl;
}

void ispisMapeNove(map<int, pair<pair<string, string>, int> > x)
{
    map<int, pair<pair<string, string>, int> >::iterator i;
    for (i= x.begin(); i!=x.end(); i++ )
        cout << i->second.first.first<<" - "<<i->second.first.second<<"  "<< i->second.second<<endl;
}



/*
void ispisListe(list<string> p)
{
    for(list<string>::iterator i=p.begin();i!=p.end();i++)
        cout << *i <<"  ";     cout<<endl;
}
void ispisSkupa(set<string> p)
{
    for(set<string>::iterator i=p.begin();i!=p.end();i++)
        cout << *i <<"     ";
    cout<<endl;
}*/
int main(void)
{
    graf test;
    test.dodaj("a","b",30);
    test.dodaj("a","c",40);
    test.dodaj("a","g",60);
    test.dodaj("b","d",110);
    test.dodaj("a","d",160);
    test.dodaj("f","g",45);
    test.dodaj("g","g",120);
    test.dodaj("g","a",40);
    test.dodaj("g","a",40);
    test.dodaj("a","b",40);
    test.dodaj("c","a",40);
    test.dodaj("e","a",40);

    ispisMape(test.bridovi);     //    a b 30     a c 40     a g 60     b d 120     a d 160     f g 45     g a 40     c a 40     e a 40
    ispisMapeNove(test.redosljed);
   /* test.ukloni("f", "g");
    
    ispisMape(test.bridovi);     //    a b 30     a c 40     a g 60     b d 120     a d 160     g a 40     c a 40     e a 40
  //  ispisLip(test.redosljed);
    cout<<test.stupanj1("a")<<"      "<<test.stupanj2("d")<<endl;     //    4      2

    ispisListe(test.vrhovi());     //    a b c g d e

    cout<<test.najlaksiBridTeziOd(50).first<<" "<<test.najlaksiBridTeziOd(50).second<<endl;     //    a g

   // ispisSkupa(test.dohvatljiviIz("a"));     //    a b c g d
*/
    return 0;
}
