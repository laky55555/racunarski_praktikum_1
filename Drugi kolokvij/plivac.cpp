#include <iostream>
#include <sstream>
#include <list>
using namespace std;

class Plivac
{
    public:
    int Polozaj,Vrijeme, broj_utrke;
    string Ime;
    static list <Plivac*> lista;
    Plivac(){}
    Plivac (int polozaj, int vrijeme, string ime, int broj_utrke)
    {
        this->Polozaj=polozaj;
        this->Vrijeme=vrijeme;
        this->Ime=ime;
        this->broj_utrke=broj_utrke;
    }
    int polozaj()
    {
        return Polozaj;
    }
    int vrijeme()
    {
        return Vrijeme;
    }
    string ime()
    {
        return Ime;
    }
    virtual void dodaj_kilometre()=0;
    void dodaj_sate()
    {
        this->Vrijeme+=30;
    }
    void ispis ()
    {
        cout << Ime << " " << Vrijeme << " " << Polozaj <<endl;
    }
    friend void SimulirajUtrku(double sati, int broj_utrke);

};


class Sipa:public Plivac
{
    public:
    Sipa(){}
    int brzina;
    Sipa(int polozaj, int vrijeme, string ime, int broj_utrke) : Plivac( polozaj,vrijeme,ime, broj_utrke)
    {
        brzina=20;
    }
    void dodaj_kilometre()
    {
        this->Polozaj+=10;
    }
};

class Tuna:public Plivac
{
    public:
    Tuna(){}
    int brzina;
    Tuna(int polozaj, int vrijeme, string ime, int broj_utrke) : Plivac(polozaj,  vrijeme, ime, broj_utrke)
    {
        brzina=30;
    }
    void dodaj_kilometre()
    {
        this->Polozaj+=15;
    }
};
void ispisliste()
{
    list< Plivac*> ::iterator it;
    cout << "---------------------------------"<<endl;
    for(it=Plivac::lista.begin();it!=Plivac::lista.end();it++)
    {
        (**it).ispis();
    }
     cout << "---------------------------------"<<endl;
}
void ubaci_u_listu(Sipa *S, Tuna *T)
{
    Plivac::lista.push_back(S);
    Plivac::lista.push_back(T);
}
 list <Plivac*> Plivac::lista;
void SimulirajUtrku(double sati, int broj_utrke)
{
    int minute=sati*60;
    int i=49;
    int broj=broj_utrke+48;
    char b=broj;
    string b1;
    stringstream ss;
    ss<<b;
    ss>>b1;
    while(minute>=30)
    {
        //imena
        char c=i;
        string s;
         stringstream ss;
        ss<<c;
        ss>>s;
        string ime1("sipa"), ime2("tuna");
        ime1.append(s);
        ime2.append(s);
        ime1.append("-");
        ime2.append("-");
        ime1.append(b1);
        ime2.append(b1);

        Sipa prva(0,0,ime1,broj_utrke);
        Tuna druga(0,0,ime2,broj_utrke);
        Sipa *A=new Sipa;
        Tuna *B=new Tuna;
        *A=prva;
        *B=druga;

        //starima dodamo kilometre i sate
        list< Plivac*> ::iterator it;
        for(it=Plivac::lista.begin();it!=Plivac::lista.end();it++)
        {
            if(((*it)->broj_utrke==broj_utrke))
            {
                (*it)->dodaj_kilometre();
                (**it).dodaj_sate();
            }
        }
        ispisliste();
        ubaci_u_listu(A,B);
        ispisliste();
        minute=minute-30;
        ++i;

    }

}

void rezultat_utrke(int broj_utrke)
{
     list< Plivac*> ::iterator it;
     for(it=Plivac::lista.begin();it!=Plivac::lista.end();it++)
     {
         if ((*it)->broj_utrke==broj_utrke)
         {
             (**it).ispis();
         }
     }
}
int main ()
{
    //SimulirajUtrku(6,1);
    //rezultat_utrke(1);
    int r=1;
    string a=r;
    for (int i = 1; i<11; i++)
        cout << a;
    return 0;
}
