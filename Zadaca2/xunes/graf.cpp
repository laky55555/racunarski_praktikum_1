#include <map>
#include <utility>
#include <list>
#include "graf.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

void graf::dodaj(string p, string d, int n)
{
    pair<string,string> par;
    int a;
    map<pair<string, string>, int>::iterator i;
    if (p != d)
    {
        a=0;
        for(i=bridovi.begin(); i!=bridovi.end(); i++)
            if (p == i->first.first && d == i->first.second)
                a = 1;
            
        
        if (a == 0)
        {
            par.first = p;
            par.second = d;
            bridovi[par] = n;
            i--;
            redosljed.push_back(i);
        }

    }
    
}

void graf::ukloni(string p, string d)
{
    map<pair<string, string>, int>::iterator i;
    for (i=bridovi.begin(); i!=bridovi.end(); i++)
        if (i->first.first == p && i->first.second == d)
            bridovi.erase(i);
}

int graf::stupanj1(string p)
{
    int suma=0;
    map<pair<string, string>, int>::iterator i;
    for (i=bridovi.begin(); i!=bridovi.end(); i++)
        if (i->first.first == p)
            suma++;
    return suma;
}

int graf::stupanj2(string p)
{
    int suma=0;
    map<pair<string, string>, int>::iterator i;
    for (i=bridovi.begin(); i!=bridovi.end(); i++)
        if (i->first.second == p)
            suma++;
    return suma;
}

list<string> graf::vrhovi()
{
    cout << "Pocetak"; 
    list<string> a;
    list<string>::iterator j;
    list<map<pair<string, string>, int>::iterator >::iterator i;
 /*   for(i=redosljed.begin(); i!=redosljed.end(); i++)
    {
        map<pair<string, string>, int>::iterator uz;
        uz = (*i);
        cout << uz->first.first<<" - "<<uz->first.second<<"  "<< uz->second<<endl;
    cout<<endl; 
    }*/
   
    for(i=redosljed.begin(); i!=redosljed.end(); i++)
    {
        map<pair<string, string>, int>::iterator pot = (*i);
        int provjera_a=0, provjera_b=0;
        for (j=a.begin(); j!=a.end(); j++)
        {
           // cout <<" df  " << (*j);
            if((*j) == pot->first.first)
                provjera_a = 1;
            if((*j) == pot->first.second)
                provjera_b = 1;
        }
        cout <<endl;
        if (provjera_a == 0){
            a.push_back(pot->first.first); cout << pot->first.first;}
        if (provjera_b == 0){
            a.push_back(pot->first.second); cout << pot->first.second;}
        
        
    }
        cout << "Kraj"<<endl; 

    return a;
}

pair<string, string> graf::najlaksiBridTeziOd(int c)
{
    pair<string, string> a;
    int pocetak=0;
    map<pair<string, string>, int>::iterator i,j;
    for (i=bridovi.begin(); i!=bridovi.end(); i++)
        if(i->second > c && (pocetak == 0 || j->second > i->second))
        {
            pocetak = 1;
            j = i;
        }
    a.first = j->first.first;
    a.second = j->first.second;
    return a;

}
//set<string> graf::dohvatljiviIz(string s);

