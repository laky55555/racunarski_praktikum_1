#include <string>
using namespace std;

struct Osoba
{
    int godRodjenja;
    string ime, prezime, grad;
    Osoba();
    Osoba(string ime, string prezime, string grad, int godRodjenja);
    
    string Ime();
    string Prezime();
    string Grad();
    int GodinaRodjenja();
};

void BubbleSort1 (Osoba a[], int n);    

struct Imenik
{
    Osoba o[100];
    int vrh;
    Imenik();
    Imenik(Osoba o);
    void Dodaj(Osoba o);
    int Izbrisi(Osoba o);
    int BrojOsoba();
    Osoba ItaOsoba(int i);
    Imenik NadjiPrezime(string prezime);
    Imenik NadjiGrad(string grad);
    Imenik NadjiGodinuRodjenja(int god);
    int NadjiNajmanjuGodinuRodjenja(void);
    void SortirajPoPrezimenu(void);
};
