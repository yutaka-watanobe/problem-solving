// @JUDGE_ID:  17051CA  545  C++
// @begin_of_source_code
/* Mathmatic */
/* ケタ！！！ */
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#define MAX 9001

double T[MAX];

string line;

void work(){
  int n;
  int e;
  
  while ( 1 ){
    getline( cin, line );
    if ( line.size() == 0 || cin.eof() ) return ;
    n = atoi( line.c_str());
    e = (int)( n * log10( 2 ) + 1 );
    cout << "2^-" << n << " = ";

    if ( ((int)(T[n]*10000))%10 == 5 ) T[n] += 0.0001;

    printf("%.3f", T[n]);
    cout << "E-" << e << endl;
  }
}

void init(){
  double p = 1;
  T[0] = 1;
  for ( int i = 1; i < MAX; i++ ){
    p /= 2;
    while ( p < 1 ) p *= 10;
    T[i] = p;
  }
}

main(){
  init();
  int t;
  getline( cin, line );
  t = atoi( line.c_str() );
  getline( cin, line ); /* dammy */
  for ( int i = 0; i < t; i++ ){
    if ( i ) cout << endl;
    work();
  }
}
// @end_of_source_code
