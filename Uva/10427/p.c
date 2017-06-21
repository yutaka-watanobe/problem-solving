// @JUDGE_ID:  17051CA  10427  C++
// @begin_of_source_code
/* Calculation */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<string>
#include<vector>
typedef unsigned long long ullong;

ullong N;
vector<ullong> M;

void init(){
  M.push_back( 0 );
  M.push_back( 1 );
  
  ullong current, next;
  next = 10;
  current = 1;
  int character = 1;
  int digit;
  while ( 1 ){
    digit = character * ( next - current );
    M.push_back( M.back() + digit );
    next *= 10;
    current *= 10;
    character += 1;
    if ( M.back() > 100000000L ) break;
  }
  
}

string ltoa( ullong x ){
  char a[20];
  sprintf( a, "%lld", x );
  return string( a );
}

void work(){
  /* exception */
  if ( N == 1 ){
    cout << 1 << endl;
    return ;
  }

  vector<ullong>::iterator pos;
  ullong start;
  
  pos = lower_bound( M.begin(), M.end(), N );
  pos--;
  start = *pos;
  
  int character = distance( M.begin(), pos );
  
  ullong difference;
  ullong adder;
  ullong width;

  width = N - start;
  difference =  ( width ) % character;
  adder = ( width - difference ) / character;

  /* cout << "character = " << character << endl; */
/*   cout << "start = " << start << endl; */
/*   cout << "difference = " << difference << endl; */
/*   cout << "adder = " << adder << endl; */

  ullong number = 1;
  
  for ( int i = 0; i < character - 1; i++ ) number *= 10;

  number += adder;

  string str = ltoa( number );

  cout << str[ difference ] << endl;
}

main(){
  init();
  while ( cin >> N ){
    work();
  }
}

// @end_of_source_code
