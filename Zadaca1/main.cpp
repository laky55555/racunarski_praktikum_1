#include <iostream>
#include <string>
#include "imenik.h"

using namespace std;

void ispisOsobe (Osoba o)
{
    cout << o.Ime() << " " << o.Prezime() << " " << o.Grad() << " " << o.GodinaRodjenja();
}

void ispisImenika(Imenik im) 
{ 
    for(int i=0; i<im.BrojOsoba(); i++) 
    { 
        ispisOsobe(im.ItaOsoba(i)); 
        cout << endl; 
    } 
}

int main(void) 
{ 
    Imenik testImenik(Osoba("Mate", "Matic", "Rijeka", 1984)); 
    testImenik.Dodaj(Osoba("Ivica", "Ivic", "Zagreb", 1990)); 
    testImenik.Dodaj(Osoba("Josip", "Josipovic", "Split", 1980)); 
    testImenik.Dodaj(Osoba("Ante", "Matic", "Osijek", 1991)); 
    testImenik.Dodaj(Osoba("Igor", "Matijasevic", "Rijeka", 1950)); 
    testImenik.Dodaj(Osoba("Karlo", "Matijasevic", "Split", 1970)); 
    testImenik.Dodaj(Osoba("Ivica", "Ivic", "Rijeka", 1966)); 
    testImenik.Dodaj(Osoba("Josip", "Josipovic", "Split", 1980)); 
    ispisImenika(testImenik);  
    cout << testImenik.NadjiNajmanjuGodinuRodjenja() << endl; 
    testImenik.SortirajPoPrezimenu(); 
    ispisImenika(testImenik);
    cout << testImenik.Izbrisi(Osoba("Josip", "Josipovic", "Split", 1980)) << endl;
    ispisImenika(testImenik); 
    ispisImenika(testImenik.NadjiGrad("Rijeka").NadjiPrezime("Ivic")); 
    return 0; 
    
}
