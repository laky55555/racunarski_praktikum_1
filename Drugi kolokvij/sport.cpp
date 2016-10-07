#include <iostream>
#include <string>

using namespace std;


class Sport
{
protected:
    string ime1, ime2;
public:
    Sport(string a1, string a2) : ime1(a1), ime2(a2) {}
    virtual string pobjednik ()
    {
        return 0;
    }
    virtual void servis(string ime, int udarac){}
};

class Boks : public Sport
{
    int brojudaraca1, brojudaraca2;
public:
    Boks (string a1, string a2) : Sport (a1, a2) 
    {
        brojudaraca1 = 0;
        brojudaraca2 = 0;
        cout << "pocela je prva runda" << endl;
    }
    void udarac (string a)
    {
        if (a==ime1)
            brojudaraca1++;
        else                                            //  098390536
            brojudaraca2++;
    }
    string pobjednik()
    {
        if (brojudaraca1>brojudaraca2)  
        {
            cout << "nokaut" << brojudaraca1 << ":" << brojudaraca2;
            return ime1;
        }
        else
        {
            cout << "nokaut" << brojudaraca2 << ":" << brojudaraca1;
            return ime2;
        }
    }
    
};

class Tenis : public Sport
{
    int udarac1, udarac2;
public:
    Tenis (string a1, string a2, string b = "Wimbledon") : Sport (a1, a2) 
    {
        udarac1=0;
        udarac2=0;
       // cout << "igra se u " << b << endl;
    }
    void servis (string ime, int udarac)
    {
        if (ime==ime1)
        {
            if(udarac1<udarac)
                udarac1 = udarac;
        }
        else
        {
            if (udarac2<udarac)
                udarac2 = udarac;
        }
    }
    string pobjednik()
    {
        if (udarac1>udarac2)
        {
            cout << "game, set, match " << ime1 << udarac1<<endl;
            return ime1;
        }
        else
        {
            cout << "game, set, match " << ime2 << udarac2<<endl;
            return ime2;
        }
    }
};


int main (void)
{
    Sport* niz[50];
    int i;
    for (i=0; i<50; i++)
    {
        niz[i] = new Tenis ("franjo", "josip");
        niz[i]->servis("franjo", i);
        niz[i]->pobjednik();
    }
    
    
    
    return 0;
}
