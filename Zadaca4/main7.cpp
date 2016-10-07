#include<iostream>
#include"surd.h"
using namespace std;

int main(){
  cout<<Surd(3)<<endl;
  cout<<Surd(4,-5,6)<<endl;
  cout<<Surd(0,2,-1)<<endl;
  cout<<Surd(-5,0,3)<<endl;
  cout<<Surd(2,1,-7)<<endl;
  cout<<Surd(0,-1,2)<<endl;
  Surd a(0,-1,2);
  cout<<a<<endl;
  ++a=a++=1;
  cout<<a<<endl;

  return 0;
}
