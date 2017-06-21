// @JUDGE_ID:  17051CA  474  C++
// @begin_of_source_code
/* Mathmatic */
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

int n;
double T[1000001L];

void work(){
  int e;
  e = (int)(n * log10( 2 ) + 1);

  cout << "2^-"  << n << " = ";
  printf("%.3f", T[n]);
  cout << "e-" << e << endl;
}

void init(){
  double p = 1;
  T[0] = 1;
  for ( long i = 1; i < 1000001L; i++ ){
    p /= 2;
    while ( p < 1 ) p *= 10;
    T[i] = p;
  }
}

main(){
  init();
  while ( cin >> n ){
    work();
  }
}
// @end_of_source_code
