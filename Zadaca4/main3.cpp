#include<iostream>
#include <cmath>
#include"surd.h"
using namespace std;

int main()
{
    Surd b(3,4,5),c(2,1,5),zb(5,5,5),raz(1,3,5),pr(26,11,5);
    cout<<(b+c==zb)<<(b-c==raz)<<(b*c==pr)<<(pr==zb)<<(b-c==-(c-b))<<endl;
    cout<<*raz<<endl<<(b+~b==Surd(6));
    cout<<(fabs((double)raz-7.70824)<0.0001)<<endl;
    cout<<++raz<<'|'<<pr++<<endl;
    
    /*cout<<Surd(3)<<endl;
    cout<<Surd(4,-5,6)<<endl;
    cout<<Surd(0,2,-1)<<endl;
    cout<<Surd(-5,0,3)<<endl;
    cout<<Surd(2,1,-7)<<endl;
    cout<<Surd(0,-1,2)<<endl;
    Surd a(0,-1,2);
    cout<<a<<endl;
    ++a=a++=1;
    cout<<a<<endl;*/
        
    /*cout<<Surd(3,1,8)<<endl;
    cout<<Surd(-4,-5,-9)<<endl;
    cout<<Surd(4,5,9)-Surd(3,2,4)<< endl;
    cout<<Surd(-5,0,3)*Surd(4,-5,6)-Surd(2,3,24) <<endl;
    cout<<Surd(1,2,0)+Surd(2,3,5)<<endl;
    cout<<Surd(0,5,6)*Surd(0,-3,2)<<endl;
    Surd d(1,5,4);
    cout<<*d<<endl<<~d<<endl;
    cout<<++d<<endl<<d++<<endl<<(d^4)<< endl;*/
    
    /*Surd a(0,1,2),b(0,-1,3);
    Surd c=a+b;
    cout<<c<<endl<<a-b<<endl<<a*b<<endl;
    cout<<++(a+b)<<endl<<(a*b)++<<endl;
    cout<<(c==c)<<(double)c<<endl;
    cout<<(a^43)<<endl<<(Surd(0,1,-1)^563)<<endl;
    cout<<(Surd(2,1,-1)<Surd(3,4,5))<<(Surd(2,1,-1)<Surd(3,1,-1));
    cout<<(Surd(5)<Surd(3,2,1))<<(b<a)<<(a<b)<<endl;*/
        
    /*const Surd a(0,1,2),b(0,-1,3);
    const Surd c=a+b;
    const int d=c++,e=b++;
    cout<<d<<'|'<<e<<endl;
    int f=++c;
    cout<<f<<endl;*/
    
    /*Surd a(0,1,2),b(2,-1,-3);
    // cout<<a+3<<'|'<<~(3-a)<<'|'<<Surd::NaS*0<<endl;
    // cout<<(b*~b==*b)<<endl;
    // cout<<(a<2)<<(2<a)<<(a<1)<<(1<a)<<endl;
    // cout<<(b<2)<<(2<b)<<(a<b)<<(b<a)<<endl;
    cout<<(Surd::NaS==b)<<endl;
    cout<<Surd::NaS*a<<endl;
    cout<<(Surd::NaS^4)<<endl;*/
      
  return 0;
}
