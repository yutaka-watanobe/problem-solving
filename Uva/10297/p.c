#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#define M_PI            3.14159265358979323846
double D, V;

int read(){
  cin >> D >> V;
  if(D==0 && V==0) return 0;
  return 1;
}

void work(){
  double A;
  A = D*D*D - 6*V/M_PI;

  A = pow(A, 1.0/3);

  printf("%.3f\n", A);
}

main(){
  while(read()) work();
}
