#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <list>
#include <set>
#include <vector>
using namespace std;

struct vlakovi
{
    map < pair <string, string>, int > cjenik;
    void dodaj(string a, string b, int cilj);
    void ukloni (string a, string b);
    list<string> susjednaMjesta(string a);
    pair <string, string> najskupljaLinija();
    set<string> mjesta();
    vector<pair<string, string> > linijeJeftinijeOd(int ogr);
    bool mozeJeftinije(string a, string b);
    int rekurzija (string a , string b, int potroseno, set <string> posjeceno, int cijena);
};
