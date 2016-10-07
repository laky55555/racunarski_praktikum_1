#include <iostream>
#include <cstring>
using namespace std;

struct Hotel
{
    string i;
    string g;
    int c;
    int m;
    Hotel();
    Hotel(string ime, string grad, int cijena, int brojSlobodnihMjesta);
    string Ime();
    string Grad();
    int Cijena();
    int BrojSlobodnihMjesta();
};

struct SkupHotela
{
    int vrh;
    Hotel polje[100];
    SkupHotela();
    SkupHotela(Hotel h);
    void Dodaj (Hotel h);
    int Izbaci (Hotel h);
    int BrojHotela();
    Hotel ItiHotel (int i);
    SkupHotela NadjiHoteleUGradu (string grad);
    SkupHotela NadjiHotele (string grad, int maxCijena, int MinSlobodnihMj);
    int NajmanjaCijenaUGradu (string grad);
    void SortirajPoCijeni();
};
