#include "vlakovi.h"
#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <set>

using namespace std;

void vlakovi::dodaj (string a, string b, int c)
{
    pair <string, string> par1(a,b);
    pair <string, string> par2(b,a);
    cjenik[par1]=c;
    cjenik[par2]=c;
}

void vlakovi::ukloni (string a, string b)
{
    pair <string, string> par1(a,b), par2(b,a);
    cjenik.erase(par1);
    cjenik.erase(par2);
}

list<string>vlakovi::susjednaMjesta(string a)
{
    list<string> lista;
    map <pair <string, string>, int >::iterator it;
    for (it=cjenik.begin();it!=cjenik.end();it++)
    {
        if(it->first.first==a)lista.push_back(it->first.second);
    }
    return lista;
}

pair <string, string> vlakovi::najskupljaLinija()
{
    map <pair <string, string>, int>::iterator it;
    int maxi=0;
    pair <string, string> maxipar;
    for (it=cjenik.begin();it!=cjenik.end();it++)
    {
        if(it==cjenik.begin())
        {
            maxi=it->second;
            maxipar=it->first;
        }
        if(maxi<=it->second)
        {
            maxi=it->second;
            maxipar=it->first;
        }
    }
    return maxipar;
}

set <string> vlakovi::mjesta ()
{
    map < pair <string, string>,int>::iterator it;
    set <string> skup;
    for (it=cjenik.begin();it!=cjenik.end();it++)
    {
        skup.insert(it->first.first);
        skup.insert(it->first.second);
    }
    return skup;
}
vector <pair <string, string> > vlakovi::linijeJeftinijeOd(int ogr)
{
    vector<pair <string, string> > linije;
    map <pair <string, string>, int >::iterator it;
    for (it=cjenik.begin();it!=cjenik.end();it++)
    {
        if(it->second<ogr)linije.push_back((it->first));
    }
    return linije;
}
int vlakovi::rekurzija (string a, string b, int potroseno, set<string> posjeceno, int cijena)
{
    if((a==b&&cijena==-1)||(a==b&&cijena>potroseno))
    {
        cout << "dosli smo do " << b << " a potroseno je " << potroseno <<endl;
        return 1;
    }
    set <string> kopija;
    kopija=posjeceno;
    list<string> kudcemo;
    kudcemo=susjednaMjesta(a);
    //iz kudcemo izbacimo sve one koji su vec posjeceni da se ne vrtimo u krug
    set <string> ::iterator is;
    list<string> ::iterator it, tmp;
    cout << "ispis posjecenog: " ;
    for(is=posjeceno.begin();is!=posjeceno.end();is++)
    {
        cout << *is << " " ;
    }
    cout <<endl<< "ispis kudcemo: " ;
    for (it=kudcemo.begin();it!=kudcemo.end();it++)
    {
        cout << *it << " ";
    }
    cout <<endl;
    for (is=posjeceno.begin();is!=posjeceno.end();is++)
    {
        for (it=kudcemo.begin();it!=kudcemo.end();)
        {
            if((*it)==(*is))
            {
                cout << "brisanje: " << *is << " " << *it <<endl;
                tmp=it;
                it++;
                kudcemo.erase(tmp);
            }
            else it++;
        }
    }
    cout << "ispis posjecenog nakon brisanja: " ;
    for(is=posjeceno.begin();is!=posjeceno.end();is++)
    {
        cout << *is << " " ;
    }
    cout <<endl<< "ispis kudcemo nakon brisanja: " ;
    for (it=kudcemo.begin();it!=kudcemo.end();it++)
    {
        cout << *it << " ";
    }
    cout <<endl;
    int suma=0;

    for (it=kudcemo.begin();it!=kudcemo.end();it++)
    {
        pair <string, string> par(a,*it);
        kopija.insert(*it);
        suma+=rekurzija(*it, b, potroseno+cjenik[par], kopija, cijena);
    }
    return suma;

}
bool vlakovi::mozeJeftinije (string a, string b)
{

   set <string> posjeceno;
   posjeceno.insert(a);
    int potroseno=0;
    int cijena=-1;
    pair <string, string> par(a,b);
    map <pair <string, string>, int >::iterator it;
    for (it=cjenik.begin();it!=cjenik.end();it++)
    {
        if(it->first.first==a&&it->first.second==b)
        {
            cijena=cjenik[par];
        }
    }
    int jel=rekurzija(a, b, potroseno, posjeceno, cijena);
    cout <<" jel je :"<<jel<<endl;
    if(jel>=1)return 1;
    return 0;



}
