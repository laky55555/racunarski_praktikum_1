#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <list>
#include <set>
using namespace std;

template<class T> struct Skladiste
{
    string naziv[10];
    T cijena[10];
    int brojpredmeta;
    
    Skladiste (string *a, T *b, int c)
    {
        int i;
        for (i=0; i<c; i++)
        {
            naziv[i] = a[i];
            cijena[i] = b[i];
        }
        brojpredmeta = c;
    }
    
    void ispisiNaEkran(void)
    {
        int i,k;
        float imaih;
        T pare;
        set<string> razlicitih;
        set<string>::iterator j;
        for (i=0; i<brojpredmeta; i++)
            razlicitih.insert(naziv[i]);
        for(j=razlicitih.begin(); j!=razlicitih.end(); j++)
        {
            for (i=0, k=0, pare = 0, imaih=0; i< brojpredmeta; i++, k++)
                if (naziv[i] == *j)
                {
                    pare = pare + cijena[k]; 
                    imaih++;
                }
            cout << *j << " " << pare/imaih <<"   ";
        }

    }
    
    int dodaj (string a, T b)
    {
        if (brojpredmeta==10)
            return 0;
        naziv[brojpredmeta]=a;
        cijena[brojpredmeta]=b;
        return 1;
    }
    
    string najskuplji()
    {
        int i, naj;
        for (i=0; i<brojpredmeta; i++)
            if (i == 0 || naj<cijena[i])
                naj = i;
        return naziv[naj];
    }
    
    int prebaci (Skladiste *A)
    {
        int prebacenih=0;
        while(brojpredmeta<11 && (*A).brojpredmeta>0)
        {
            naziv[brojpredmeta]=(*A).naziv[(*A).brojpredmeta-1];
            cijena[brojpredmeta]=(*A).cijena[(*A).brojpredmeta-1];
            brojpredmeta++;
            (*A).brojpredmeta--;
            prebacenih++;
        }
        return prebacenih;
    }
    
    ~Skladiste()
    {
        cout << "unisteno " << brojpredmeta << " predmeta" <<endl;
    }
    
};

int main (void)
{
    string a[3]; a[0] = "komp"; a[1] = "lampa"; a[2]= "komp";
    string x[3]; x[0] = "kompx"; x[1] = "lampax"; x[2]= "kompx";
    int b[3]; b[0]=2; b[1]=3; b[2]=4;
    int y[3]; y[0]=2; y[1]=3; y[2]=4;
    
    Skladiste<int> zz(a, b, 3);
    zz.ispisiNaEkran(); cout <<endl;
    Skladiste<int> zy (x, y, 3);
    zy.ispisiNaEkran(); cout <<endl;
    cout << zz.najskuplji() <<endl;
    zz.prebaci(&zy);
    zz.ispisiNaEkran(); cout <<endl;

    return 0;
}
