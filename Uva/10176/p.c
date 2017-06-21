// @JUDGE_ID:  17051CA  10176  C++
// @begin_of_source_code
/* Number */
/* 131071 の世界にしてしまえばよい */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define P 131071

string bit;

int read(){
  bit = "";
  char ch;
  while( 1 ){
    cin >> ch;
    if ( cin.eof() ) return 0;
    if ( ch == '#' ) break;
    bit += ch;
  }

  reverse( bit.begin(), bit.end() );
  return 1;
}

void work(){
  int value, pow;
  value = 0;
  pow = 1;

  for ( int i = 0; i < bit.size(); i++ ){
    if ( bit[i] == '1' ) value = ( value + pow ) % P;
    pow = ( pow * 2 ) % P;
  }

  if ( value % P == 0 ) cout << "YES" << endl;
  else cout << "NO" << endl;
}

main(){
  while ( read() ) work();
}
// @end_of_source_code
