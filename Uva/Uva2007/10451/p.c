// @JUDGE_ID:  17051CA  10451  C++
// @begin_of_source_code
/* Mathmatic & Geometory */
#include<stdio.h>
#include<iostream>
#include<cmath>

int n;
double A;
double PI;

bool read(){
  cin >> n >> A;
  if ( n < 3 ) return false;
  return true;
}

void work(){
  double R1, R2;
  double spectator, official;

  R1 = sqrt( 2*A/( n*sin(2*PI/n) ) );
  spectator = PI*R1*R1 - A;

  R2 = sqrt( A/( n*tan(PI/n) ) );
  official = A - PI*R2*R2;

  printf(" %.5lf %.5lf\n", spectator, official );
}

main(){
  PI = 2*acos( 0.0 );
  for ( int i = 1; read(); i++ ){
    cout << "Case " << i << ":";
    work();
  }
}
// @end_of_source_code


