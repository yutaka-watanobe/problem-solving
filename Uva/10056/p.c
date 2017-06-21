// @JUDGE_ID:  17051CA  10056  C++
// @begin_of_source_code
/* Mathmatic - Probability */
#include<stdio.h>
#include<iostream>
#include<string>

void work(){
  int N, I;
  double p;

  cin >> N >> p >> I;

  double e;
  double probability = 0.0;
  double start, next;
  double pre;

  pre = 1;

  for ( int i = 1; i < I; i++ ) pre *= ( 1 - p );
  /* win in first step */
  probability = pre * p;
  
  /* lose in first step */
  start = 1;
  for ( int i = 1; i <= I; i++ ) start *= ( 1 - p );

  /* probability to lose in each turn */
  next = 1;
  for ( int i = 1; i <= N-1; i++ ) next *= ( 1 - p );

  int n = 1;
  e = start;
  while ( 1 ){
    e *= next;
    if ( e*p < 0.000001 ) break;
    probability += e*p;
    e *= (1-p);
    n++;
  }

  printf("%.4f\n", probability );
}

main(){
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    work();
  }
}
// @end_of_source_code
