#include<iostream>
#include"surd.h"
using namespace std;

int main(){
  Surd a(0,1,2),b(0,-1,3);
  Surd c=a+b;
  cout<<c<<endl<<a-b<<endl<<a*b<<endl;
  cout<<++(a+b)<<endl<<(a*b)++<<endl;
  cout<<(c==c)<<(double)c<<endl;
  cout<<(a^43)<<endl<<(Surd(0,1,-1)^563)<<endl;
  cout<<(Surd(2,1,-1)<Surd(3,4,5))<<(Surd(2,1,-1)<Surd(3,1,-1));
  cout<<(Surd(5)<Surd(3,2,1))<<(b<a)<<(a<b)<<endl;

  return 0;
}
