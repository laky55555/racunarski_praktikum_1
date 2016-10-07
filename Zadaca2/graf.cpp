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
    int a=0;
    if (p != d)
    {
        map<pair<string, string>, int>::iterator i;
        for(i=bridovi.begin(); i!=bridovi.end(); i++)
            if (p == i->first.first && d == i->first.second)
                a = 1;
        if (a == 0)
        {
            par.first = p;
            par.second = d;
            bridovi[par] = n;
        }
    }
}

void graf::ukloni(string p, string d)
{
    map<pair<string, string>, int>::iterator i;
    for (i=bridovi.begin(); i!=bridovi.end(); i++)
    {
        if (i->first.first == p && i->first.second == d)
        {
            bridovi.erase(i);
            break;
        }
    }
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
    list<string> a;
    list<string>::iterator j;
    map<pair<string, string>, int>::iterator i;
    for (i=bridovi.begin(); i!=bridovi.end(); i++)
    {
        int provjera_a=0, provjera_b=0;
        for (j=a.begin(); j!=a.end(); j++)
        {
            if((*j) == i->first.first)
                provjera_a = 1;
            if((*j) == i->first.second)
                provjera_b = 1;
        }
        if (provjera_a == 0)
            a.push_back(i->first.first);
        if (provjera_b == 0)
            a.push_back(i->first.second);
    }
    return a;
}

pair<string, string> graf::najlaksiBridTeziOd(int c)
{
    pair<string, string> a;
    int pocetak=0;
    map<pair<string, string>, int>::iterator i,j;
    for (i=bridovi.begin(); i!=bridovi.end(); i++)
    {
        if(i->second > c && (pocetak == 0 || j->second > i->second))
        {
            pocetak = 1;
            j = i;
        }
    }
    if (pocetak==0)
    {
        a.first = '\0';
        a.second = '\0';
    }
    else
    { 
        a.first = j->first.first;
        a.second = j->first.second;
    }
    return a;

}

set<string> graf::dohvatljiviIz(string s)
{
    int novi;
    set<string> podskup;
    skup.insert(s);
    map<pair<string, string>, int>::iterator i;
    for(i=bridovi.begin(); i!=bridovi.end(); i++)
    {
        if (i->first.first == s)
        {
            novi = (skup.insert(i->first.second).second);
            if (novi == 1)
            {
                podskup = dohvatljiviIz(i->first.second);
                skup.insert(podskup.begin(), podskup.end());
            }
        }
    }
    return skup;
}

