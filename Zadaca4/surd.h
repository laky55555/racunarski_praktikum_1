#include <iostream>
#include <string>

using namespace std;

class Surd
{
    int a, b, c;
    string d;
    void skrati();    
    
public:
    static Surd NaS;
    Surd();
    Surd(int x);
    Surd(string x);
    Surd(int x, int y, int z);
    operator double() const;
    friend ostream& operator <<(ostream& f, const Surd& x);
    friend int& operator++(Surd& x);
    friend int& operator++(Surd& x, int);
    int operator++() const;
    int operator++(int) const;
    friend bool operator== (const Surd& x,const Surd& y);
    friend bool operator< (const Surd& x,const Surd& y);
    friend Surd operator* (const Surd& x,const Surd& y);
    friend Surd operator+ (const Surd& x,const Surd& y);
    friend Surd operator- (const Surd& x,const Surd& y);
    Surd operator-() const;
    Surd operator~() const;
    Surd operator*() const;
    friend Surd operator^ (const Surd& x, const unsigned& n);
    ~Surd();
    
};
