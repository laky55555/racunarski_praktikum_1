#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <set>

using namespace std;



int main (void)
{
    string a, pred;
    int studenti;
    map<string, pair<set<string>, int> > predmeti;
    map<string, pair<set<string>, int> >::iterator i;
    set<string>::iterator j;
    cin >> a;
    while (a != "kraj")
    {
        set<string> pomocni;
        pred = a;
        cin >> a;
        while (a != "x")
        {
            pomocni.insert(a);
            cin >> a;
        }
        cin >> studenti;
        pair<set<string>, int> pomocni2;
        pomocni2.first = pomocni; pomocni2.second = studenti;
        predmeti[pred] = pomocni2;
        cin >> a;    
    }
    cin >> a;
    int suma=0, imaih=0;
    for (i=predmeti.begin(); i!=predmeti.end(); i++)
    {
        for(j=(i->second.first).begin(); j!=(i->second.first).end(); j++)
            if ((*j) == a)
            {
                cout << i->first<<endl;
                suma += i->second.second;
                imaih++;
            }
    }
    cout << suma/imaih;
    
    
    return 0;
}
