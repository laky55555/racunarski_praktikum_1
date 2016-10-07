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
    int ponavljanje=0, imaih=0;
    if (p != d)
    {
        map<pair<string, string>, int>::iterator i;
        for (i=bridovi.begin(); i!=bridovi.end(); i++)
            if (i->first.first == p && i->first.second == d)
                ponavljanje=1;
        if (ponavljanje == 0)
        {
            pair<string,string> novi;
            novi.first = p;     novi.second = d;
            bridovi[novi] = n;
            i=bridovi.end();
            i--;
            map<int, pair<pair<string, string>, int> >::iterator k;
            for (k=redosljed.begin(); k!=redosljed.end(); k++)
                imaih++;
            pair<pair<string, string>, int> abc;
            abc.first=novi;
            abc.second=n;
            redosljed[imaih] = abc;             
        }
    }
}
