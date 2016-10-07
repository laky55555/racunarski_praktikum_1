#include "vlakovi.h"
#include <string>
#include <map>
#include <string>
#include <iostream>
#include <utility>
#include <list>
#include <vector>

void vlakovi::dodaj (string a, string b, int cij)
{
    pair<string, string> pomocni_pair;  
    pomocni_pair.first = a;
    pomocni_pair.second = b;
    cjenik[pomocni_pair] = cij;
    pomocni_pair.first = b;
    pomocni_pair.second = a;
    cjenik[pomocni_pair] = cij;
}

void vlakovi::ukloni (string a, string b)
{
    pair<string,string> x(a,b), y(b,a);
    cjenik.erase(x);
    cjenik.erase(y);
    
}

list<string> vlakovi::susjednaMjesta(string s)
{
    int imaih;
    list<string> pomocna_lista;
    list<string>::iterator k;
    map<pair<string, string>, int>::iterator i,j;
    for (i=cjenik.begin(); i!=cjenik.end(); i++)
    {
        imaih=0;
        if(i->first.first == s)
        {
            for (k=pomocna_lista.begin(); k!=pomocna_lista.end(); k++)
                if ((*k) == i->first.second)
                    imaih = 1;
            if (imaih == 0)
                pomocna_lista.push_back(i->first.second);
        }
        else if(i->first.second == s)
        {
            for (k=pomocna_lista.begin(); k!=pomocna_lista.end(); k++)
                if ((*k) == i->first.first)
                    imaih = 1;
            if (imaih == 0)
                pomocna_lista.push_back(i->first.first);
        }
    }
    return pomocna_lista;
}

pair<string, string> vlakovi::najskupljaLinija()
{
    pair<string, string> pomocni_pair;
    int max, pocetak=0;
    map<pair<string, string>, int>::iterator i;
    for(i=cjenik.begin(); i!=cjenik.end(); i++)
        if(pocetak==0 || i->second >= max)
        {
            pocetak =1;
            max = i->second;
            pomocni_pair.first = i->first.first;
            pomocni_pair.second = i->first.second;
        }
    return pomocni_pair;
}

set<string> vlakovi::mjesta()
{
    set<string> pomocni_set;
    map<pair<string, string>, int>::iterator i;
    for(i=cjenik.begin(); i!=cjenik.end(); i++)
    {
        pomocni_set.insert(i->first.first);
        pomocni_set.insert(i->first.second);
    }
    return pomocni_set;
}

vector<pair<string, string> > vlakovi::linijeJeftinijeOd(int ogr)
{
    map<pair<string, string>, int>::iterator i;
    vector<pair<string, string> > pomocni_vektor;
    for(i=cjenik.begin(); i!=cjenik.end(); i++)
        if(i->second < ogr)
            pomocni_vektor.push_back(i->first);
    return pomocni_vektor;
}

int vlakovi::postojiDirektanPut(string a, string b)
{
    int put, pronadeni=0;
    map<pair<string, string>, int>::iterator i;
    for(i=cjenik.begin(); i!=cjenik.end(); i++)
        if(i->first.first == a && i->first.second == b)
        {
            pronadeni = 1;
            put = i->second;
            break;
        }
    if(pronadeni == 1)
        return put;
    return -1;
}

vector<int> vlakovi::rekurzija(list<string> prosli, string a, string b)
{
    int x =0;
    vector<int> vrijednosti, pomoc;
    if(a == b)
        return vrijednosti;
    if (postojiDirektanPut(a, b)!=-1)
        vrijednosti.push_back(postojiDirektanPut(a, b));
    int vec_je;
    list<string> susjedi;
    list<string>::iterator i, j;
    susjedi = susjednaMjesta(a);
    for(i=susjedi.begin(); i!=susjedi.end(); i++)
    {
        vec_je = 0;
        for(j=prosli.begin(); j!=prosli.end(); j++)
            if(*j == *i)
                vec_je = 1;
        if (vec_je == 0)
        {
            prosli.push_back(*i);
            x = postojiDirektanPut(a, *i);
            pomoc = rekurzija(prosli, *i, b);
            for (unsigned int j=0; j<pomoc.size(); j++)
                vrijednosti.push_back(pomoc[j]+x);
        }
    }
    return vrijednosti;
}

bool vlakovi::mozeJeftinije(string a, string b)
{
    unsigned int i;
    vector<int> niz;
    list<string> lista;
    niz = rekurzija(lista, a, b);

    for(int i=0;i<niz.size();i++) 
        cout << niz[i] << " ";
    cout <<endl;

    if (postojiDirektanPut(a,b) != -1)
    {
        for(i=0; i<niz.size(); i++)
            if (niz[i]<postojiDirektanPut(a,b) && niz[i]!=-1)
                return 1;
        return 0;
    }
    for(int i=0;i<niz.size();i++) 
        if(niz[i] != -1)
            return 1;
    return 0;    
}










