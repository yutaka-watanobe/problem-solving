#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define EPS 0.00001

void compute(int q){
  double x = q/2.0;
  while(1){
    if ( fabs(x*x*x - q) < EPS*q ) break;
    x = x - (x*x*x - q)/(3*x*x);


  }
  printf("%.6lf\n", x);
}

main(){
  int q;
  while( cin >> q && q >= 0 ) compute(q);
}
