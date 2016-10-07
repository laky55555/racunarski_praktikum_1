#include<iostream>
#include<cmath>
#include"surd.h"
using namespace std;

int main(){
  Surd b(3,4,5),c(2,1,5),zb(5,5,5),raz(1,3,5),pr(26,11,5);
  cout<<(b+c==zb)<<(b-c==raz)<<(b*c==pr)<<(pr==zb)<<(b-c==-(c-b))<<endl;
  cout<<*raz<<endl<<(b+~b==Surd(6));
  cout<<(fabs((double)raz-7.70824)<0.0001)<<endl;
  cout<<++raz<<'|'<<pr++<<endl;

  return 0;
}
