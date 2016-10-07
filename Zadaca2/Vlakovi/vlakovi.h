#include <string>
#include <map>
#include <string>
#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <set>

using namespace std;

struct vlakovi
{
    map<pair<string, string>, int> cjenik;
    void dodaj(string a, string b, int c);
    void ukloni(string a, string b);
    list<string> susjednaMjesta (string s);
    pair<string,string> najskupljaLinija();
    set<string> mjesta ();
    vector<pair<string, string> > linijeJeftinijeOd(int c);
    bool mozeJeftinije (string a, string b);
    int postojiDirektanPut (string a, string b);
    vector<int> rekurzija(list<string> prosli, string a, string b);

};
