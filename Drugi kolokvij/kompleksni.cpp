#include <iostream>
#include <string>
#include <cmath>


using namespace std;

class Cplx
{
public:
    static double eps;
    double re,im;
    Cplx (double a, double b=0) : re(a), im(b)
    {}
   /* Cplx(double a) : re(a)
    {
        im = 0;
        re = a;
    }*/
    Cplx (string a)
    {
        if (a == "i")
        {
            im = 1;
            re = 0;
        }
        else
            re = im = 0;
    }
    Cplx ()
    {
        re = im = 0;
    }
    Cplx* operator->()
    {
        return this;
    }
    friend ostream& operator<<(ostream& f, const Cplx& a);
    operator double() const
    {
        double a = re*re+im*im;
        a = sqrt(a);
        return a;
    }
    Cplx operator~ () const
    {
        Cplx a(re,-im);
        return a;
    }
    friend Cplx operator* (const Cplx& x,const Cplx& y);
    friend Cplx operator+ (const Cplx& x,const Cplx& y);
    friend Cplx operator/ (const Cplx& x,const Cplx& y);
    friend bool operator== (const Cplx& x,const Cplx& y);

};

ostream& operator<< (ostream& f, const Cplx& a)
{
    if (a.re == 0)
    {
        if (a.im == 0)
            f << a.im;
        else if(a.im == -1)
            f << "-i";
        else if(a.im == 1)
            f << "i";
        else
            f << a.im << "i";
    }
    else
    {
        if (a.im == 0)
            f << a.re;
        else if(a.im == -1)
            f << a.re << "-i";
        else if(a.im == 1)
            f << a.re << "+i";
        else if (a.im < 0)
            f << a.re << a.im << "i";
        else
            f << a.re << "+" <<a.im << "i";
    }
    return f;
}

Cplx operator* (const Cplx& q,const Cplx& w)
{
    Cplx x = q;
    Cplx y = w;
    Cplx a;
    a.re = x.re*y.re - x.im*y.im;
    a.im = x.re*y.im + x.im*y.re;
    return a;
}

Cplx operator+ (const Cplx &x, Cplx& y)
{
    Cplx a;
    a.re = x.re + y.re;
    a.im = x.im + y.im;
    return a;
}

Cplx operator/ (const Cplx& x,const Cplx& y)
{
    if(y.im == 0 && y.re == 0)
    {
        cout << "div0!" <<endl;
        return 0;
    }
    else if (x.im == 0 && x.re==0)
        return 0;
    else
    {
        Cplx a;
        a = x*(~y);
        a.re /= (y.re*y.re+y.im*y.im);
        return a;
    }

}

bool operator== (const Cplx& x, const Cplx& y)
{
    double a = (double)x - (double)y;
    if (a<0)
        a = -a;
    if (a<Cplx::eps)
        return true;
    else
        return false;
}


double Cplx::eps=0.0000001;

int main (void)
{
    Cplx::eps = 0.1;
    Cplx a(1,0);
    a->im = 101;
    cout << a->im <<endl;
    int t = 101;
    Cplx b = t;
    cout << a << "  " << (double)a <<endl;
    cout << ~a <<endl;
    cout << (double)b <<endl;
    cout << (a==b) <<endl;
    Cplx z(7,9);

 cout << (2*a) <<endl;
  b = a*2;
  cout << b<< endl;

    int p=3;
    cout << (Cplx)p << endl;

    return 0;
}
