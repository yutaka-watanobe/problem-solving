// @JUDGE_ID:  17051CA  640  C++
// @begin_of_source_code
/* Number Theory */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<cmath>

unsigned char S[ 1000100 ]; /* self number */

int P[9] = { 0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

void sieve( int x ){
  int digit = (int)( log10( x ) ) + 1;
  int p = P[ digit ];
  int sum = x;

  for ( int i = 0; i < digit; i++ ){
    sum += x / p;
    x = x % p;
    p /= 10;
  }

  S[ sum ] = 0;
}

void work(){
  fill( S, S + 1000100, 1 );

  string str;
  for ( int i = 1; i <= 1000100; i++ ){
    sieve( i );
  }
  
  int sum = 0;
  for ( int i = 1; i <= 1000000; i++ ){
    if ( S[i] ) {
      printf("%d\n", i );
    }
  }

}

main(){
  work();
}
// @end_of_source_code
