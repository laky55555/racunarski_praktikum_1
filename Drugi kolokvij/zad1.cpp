#include <iostream>
#include <list>

using namespace std;

class Igrac
{
    private:
    string name, zadnji_napadac;
    int poeni;
    static list<Igrac*> v;

    protected:
    int obrana;
    bool pomocni_attack(Igrac &ig, int p)
    {
        if(ig.obrana) { ig.obrana--; return false; }
        else { ig.zadnji_napadac = name; ig.poeni-=p; return true; }
    }

    public:
    Igrac(string name, int poeni)
    {
        this->name = name; this->poeni = poeni;
        obrana = 0;
        v.push_back(this);
    }
    string ime() { return name; }

    int trenutnoStanje() { return poeni; }

    bool attack(Igrac &ig) { return pomocni_attack(ig, 10); }

    virtual bool specialAttack(Igrac &ig) = 0;

    virtual void defend() = 0;

    ~Igrac()
    {
        cout << name << " " << zadnji_napadac << endl;
        list<Igrac *>::iterator it;
        for(it = v.begin(); it != v.end(); ++it)
            if(*it == this) { v.erase(it); break; }
    }

    static void sviIgraci()
    {
        list<Igrac *>::iterator it;
        for(it = v.begin(); it != v.end(); ++it)
            cout << (*it)->name << " " << (*it)->poeni << endl;
    }
};

list<Igrac *> Igrac::v;

class Paladin : public Igrac
{
    public:
    Paladin(string ime, int poeni) : Igrac(ime, poeni) {}

    bool specialAttack(Igrac &ig) { return pomocni_attack(ig, 30); }

    void defend() { obrana = 1; }
};

class Dwarf : public Igrac
{
    public:
    Dwarf(string ime, int poeni) : Igrac(ime, poeni) {}

    bool specialAttack(Igrac &ig) { return pomocni_attack(ig, 20); }

    void defend() { obrana = 2; }
};

bool ziviSu(Igrac *polje[], int n)
{
    for(int i = 0; i < n; i++)
        if(polje[i]->trenutnoStanje() <=0 ) return false;

    return true;
}

void unisti(Igrac *polje[], int n)
{
    for(int i = 0; i < n; i++)
        delete polje[i];
}

int main()
{
    Igrac *polje[3];
    polje[0] = new Paladin("Ante", 30);
    polje[1] = new Dwarf("Frane", 40);
    polje[2] = new Paladin("Duje", 30);

    Igrac::sviIgraci();

    if(polje[0]->attack(*polje[2])) cout << "Napad uspio" << endl;
    cout << endl; Igrac::sviIgraci();
    if(!ziviSu(polje, 3)) { unisti(polje, 3); return 0; }

    polje[1]->defend();
    if(!polje[0]->attack(*polje[1])) cout << "Napad nije uspio" << endl;
    if(!polje[0]->attack(*polje[1])) cout << "Napada nije uspio" << endl;
    cout << endl; Igrac::sviIgraci();
    if(!ziviSu(polje, 3)) { unisti(polje, 3); return 0; }

    polje[1]->specialAttack(*polje[2]);
    cout << endl; Igrac::sviIgraci();
    if(!ziviSu(polje, 3)) { unisti(polje, 3); return 0; }
    return 0;
}
