#include <iostream>
#include <list>

using namespace std;


class Nanobot
{
    private:
    string Ime;
    int Vijek, Vrijeme,Sustav;
    static list<Nanobot*> lista;
    static int brojac_uk;
    public:
    Nanobot(){}
    Nanobot(string ime, int vrijeme, int vijek,int sustav)
    {
        this->Ime=ime;
        this->Vrijeme=vrijeme;
        this->Vijek=vijek;
        this->Sustav=sustav;
    }
    string ime()
    {
        return Ime;
    }
    int vijek()
    {
        return Vijek;
    }
    int vrijeme()
    {
        return Vrijeme;
    }
    void ostari()
    {
        Vrijeme++;
    }
    int  sustav()
    {
        return Sustav;
    }
    virtual void stvori_novog()=0;

    void unisti_se()
    {

        if(Vrijeme>=Vijek)
        {
            cout << Vrijeme << " " << Vijek<< "brisanje iz liste"<<endl;
            list <Nanobot*> ::iterator it;
            for (it=lista.begin();it!=lista.end();)
            {
                if((*it)==this)
                    {
                    it=lista.erase(it);
                    brojac_uk--;
                }
                else it++;
            }
        }
    }
    friend void ubaci_u_listu(Nanobot *A);
   friend int izbroji1(int i);
   friend int izbroji2(int i);
    friend int izbroji3(int i);
    friend void ispis(int i);
    friend void simulirajSustav (int dana, int brojSustava, int x51, int x52);
    void ispis()
    {
        cout << Ime << " " << Vrijeme << " " << Vijek << " " << Sustav<<endl;
    }
    ~Nanobot()
    {
        list <Nanobot*> ::iterator it;
            for (it=lista.begin();it!=lista.end();)
            {
                if((*it)==this)
                {
                    it=lista.erase(it);
                    brojac_uk--;
                }
                else it++;
            }
    }
    static void koliko_ih()
    {
        cout <<brojac_uk<<endl;
    }
};

void ubaci_u_listu(Nanobot *A)
{
    Nanobot::lista.push_front(A);
    Nanobot::brojac_uk++;
}
class X5:public Nanobot
{
private:
    int razmnozavanje;
    public:
        X5(){}
    X5(string ime, int vrijeme, int vijek, int razmnozavanje, int sustav):Nanobot(ime, vrijeme,vijek,sustav)
    {
        this->razmnozavanje=razmnozavanje;
    }
    int raz()
    {
        return razmnozavanje;
    }
    virtual void stvori_novog()=0;

};

class X51 : public X5
{
public:
    X51(){}
    X51(string ime, int vrijeme, int vijek, int razmnozavanje, int sustav):X5(ime, vrijeme,17,6,sustav)
    {
    }
    void stvori_novog()
    {
        int dana=this->vrijeme();
        if(dana%6==0)
        {/*cout << "nastaje novi X51"<<endl;*/
             X51 novi(this->ime(),0, this->vijek(), this->raz(),this->sustav());
        X51 *A=new X51;
        *A=novi;
        ubaci_u_listu(A);}
    }

};

class X52:public X5
{
public:
X52(){}
     X52(string ime, int vrijeme, int vijek, int razmnozavanje, int sustav):X5(ime, vrijeme,18,7,sustav)
    {
    }
    void stvori_novog()
    {
        if(this->vrijeme()%7==0)
        {X52 novi(this->ime(), 0, this->vijek(), this->raz(),this->sustav());
        X52 *A=new X52;
        *A=novi;
        ubaci_u_listu(A);}
    }
};


 list<Nanobot*> Nanobot::lista;
int Nanobot::brojac_uk=0;

int izbroji1(int i)
{
     int brojac=0;
     list <Nanobot*> ::iterator it;
    for (it=Nanobot::lista.begin();it!=Nanobot::lista.end();it++)
        if((*it)->ime()=="X51" && (*it)->sustav()==i)brojac++;

    return brojac;
}

int izbroji2(int i)
{
     int brojac=0;
     list <Nanobot*> ::iterator it;
    for (it=Nanobot::lista.begin();it!=Nanobot::lista.end();it++)
        if((*it)->ime()=="X52" && (*it)->sustav()==i)brojac++;

    return brojac;
}
int izbroji3(int i)
{
    int brojac=0;
     list <Nanobot*> ::iterator it;
    for (it=Nanobot::lista.begin();it!=Nanobot::lista.end();it++)
        if( (*it)->sustav()==i)brojac++;

    return brojac;
}


void ispis(int i)
{
    list <Nanobot*> ::iterator it;
    cout << "---------------------"<<endl;
    for (it=Nanobot::lista.begin();it!=Nanobot::lista.end()&&((*it)->sustav()==i) ;it++)
    {
        (*it)->ispis();
    }
    cout << "---------------------"<<endl;
}



void simulirajSustav (int dana, int brojSustava, int x51=1, int x52=1)
{
    int i;

    for (i=0;i<x51;i++)
    {
        X51 novi("X51",0,17,6,brojSustava);
        X51 *A=new X51;
        *A=novi;
        ubaci_u_listu(A);
    }
     for (i=0;i<x52;i++)
    {
        X52 novi("X52",0,18,7,brojSustava);
        X52 *B=new X52;
        *B=novi;
        ubaci_u_listu(B);
    }

 i=0;



    while(i<dana)
    {
        cout <<i<<endl;
        list <Nanobot*> ::iterator it, kopija;
        for (it=Nanobot::lista.begin();it!=Nanobot::lista.end()&&(*it)->sustav()==brojSustava;)
        {

            (*it)->ostari();
(*it)->stvori_novog();

            kopija=it;
            ++it;
            (*kopija)->unisti_se();

        }
        double koliko1=izbroji1(brojSustava);
        double koliko2=izbroji2(brojSustava);
        double  ukupno=izbroji3(brojSustava);
        if(koliko2/ukupno>0.8 || koliko1/ukupno>0.8)
        {
            cout << koliko1 <<" "<< koliko2 <<" "<< ukupno <<endl;
            break;}
            ispis(brojSustava);
         i++;

    }
}

void distribucijaSustava(int brojSustava)
{
    double koliko1=izbroji1(brojSustava);
        double koliko2=izbroji2(brojSustava);
        double ukupno=izbroji3(brojSustava);

        cout << koliko1 <<" "<< koliko2 <<" "<< ukupno <<endl;
        cout << "X51: " << koliko1/ukupno<<endl;
        cout << "X52: " <<koliko2/ukupno<<endl;

}


int main()
{
    simulirajSustav(25,1,3,3);
    distribucijaSustava(1);
    Nanobot::koliko_ih();
    /*simulirajSustav(10,2,1,2);
    distribucijaSustava(2);
    Nanobot::koliko_ih();*/
    return 0;
}
