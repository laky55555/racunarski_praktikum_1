#include <iostream>
#include <map>
using namespace std;

class polinom
{
    public:
    map<int, int> p;
    polinom(int a=0)
    {
        p[0]=a;
    }
    polinom (char s)
    {
        p[1]=1;
    }
    polinom operator-()
    {
       polinom a;
        map<int, int>::iterator it;
        for (it=p.begin();it!=p.end();it++)
        {
            a.p[it->first]=it->second;
        }
        return a;
    }
    friend polinom operator+(const polinom &a, const polinom &b );
    friend polinom operator-(const polinom &a, const polinom &b );
    friend polinom operator*(polinom &a,  polinom &b );
    polinom operator^(unsigned n)
    {
        polinom c=*this;
        for (int i=0;i<n-1;i++) c=*this*c;
        return c;
    }
    int operator () (int j)
    {
        //horner
        map<int, int>::iterator ia;
        ia=p.end();
    --ia;
    int n=ia->first;
    int sum=p[n];
    for (int i=n-1;i>=0;i--)
    {
        int h;
        if(p.find(i)==p.end())h=0;
        else h=p[i];
        sum=sum*j+h;

    }
    return sum;
    }

};

polinom operator+(polinom &a, polinom &b )
{
    polinom c;
    map<int, int>::iterator ia,ib;
    for (ia=a.p.begin();ia!=a.p.end();ia++)
    {
        for (ib=b.p.begin();ib!=b.p.end();ib++)
        {
           if(ia->first==ib->first) c.p[ia->first]=ia->second+ib->second;
        }
    }
    return c;

}
polinom operator-( polinom &a,  polinom &b )
{
    polinom c;
    map<int, int>::iterator ia,ib;
    for (ia=a.p.begin();ia!=a.p.end();ia++)
    {
        for (ib=b.p.begin();ib!=b.p.end();ib++)
        {
           if(ia->first==ib->first) c.p[ia->first]=ia->second-ib->second;
        }
    }
    return c;
}
polinom operator*( polinom &a, polinom &b )
{
    polinom c;
    map<int, int>::iterator ia,ib;
    for (ia=a.p.begin();ia!=a.p.end();ia++)
    {
        for (ib=b.p.begin();ib!=b.p.end();ib++)
        {
           int k=ia->first+ib->first;
           if(a.p.find(k)==a.p.end())c.p[k]=ia->second*ib->second;
           else c.p[k]+=ia->second*ib->second;
        }
    }
    return c;
}


ostream& operator<< (ostream &f, polinom a)
{
    f << "[" ;
    map<int, int>::iterator ia;
    ia=a.p.end();
    --ia;
    int n=ia->first;
    for (int i=0;i<=n;i++)
    {
        if(a.p.find(i)==a.p.end() && i!=n)f<< "0," ;
        else if (a.p.find(i)!=a.p.end() && i!=n) f << a.p[i]<<", ";
        else f << a.p[i] ;
    }
    f << "]";
    return f;
}

istream & operator>> (istream &f,polinom &p)
{
    char c;
    f >> c;
    int k=0;
    while(c!=']')
    {
        f >> c;
        int i=c;
        if(i>=48 && i<=48+9){i=i-48;
        p.p[k]=i;
        k++;}
    }
    return f;
}
int main ()
{
    polinom p(3);
    polinom c('x');
    cout << p <<" " << c<<endl;
    cout << p*c <<endl;
    polinom novi=c^3,h(0);
    cout << novi<<endl;
    cout << novi(2)<<endl;

    //ako zelimo ucitat polinom
    cin >> h;
    cout << h <<endl;
    cout << h(0)<<endl;
    return 0;
}
