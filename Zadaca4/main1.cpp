#include "surd.h"
 
 
 using namespace std;
 
 
 
 int main(void)
 {
    Surd a(5,-3,-4), c(0,2,3);
    const Surd b(0,4,15);
    cout << a <<endl;
    cout << b <<endl;
    cout << b*c <<endl;
   // cout << c <<endl;
    double t= a;
    cout << t <<endl;
    /*cout << ++a << endl;
    ++a=4;
    cout << ++a << endl;
    cout << a++ << endl;
    cout << ++b << endl;
    cout << b++ << endl;*/
    
    if (a == b)
        cout << "Isti su" <<endl;
    else
        cout << "razlociti su" <<endl;
    if (a<b)
        cout << "a je manji od b" <<endl;
   /* cout << "zbroj je " << a+b << " umnozak " << a*b << " i razlika " << a-b << endl;
    cout << -a <<endl;
    cout << *c << endl << endl <<endl;
    Surd j;
    cout << (2)+(j) <<endl;
    cout << a << endl;
    int x =4;
    cout << (a^x) << endl;
    cout << (a*a) <<endl;
    */
    Surd g(0,0,-5);
    double aj=g;
    cout << aj;
     return 0;
 }
