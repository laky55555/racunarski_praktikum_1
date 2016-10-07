#include "comp.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


Computer::~Computer()
{
    int i;
    cout << "Destruktor od compa" <<endl;
    for (i=0; i<niz.size(); i++)
        if (niz[i] == this)
        {
            cout << "Pronasao comp" <<endl;
            Computer *temp = niz[i];
            niz[i] = niz[niz.size()-1];
            niz[niz.size()-1] = temp;
            niz.pop_back();
            break;
        }
}

/*Notebook::~Notebook()
{
    int i;
    cout << "Destruktor od notebooka" <<endl;
    for (i=0; i<niz.size(); i++)
        if (niz[i] == this)
        {
            cout << "Pronasao notebook" <<endl;
            Computer *temp = niz[i];
            niz[i] = niz[niz.size()-1];
            niz[niz.size()-1] = temp;
            niz.pop_back();
            break;
        }
}

Tablet::~Tablet()
{
    int i;
    cout << "Destruktor od tableta" <<endl;
    for (i=0; i<niz.size(); i++)
        if (niz[i] == this)
        {
            cout << "Pronasao tablet" <<endl;
            Computer *temp = niz[i];
            niz[i] = niz[niz.size()-1];
            niz[niz.size()-1] = temp;
            niz.pop_back();
            break;
        }
}*/

Computer::Computer(int mhz, string vendor, int memory)
{
    brzina_procesora = mhz;
    proizvodac_procesora = vendor;
    kolicina_memorije = memory;
    niz.push_back(this);
}

vector<Computer *> Computer::niz;

int Computer::get_mhz()
{
    return brzina_procesora;
}

int Computer::get_memory()
{
    return kolicina_memorije;
}

string Computer::get_vendor()
{
    return proizvodac_procesora;
}

int Computer::upgrade(int mhz, int memory)
{
    int povratak;
    povratak = (mhz - brzina_procesora)*2 + (memory - kolicina_memorije);
    brzina_procesora = mhz;
    kolicina_memorije = memory;
    return povratak;
}

Computer& Computer::next_fastest()
{
    unsigned i,j;
    int min1, min2, pocetak=0;
    for (i=0; i<niz.size(); i++)
    {
        if(  (*niz[i]).brzina_procesora > brzina_procesora || ( (*niz[i]).brzina_procesora == brzina_procesora && (*niz[i]).kolicina_memorije > kolicina_memorije)  )
        {
            if(pocetak == 0 || ( (*niz[i]).brzina_procesora < min1 || ( (*niz[i]).brzina_procesora == min1 && (*niz[i]).kolicina_memorije < min2) ) )
            {
                pocetak = 1;
                min1 = (*niz[i]).brzina_procesora;
                min2 = (*niz[i]).kolicina_memorije;
                j = i;
            }
        }        
    }
    Computer &x = *niz[j];
    return x;
    
}

Computer& Computer::fastest_computer()
{
    int max1, max2, pocetak=0;
    unsigned i,j;
    for (i=0; i<niz.size(); i++)
        if(pocetak == 0 || ( (*niz[i]).brzina_procesora > max1 || ( (*niz[i]).brzina_procesora == max1 && (*niz[i]).kolicina_memorije > max2) ) )
        {
            pocetak = 1;
            max1 = (*niz[i]).brzina_procesora;
            max2 = (*niz[i]).kolicina_memorije;
            j = i;
        }
    static Computer &x = *niz[j];
    return x;

}

Computer& Computer::faster(Computer &comp1, Computer &comp2)
{
    static Computer& brzi = comp1;
    if (comp1.get_mhz() > comp2.get_mhz())
    {
        brzi = comp1;
        return brzi;
    }
    else if (comp1.get_mhz() < comp2.get_mhz())
    {
        brzi = comp2;
        return brzi;
    }
    else
    {
        if (comp1.get_memory() > comp2.get_memory())
        {
            brzi = comp1;
            return brzi;
        }
        else
        {
            brzi = comp2;
            return brzi;
        }
    }
}

Notebook::Notebook(int mhz, string vendor, int memory, float screen_size) : Computer(mhz, vendor, memory)
{
    velicina_ekrana = screen_size;
}

float Notebook::get_screen_size()
{
    return velicina_ekrana;
}

int Notebook::upgrade(int mhz, int memory)
{
    int povratak;
    povratak = (mhz - brzina_procesora)*3 + (memory - kolicina_memorije)*2;
    brzina_procesora = mhz;
    kolicina_memorije = memory;
    return povratak;    
}

Tablet::Tablet(int mhz, string vendor, int memory, float screen_size, string os) : Notebook(mhz, vendor, memory, screen_size)
{
    operacijski_sustav = os;
}

string Tablet::get_os()
{
    return operacijski_sustav;
}

int Tablet::upgrade(int mhz, int memory)
{
    int povratak;
    povratak = (mhz - brzina_procesora)*3 + (memory - kolicina_memorije)*3;
    brzina_procesora = mhz;
    kolicina_memorije = memory;
    return povratak;    
}


