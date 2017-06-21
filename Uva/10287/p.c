// @JUDGE_ID:  17051CA  10287  C++
// @begin_of_source_code
/* Math - Geometory */
#include<stdio.h>
#include<iostream>
#include<cmath>

double PI;
double S;
double root3;

double gift1, gift2, gift3, gift4;

void compute1(){
   gift1 = S * root3 / 2.0;
}

void compute2(){
  gift2 = S * root3 / ( root3 + 2.0 );
}

void compute3(){
  gift3 = S * root3 / 4.0;
}

void compute4(){
  double a = 20 * root3;
  double b = 84 * S;
  double c = -1 * 21 * root3 * S * S;
  gift4 = ( -b + sqrt( b*b - 4*a*c ) ) / (2*a);
}

void work(){
  compute1();
  compute2();
  compute3();
  compute4();
  printf("%.10lf %.10lf %.10lf %.10lf\n", gift1, gift2, gift3, gift4 );
}

bool read(){
  if ( !( cin >> S ) ) return false;
  return true;
}

main(){
  PI = 2 * acos( 0.0 );
  root3 = sqrt( 3.0 );
  while ( read() ){
    work();
  }
}
// @end_of_source_code
