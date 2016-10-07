#include <iostream>
#include <string>
#include <list>

using namespace std;

template <class T> 
struct Vozilo 
{
    T brzina, put;
    float vrijeme;
    list<string> pomaci;
    int koordinata_x, koordinata_y;
    
    Vozilo (T n)
    {
        brzina = n;
        vrijeme = 0;
        koordinata_x = 0;
        koordinata_y =0;
        put = 0;
    }
    
    void promijeniBrzinu (T n)
    {
        brzina = n;
    }
    
    void pomak (string a)
    {
        if (a == "gore")
            koordinata_y++;
        else if (a == "dolje")
            koordinata_y--;
        else if (a == "lijevo")
            koordinata_x--;
        else 
            koordinata_x++;
        vrijeme += 1/float(brzina);
        pomaci.push_back(a);
        put+=1;
    }
    
    void ispisNaEkran(void)
    {
        string x;
        cout <<"(" << koordinata_x << ", " << koordinata_y << ")" <<endl;
        list<string>::iterator i;
        for (i=pomaci.begin(); i!=pomaci.end(); )
        {
            int imaih = 0;
            x = *i;
            while (i!=pomaci.end() && *i == x)
            {
                imaih++;
                i++;
            }
            cout << imaih << " " << x << " ";
        }
    }
    
    float prosjecnaBrzina()
    {
        float pros;
        pros = float(put)/float(vrijeme);
        return pros;
    }
    
    int izbjegniSudar(Vozilo *V)
    {
        if ((*V).koordinata_x == koordinata_x && (*V).koordinata_y == koordinata_y)
        {
            (*V).pomak("gore");
            pomak("desno");
            return 1;
        }
        else
            return 0;
    }
    
    ~Vozilo()
    {
        cout << "unisteno vozilo na koordinatama: (" << koordinata_x << ", " << koordinata_y << ")" <<endl;
    }

};

int main(void)
{
    int a=10;
    Vozilo<int> A(a), B(a+5);
    A.pomak("gore");
    A.pomak("gore");
    A.pomak("gore");
    A.pomak("desno");
    A.ispisNaEkran();
    B.pomak("gore");
    B.pomak("gore");
    B.pomak("gore");
    B.pomak("desno");
    cout << B.izbjegniSudar(&A)<<endl;
    A.ispisNaEkran();
    cout <<endl;
    B.ispisNaEkran();
    
    
    return 0;
}
