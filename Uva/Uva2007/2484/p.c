// @JUDGE_ID:  17051CA  2484  C++
// @begin_of_source_code
/* 総計 N 個の数字でつくられている本は何ページあるか */
/* 1234567891011121314... まで何個の数字があるかの逆！ */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#include<string>
typedef long long llong;

vector<llong> ST; /* start table */
llong OS[ 11 ]; /* original start tabe */
llong N;

llong compute(){
  vector<llong>::iterator pos;
  pos = upper_bound( ST.begin(), ST.end(), N );
  pos--;
  llong start = *pos;
  llong delta = N - start;

  int digit = distance( ST.begin(), pos ) + 1;

  if ( ( delta + 1 ) % digit != 0 ) return -1;
  
  return OS[ digit ] + delta / digit;

}

void work(){
  llong ans;
  ans = compute();
  if ( ans ==-1  ) cout << "Impossible!" << endl;
  else cout << ans << endl;
}

bool read(){
  string line;
  cin >> line;
  if ( line == "#" ) return false;
  N = atoi ( line.c_str() );
  return true;
}

void init(){
  ST.resize( 11 );
  llong sum = 0;
  llong p = 1;
  int digit = 1;
  ST[ 0 ] = 1;
  OS[ 0 ] = 0;
  for ( int i = 1; i < 11; i++ ){
    sum += ( 10*p - p ) * digit;
    ST[ i ] = sum + 1;
    OS[ i ] = p;
    digit++;
    p *= 10;
  }
}

main(){
  init();
  while ( read() ){
    work();
  }
}

// @end_of_source_code
