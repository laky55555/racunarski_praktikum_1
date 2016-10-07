#include <iostream>
#include "hoteli.h"
using namespace std;

Hotel::Hotel()
{

}
Hotel::Hotel(string ime, string grad, int cijena, int brojSlobodnihMjesta)
{
    i=ime;
    g=grad;
    c=cijena;
    m=brojSlobodnihMjesta;
}

string Hotel::Ime ()
{
    return i;
}

string Hotel::Grad ()
{
    return g;
}

int Hotel::Cijena()
{
    return c;
}

int Hotel::BrojSlobodnihMjesta()
{
    return m;
}


SkupHotela::SkupHotela()
{
    vrh=-1;
}

SkupHotela::SkupHotela(Hotel h)
{
    vrh=0;
    polje[0].i=h.i;
    polje[0].g=h.g;
    polje[0].c=h.c;
    polje[0].m=h.m;
}

void SkupHotela::Dodaj (Hotel h)
{
    if(vrh>=99) return;     //nema slobodnog mjesta u polju
    vrh++;
    polje[vrh].i=h.i;
    polje[vrh].g=h.g;
    polje[vrh].c=h.c;
    polje[vrh].m=h.m;
}

int SkupHotela::Izbaci(Hotel h)
{
    int i, brojac=0, j;
    for (i=0;i<=vrh;i++)
    {
        if (polje[i].i==h.i&&polje[i].c==h.c&&polje[i].g==h.g&&polje[i].m==h.m)
        {
            for(j=i;j<vrh;j++)
            {
                polje[j].i=polje[j+1].i;
                polje[j].g=polje[j+1].g;
                polje[j].c=polje[j+1].c;
                polje[j].m=polje[j+1].m;
            }
            vrh--;
            brojac++;
        }
    }
    return brojac;
}

int SkupHotela::BrojHotela ()
{
    return (vrh+1);
}

Hotel SkupHotela::ItiHotel(int i)
{
    return polje[i];
}

SkupHotela SkupHotela::NadjiHoteleUGradu(string grad)
{
    SkupHotela temp;
    int i;
    for (i=0;i<=vrh;i++)
    {
        if(polje[i].g==grad) temp.Dodaj(polje[i]);
    }
    return temp;
}

SkupHotela SkupHotela::NadjiHotele(string grad, int maxCijena, int minSlobodnihMj)
{
    SkupHotela temp;
    int i;
    for (i=0;i<=vrh;i++)
    {
        if(polje[i].g==grad&&polje[i].c<=maxCijena&&polje[i].m>=minSlobodnihMj)
            temp.Dodaj(polje[i]);
    }
    return temp;
}

int SkupHotela::NajmanjaCijenaUGradu(string grad)
{
    SkupHotela novi;
    int i, mini;
    novi=NadjiHoteleUGradu(grad);
    if(novi.vrh==-1)return -1;
    else
    {
        for (i=0;i<=novi.vrh;i++)
        {
            if(i==0) mini=novi.polje[i].c;
            if(i>0&&mini>novi.polje[i].c) mini=novi.polje[i].c;
        }
    }
    return mini;

}

void SkupHotela::SortirajPoCijeni()
{
    int k, j, mini, minicijena;
    Hotel temp;
    for (k=0;k<vrh;k++)
    {
        mini=k;
        minicijena=polje[k].c;
        for(j=k+1;j<=vrh;j++)
        {
            if(polje[j].c<minicijena)
            {
                mini=j;
                minicijena=polje[j].c;
            }
        }
        if(mini!=k)
        {
            temp.i=polje[k].i;
             temp.g=polje[k].g;
              temp.c=polje[k].c;
               temp.m=polje[k].m;
            polje[k].i=polje[mini].i;
            polje[k].g=polje[mini].g;
            polje[k].c=polje[mini].c;
            polje[k].m=polje[mini].m;
            polje[mini].i=temp.i;
            polje[mini].g=temp.g;
            polje[mini].c=temp.c;
            polje[mini].m=temp.m;
        }
    }
}










