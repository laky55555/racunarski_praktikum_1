#include <iostream>
#include <string>
#include <cmath>


using namespace std;


class Vektor
{
public:
    double x,y,z;
    Vektor(double a=0, double b=0, double c=0) : x(a), y(b), z(c) {}
    
    friend Vektor operator+ (const Vektor& a, const Vektor& b);
    friend double operator| (const Vektor& a, const Vektor& b);
    friend Vektor operator* (const Vektor& a, const Vektor& b);
    friend Vektor operator* (const double& a, const Vektor& b);
    friend ostream& operator<< (ostream& f, const Vektor &a);
    friend istream& operator>> (istream& f, const Vektor &a);
    friend bool operator|| (const Vektor& a, const Vektor& b);

    double& operator[] (char i)
    {
        if(i=='x')
            return this->x;
        if(i=='y')
            return this->y;
        if(i=='z')
            return this->z;
    }
    
    operator double() const
    {
        double a;
        a = x*x + y*y + z*z;
        a = sqrt(a);
        return a;
    }
    
};

Vektor operator+ (const Vektor& a, const Vektor& b)
{
    Vektor c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    return c;
}

double operator| (const Vektor& a, const Vektor& b)
{
    double c;
    c = a.x*b.x + a.y*b.y + a.z+b.z;
    return c;
}

Vektor operator* (const Vektor& a, const Vektor& b)
{
    Vektor c;
    c.x = a.y*b.z-b.y*a.z;
    c.y = a.x*b.z-b.x*a.z;
    c.z = a.x*b.y-b.x*a.y;
    return c;
}

Vektor operator* (const double& a, const Vektor& b)
{
    Vektor c;
    c.x = a * b.x;
    c.y = a * b.y;
    c.z = a * b.z;
    return c;
}

ostream& operator<< (ostream& f, const Vektor &a)
{
    f << "(" << a.x << ", " << a.y << ", " << a.z << ")";
    return f;
} 

istream& operator>> (istream& f, Vektor &a)
{
    return f >> a.x >> a.y >> a.z;
}

bool operator|| (const Vektor& a, const Vektor& b)
{
    double x,y,z;
    x = a.x/b.x;
    y = a.y/b.y;
    z = a.z/b.z;
    if(x-y<0.0001 && y-z<0.0001 && z-x<0.0001 && x-y>-0.0001 && y-z>-0.0001 && z-x>-0.0001)
        return true;
    else
        return false;
}


int main (void)
{
    Vektor a(2,2,2), b(2,1,2);
    cout << a << "  " << b <<endl;
    cout << a+b << "  " << a*b*a <<endl;
    cout << 2.*a << "  " << a/b <<endl;
    cout << double(a) << "  " << a <<endl;
    cout << (a||b) << "  " << (a|b) <<endl;
    cout << a['x']++ << "  " << a <<endl; 
    
    return 0;
}
