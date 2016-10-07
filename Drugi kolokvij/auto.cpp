#include <iostream>
#include <string>
#include <list>

using namespace std;

class Auto
{
    int polozaj_automobila, vrijeme_voznje;
    string vozac;
public:
    static list<Auto*> lista;
    bool vozno_stanje;
    static string staza;
    Auto (){};
    Auto (string ime)
    {
        vozac = ime;
        polozaj_automobila = 0;
        vrijeme_voznje = 0;
        vozno_stanje = true;
        lista.push_back(this);
    }
    int& polozaj ()
    {
        return polozaj_automobila;
    }
    int& vrijeme()
    {
        return vrijeme_voznje;
    }
    string ime ()
    {
        return vozac;
    }

    static void kreirajStazu (string stazica)
    { 
        staza = stazica;
    }
    
    void odvozi()
    {
        /*if (vozno_stanje == false)
            break;*/
        polozaj_automobila += 10;
        vrijeme_voznje += 120;
    }
    
    virtual void nitro()
    {
        
    }
    void sudar (Auto &a)
    {
        if (a.polozaj() == this->polozaj() )
        {
            vozno_stanje = false;
            a.vozno_stanje = false;
        }
    }
    void sviAutomobili()
    {
        list<Auto*>::iterator i;
        int j=1;
        for(i=lista.begin(); i!=lista.end(); i++, j++)
            cout <<j<<"automobil se zove "<<vozac<<" i nalazi se na "<<polozaj_automobila << "km i vozio je " << vrijeme_voznje << "s."<<endl;
        
    }

};

list<Auto*> Auto::lista;
string Auto::staza;

class Ferrari : public Auto
{
public:
    Ferrari(){};
    Ferrari(string ime) : Auto(ime)
    {
        
    }
    
    void nitro()
    {            
        int a = polozaj(), b = vrijeme(), mjesto=(a/10);
        if( staza[mjesto] == 'f' )
        {  
            a += 10;
            b +=60;
        }
        else
        {
            a +=10;
            b +=90;
        }
    }
};

int main (void)
{
    Auto::kreirajStazu("ffflllffll");
    Ferrari A("A1"), B("B2");
    Ferrari *a = new Ferrari;
    *a = A;
    Ferrari *b = new Ferrari;
    *b=B;
    A.sviAutomobili();
}
