#include <iostream>
#include <string>
#include <list>
using namespace std;


class Nanobot
{
    int vijek_trajanja, prosli_dani;
    string naziv;
public:
    Nanobot(){}
    static int ukupan_broj;

    Nanobot(string ime, int zivot)
    {
        naziv = ime;
        prosli_dani = 0;
        vijek_trajanja = zivot;
    }
    int& vijek()
    {
        return vijek_trajanja;
    }
    int& vrijeme()
    {
        return prosli_dani;
    }
    string ime ()
    {
        return naziv;
    }

    static void ukupnoStvorenih()
    {
        cout << "Stvoreno je " << ukupan_broj << " nanobota." << endl;
    }
};

int Nanobot::ukupan_broj = 0;

class X5 : public Nanobot
{
    int brzina_razmnozavanja;
public:
    X5(){}
    X5 (string ime, int brzina, int zivot) : Nanobot(ime, zivot)
    {
        brzina_razmnozavanja = brzina;
    }
};

class X51 : public X5
{
public:
    X51(){}
    static list<X51*> lista51;
    X51 (string ime) : X5(ime, 6, 17) {}
};

class X52 : public X5
{
public:
    X52(){}
    static list<X52*> lista52;
    X52 (string ime) : X5(ime, 7, 18) {}
};

list<X51*> X51::lista51;
list<X52*> X52::lista52;

void distribucijaSustava(int brojSustava)
{
    double ukupno = X51::lista51.size() + X52::lista52.size();
    cout << "Udio X51 i X52 i sustavu " << brojSustava << " je " << X51::lista51.size()/ukupno << " i " << X52::lista52.size()/ukupno <<endl;
    cout << "Ima " << X51::lista51.size() << " X51 i " << X52::lista52.size() << " X52." <<endl;
}

void simulirajSustav (int dana, int brojSustava, int x51=1, int x52=1)
{
    X51::lista51.clear();
    X52::lista52.clear();
    list<X51*>::iterator i51;
    list<X52*>::iterator i52;
    int i;
    for(i=1; i<=x51; i++)
    {
        X51 a("X51");
        X51::lista51.push_back(&a);
        Nanobot::ukupan_broj++;
    }
    for(i=1; i<=x52; i++)
    {
        X52 b("X52");
        X52::lista52.push_back(&b);
        Nanobot::ukupan_broj++;
    }
    //cout << "x51 " << X51::lista51.size() <<endl;
    for (i = 1; i<=dana; i++)
    {
        cout << "dan " << i << ": ";
        for(i51=X51::lista51.begin(); i51!=X51::lista51.end();)
        {
            if( (*i51)->vijek()== 0)
            {
                cout << "umire" <<endl;
                X51::lista51.erase(i51++);
                continue;
            }

            cout <<"vijek trajanja"<< (*i51)->vijek() <<endl;

            (*i51)->vijek()--;


            if ( ((*i51)->vrijeme()+1) % 6 == 0)
            {
                X51 a("X51");
                X51 *novi=new X51;
                *novi=a;
                X51::lista51.push_front(novi);
                Nanobot::ukupan_broj++;
               // cout << "rada se novi" <<endl;
            }
            (*i51)->vrijeme()++;

            i51++;
        }
        for(i52=X52::lista52.begin(); i52!=X52::lista52.end();)
        {
            if( (*i52)->vijek()== 0)
            {
                X52::lista52.erase(i52++);
                continue;
            }
            (*i52)->vijek()--;
            if ( ((*i52)->vrijeme()+1) % 7 == 0)
            {
                X52 a("X52");
                X52 *novi=new X52;
                *novi=a;
                X52::lista52.push_front(novi);

                Nanobot::ukupan_broj++;
            }
            (*i52)->vrijeme()++;
            i52++;
        }
        double a=X51::lista51.size(), b=X52::lista52.size();
        double ukupno = a + b;
        if (a/ukupno>0.8 || b/ukupno>0.8)
            break;
        cout <<endl;
    }
    distribucijaSustava(brojSustava);
}

int main(void)
{
    simulirajSustav(25,1,3,3);

    return 0;
}



