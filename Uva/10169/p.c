// @JUDGE_ID:  17051CA  10169  C++
// @begin_of_source_code
/* Mathmatic */
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<stl.h>
#define MAX 1000000

double P1[MAX];
int P2[MAX];

int n;

void init(){
  fill ( P1, P1 + MAX, 0 );
  fill ( P2, P2 + MAX, 0 );

  P1[1] = 0.5;
  P2[1] = 0;
 
  double L = log10( 2 );
  for ( int i = 2; i < MAX; i++ ){
    double p = ( (1.0/i) * (1.0/(i+1)) );
    P1[i] = P1[i-1] * ( 1 - p );
    L += log10( (double) i*(i+1) );
    P2[i] = (int)( floor(L) )  ;
  }

}

void work(){
  if ( n == 0 ) printf("%f %d\n", 0, 0 );
  else printf("%f %d\n", 1 - P1[n], P2[n] );
}

main(){
  init();
  while ( cin >> n ) work();
}
// @end_of_source_code
