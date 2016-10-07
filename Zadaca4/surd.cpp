#include "surd.h"
#include <string>
#include <cmath>

using namespace std;

Surd Surd::NaS("NaS");

Surd::Surd(string x)
{
    a=0;
    b=0;
    c=0;
    d = x;
}

void Surd::skrati()
{
    int i;
    if (c > 0)
        for(i=2; i*i<=c; i++)
            if(c % (i*i) == 0)
            {
                b *= i;
                c /= i;
                c /= i;
                i=1;
            }
    if (c<0)
    {
        c=-c;
        for(i=2; i*i<=c; i++)
            if(c % (i*i) == 0)
            {
                b *= i;
                c /= i;
                c /= i;
                i=1;
            }
        c = -c;
    }
    if (c==1)
    {
        a += b;
        b=0;
        c = 0;
    }
    if (c==0)
        b = 0;
    
    if (b==0)
        c = 0;
}

Surd::Surd()
{
    a=0;
    b=0;
    c=0;
    d="";
}

Surd::Surd(int x)
{
    a=x;
    b=0;
    c=0;
    d="";
}

Surd::Surd(int x, int y, int z)
{
    a=x;
    b=y;
    c=z;
    d="";
    skrati();
}

Surd:: operator double() const
{
    double rezultat, q=a, w=b, e=c;
    if (e>=0)
        rezultat = q + w*sqrt(e);
    else
        rezultat = 0.0;
    return rezultat;
}

ostream &operator<< (ostream& f, const Surd& x)
{
    if (x.d == "NaS")
    {
        f << "NaS";
        return f;
    }
    if (x.c>0)
    {
        if (x.b == 1)
        {
            if (x.a == 0)
                f << "@" <<x.c;
            else 
                f << x.a << "+@" << x.c;
        }
        else if (x.b == -1)
        {
            if (x.a == 0)
                f << "-@" <<x.c;
            else 
                f << x.a << "-@" << x.c;
        }
        else if (x.b >0 && x.b != 1)
        {
            if (x.a == 0)
                f <<x.b << "@" << x.c;
            else
                f << x.a << "+" <<x.b << "@" << x.c;
        }
        else 
        {
            if (x.a == 0)
                f <<x.b << "@" << x.c;
            else
                f << x.a <<x.b << "@" << x.c;
        }
    }
    else if (x.c == 0)
    {
        f << x.a;
    }
    else if (x.c == -1)
    {
        if (x.a == 0)
        {
            if (x.b == 0)
                f << 0;
            else if (x.b == 1)
                f << "i";
            else if (x.b == -1)
                f << "-i";
            else 
                f << x.b << "i";
        }
        else
        {
            if (x.b==0)
                f << x.a;
            else if (x.b == 1)
                f << x.a << "+i";
            else if (x.b == -1)
                f << x.a << "-i";
            else if (x.b>0)
                f << x.a << "+"<< x.b << "i";
            else
                f << x.a << x.b << "i";
        }   
    }
    else
    {
        if (x.a == 0)
        {
            if (x.b == 0)
                f << 0;
            else if (x.b == 1)
                f << "i@" << -x.c;
            else if (x.b == -1)
                f << "-i@" << -x.c;
            else 
                f << x.b << "i@" << -x.c;
        }
        else
        {
            if (x.b==0)
                f << x.a;
            else if (x.b == 1)
                f << x.a << "+i@" <<-x.c;
            else if (x.b == -1)
                f << x.a << "-i@" <<-x.c;
            else 
                f << x.a << x.b << "i@" << -x.c;
        }

    }
	return f;
}

int& operator++(Surd& x)
{
        return x.a;
}

int& operator++(Surd& x, int)
{
        return x.b;
}

int Surd::operator++() const
{
    if (d=="NaS")
        return 0;
    int x = this->a;
    return x;
}
int Surd::operator++(int) const
{
    if (d=="NaS")
        return 0;
    int x = this->b;
    return x;
}

bool operator== (const Surd& x,const Surd& y)
{
    if (x.d=="NaS" || y.d =="NaS")
        return false;
     if (x.a == y.a && x.b == y.b && x.c==y.c)
        return true;
    else
        return false;
}
bool operator< (const Surd& x,const Surd& y)
{
    if (x.d=="NaS" || y.d =="NaS")
        return false;
    if (x.c<0 || y.c<0)
        return false;
    double a=x, b=y;
    if (a < b)
        return true;
    else
        return false;
}

Surd operator* (const Surd& x, const Surd& y)
{
    if (x.d=="NaS" || y.d=="NaS")
        return Surd::NaS;
    if ((x.c == y.c) || (x.c == 0 || y.c==0) || (x.a == 0 && y.a==0) )
    {
        Surd umnozak;
        if (y.c==0 && x.c!=0)
        {
            umnozak.a = x.a * y.a + x.c*x.b*y.b;
            umnozak.b = x.a * y.b + y.a * x.b;
            umnozak.c = x.c;
        }
        else if (x.c==0)
        {
            umnozak.a = x.a * y.a + y.c*x.b*y.b;
            umnozak.b = x.a * y.b + y.a * x.b;
            umnozak.c = y.c;            
        }
        else if (x.c == y.c && x.c!=0)
        {
            umnozak.a = x.a * y.a + x.c*x.b*y.b;
            umnozak.b = x.a * y.b + y.a * x.b;
            umnozak.c = x.c;
        }
        else
        {
            umnozak.a = 0;
            umnozak.b = y.b * x.b;
            umnozak.c = x.c * y.c;
        }
        umnozak.skrati();
        return umnozak;
    }
    else
        return Surd::NaS;
}

Surd operator+ (const Surd& x,const Surd& y)
{
    if (x.d=="NaS" || y.d=="NaS")
        return Surd::NaS;
    if (x.c != y.c && (x.c!=0 && y.c!=0) )
    {
        Surd abc=Surd::NaS;
        return abc;
    }
    else
    {
        Surd zbroj;
        zbroj.a = x.a + y.a;
        zbroj.b = x.b + y.b;
        if (y.c==0)
            zbroj.c = x.c;
        else
            zbroj.c = y.c;        
        zbroj.skrati();
        return zbroj;
    }
}

Surd operator- (const Surd& x,const Surd& y)
{
    if (x.d=="NaS" || y.d=="NaS")
        return Surd::NaS;
    if (x.c != y.c && (x.c!=0 && y.c!=0) )
    {
        Surd abc=Surd::NaS;
        return abc;
    }
    else
    {
        Surd zbroj;
        zbroj.a = x.a - y.a;
        zbroj.b = x.b - y.b;
        if (y.c==0)
            zbroj.c = x.c;
        else
            zbroj.c = y.c;
        zbroj.skrati();
        return zbroj;
    }
}

Surd Surd::operator-() const 
{ 
    if (d=="NaS")
        return NaS;
    return Surd(-a,-b, c);	
}

Surd Surd::operator~() const
{
    if (d=="NaS")
        return NaS;
    return Surd(a,-b,c);
}

Surd Surd::operator*() const
{
    if (d=="NaS")
        return NaS;
    Surd q = *this * (~(*this));
    return q;
}

Surd operator^ (const Surd& x, const unsigned& n)
{
    if (x.d=="NaS")
        return Surd::NaS;
    Surd a=x;
    unsigned i;
    for (i=0; i<n-1; i++)
        a = x*a;
    return a;
}

Surd::~Surd()
{
    
}
