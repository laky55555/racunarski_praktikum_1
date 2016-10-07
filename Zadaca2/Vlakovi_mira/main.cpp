#include <iostream>
#include "vlakovi.h"
#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

void ispisListe(list<string> p)
{
    list <string>::iterator it;
    for (it=p.begin();it!=p.end();it++)
    {
        cout << *it << endl;
    }
}

void ispisMape(map<pair <string, string>, int> p)
 {
     map < pair <string, string>,int >::iterator it;
     for (it=p.begin();it!=p.end();it++)
     {
         cout << it->first.first <<" " << it->first.second << " " << it->second << endl;
     }
 }

 void ispisVektora(vector<pair<string, string> > p)
 {
    for(int i=0;i<p.size();i++) cout << (p[i]).first<<" "<<(p[i]).second<<" ";
    cout<<endl;
}

 void ispisSeta(set<string> p)
{
    for(set<string>::iterator i=p.begin();i!=p.end();i++) cout << *i <<" ";
    cout<<endl;
}
int main()
{
    vlakovi test;
    test.dodaj(string("split"), string ("perkovic"), 30);
    test.dodaj(string("split"), string ("perkovic"), 40);
    test.dodaj(string ("zagreb"), string("karlovac"),60);
    test.dodaj(string("zagreb"), string ("rijeka"), 110);
    test.dodaj(string("zagreb"), string ("vinkovci"), 160);
    test.dodaj(string("karlovac"), string ("rijeka"), 45);
    test.dodaj(string("split"), string ("gospic"), 120);
    test.dodaj(string("gospic"), string ("karlovac"), 40);
    ispisMape(test.cjenik);
    cout <<" " << endl;
    test.ukloni(string("zagreb"), string("vinkovci"));
    ispisMape(test.cjenik);
    cout << " " << endl;
    ispisListe(test.susjednaMjesta(string("zagreb")));
    cout<< " "<< endl;
    cout<<test.najskupljaLinija().first<<" "<<test.najskupljaLinija().second<<endl;
    ispisSeta(test.mjesta());
// gospic karlovac perkovic rijeka split zagreb
    ispisVektora(test.linijeJeftinijeOd(41));
// gospic karlovac karlovac gospic perkovic split split perkovic
    cout<<test.mozeJeftinije("zagreb", "rijeka")<<endl;
// 1
    return 0;
}
