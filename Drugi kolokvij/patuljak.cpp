#include <iostream>
#include <string>
#include <list>


using namespace std;

class Igrac
{
    int zdravlje;
    string naziv;
    
public:
    static list<Igrac*> lista;
    int obrana;
    string borba;
    Igrac(string Ime, int zivot)
    {
        zdravlje = zivot;
        naziv = Ime;
        obrana = 0;
        lista.push_back(this);
    }
    void skidanjebodova(int a)
    {
        this->zdravlje -= a;
    }
    int trenutnoStanje()
    {
        return zdravlje;
    }
    string ime() 
    {
        return naziv;
    }
    bool attack(Igrac& a)
    {
        if (a.obrana)
        {
            a.obrana--;
            return false;
        }
        else
        {
            a.skidanjebodova(10);
            a.borba = this->ime();
            return true;
        }   
    }
    virtual bool specialAttack(Igrac& a)
    {
        return 0;
    }
    virtual void defend ()
    {
        
    }
    void sviIgraci()
    {
        list<Igrac*>::iterator i;
        for(i=lista.begin(); i!=lista.end(); i++)
        {
            cout << (*i)->naziv << " " << (*i)->zdravlje <<endl;
        }
    }
    ~Igrac()
    {
        list<Igrac*>::iterator i;
        for(i=lista.begin(); i!=lista.end(); i++)
        {
            if ((*i)==this)
            {
                if((*i)->zdravlje<=0)
                    cout << (*i)->naziv << " " << (*i)->zdravlje << "ubio ga " << (*i)->borba <<endl;
                else
                    cout << (*i)->naziv << " " << (*i)->zdravlje <<endl;
                lista.erase(i);
                break;
            }
        }
    }
    
};

list<Igrac*> Igrac::lista;

class Paladin : public Igrac
{
    
public: 
    Paladin(string Ime, int zivot) : Igrac(Ime, zivot)
    {
        
    }
    bool specialAttack(Igrac& a)
    {
        if (a.obrana)
        {
            a.obrana--;
            return false;
        }
        else
        {
            a.skidanjebodova(30);
            a.borba = this->ime();
            return true;
        }   
    }
    void defend ()
    {
        obrana++;
    }
};

class Dwarf : public Igrac
{
    
public: 
    Dwarf(string Ime, int zivot) : Igrac(Ime, zivot)
    {
        
    }
    bool specialAttack(Igrac& a)
    {
        if (a.obrana)
        {
            a.obrana--;
            return false;
        }
        else
        {
            a.borba = this->ime();
            a.skidanjebodova(30);
            return true;
        }   
    }
    void defend()
    {
        obrana += 2;
    }
};

int main(void)
{
    Igrac* polje[3];
    polje[0] = new Paladin("jorjo", 30);
    polje[1] = new Dwarf("vrisak", 40);
    polje[2] = new Paladin("drodo", 50);
    
    polje[0]->attack(*polje[1]);
    polje[1]->defend();
    polje[0]->specialAttack(*polje[1]);
    polje[0]->specialAttack(*polje[1]);
    polje[0]->specialAttack(*polje[1]);
    polje[0]->specialAttack(*polje[1]);
    
    
    
    delete polje[1];
    
    return 0;
}
