#include<iostream>
#include"surd.h"
using namespace std;

int main(){
  const Surd a(0,1,2),b(0,-1,3);
  const Surd c=a+b;
  const int d=c++,e=b++;
  cout<<d<<'|'<<e<<endl;
  int f=++c;
  cout<<f<<endl;
  
  return 0;
}
