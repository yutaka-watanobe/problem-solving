// @JUDGE_ID:  17051CA  10170  C++
// @begin_of_source_code
/* Ingeger + mathematic */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
typedef unsigned long long ullong;

ullong S, D;

int read(){
  cin >> S >> D;
  if ( cin.eof() ) return 0;
  return 1;
}

void work(){
  cout << (ullong)( (sqrt( 1 + 8*D + 4*S*S - 4*S ) - 1 )/2.0 + 0.99999999) << endl;
}

main(){
  while( read() ) work();
}
// @end_of_source_code
