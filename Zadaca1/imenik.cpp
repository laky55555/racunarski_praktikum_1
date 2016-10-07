#include <iostream>
#include "imenik.h"

using namespace std;

Osoba::Osoba()
{

}
    
Osoba::Osoba(string ime1, string prezime1, string grad1, int godRodjenja1)
{
    ime = ime1;
    prezime = prezime1;
    grad = grad1;
    godRodjenja = godRodjenja1;
}
       
string Osoba::Ime(void)
{
    return ime;
}
        
string Osoba::Prezime(void)
{
    return prezime;
}
        
string Osoba::Grad(void)
{
    return grad;
}
        
int Osoba::GodinaRodjenja(void)
{
    return godRodjenja;
}

void BubbleSort1 (Osoba a[], int n) 
{
    int i, j, chg;
    Osoba temp;
    for (i = 0, chg = 1; chg; i++) 
    {
        chg = 0;
        for (j = 0; j < n-1-i; j++)
        {  
            if (a[j+1].prezime < a[j].prezime) 
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                chg = 1;
            }
        }
    }
}
    
Imenik::Imenik()
{
    vrh = -1;
}
Imenik::Imenik(Osoba a)
{
    vrh = 0;
    o[0].ime = a.ime;
    o[0].prezime = a.prezime;
    o[0].grad = a.grad;
    o[0].godRodjenja = a.godRodjenja;
}
    
void Imenik::Dodaj(Osoba a)
{
    vrh++;
    o[vrh].ime = a.ime;
    o[vrh].prezime = a.prezime;
    o[vrh].grad = a.grad;
    o[vrh].godRodjenja = a.godRodjenja;
}
int Imenik::Izbrisi(Osoba a)
{
    int i, brojac=0, j;
    for (i=0; i<=vrh; i++)
    {
        if (o[i].godRodjenja == a.godRodjenja && o[i].ime == a.ime && o[i].prezime == a.prezime && o[i].grad == a.grad)
        {
            brojac++;
            for (j=i+1; j<=vrh; j++)
                o[j-1] = o[j];
            vrh--;
            i--;
        }
    }
    return brojac;
}
int Imenik::BrojOsoba(void)
{
    return (vrh+1);
}

Osoba Imenik::ItaOsoba(int i)
{
    return o[i];
}

Imenik Imenik::NadjiPrezime(string prezime)
{
    Imenik A;
    int i;
    for (i=0; i<BrojOsoba(); i++)
    {
        if (prezime == o[i].prezime)
            A.Dodaj(o[i]);
    }
    return A;
}
Imenik Imenik::NadjiGrad(string grad)
{
    Imenik A;
    int i;
    for (i=0; i<BrojOsoba(); i++)
    {
        if (grad == o[i].grad)
            A.Dodaj(o[i]);
    }
    return A;
}
Imenik Imenik::NadjiGodinuRodjenja(int god)
{
    Imenik A;
    int i;
    for (i=0; i<BrojOsoba(); i++)
    {
        if (god == o[i].godRodjenja)
            A.Dodaj(o[i]);
    }   
    return A;
}
int Imenik::NadjiNajmanjuGodinuRodjenja(void)
{
    int min, i;
    if (BrojOsoba() == 0)
        return -1;
    for (i=0; i<BrojOsoba(); i++)
    {
        if (i==0)
            min = o[i].godRodjenja;
        if (min > o[i].godRodjenja)
            min = o[i].godRodjenja;
    }
    return min;
}

void Imenik::SortirajPoPrezimenu(void)
{
    BubbleSort1(o, BrojOsoba());
}
