// @JUDGE_ID:  17051CA  374  C++
// @begin_of_source_code
/* Number Theory */
/* B^p mod M */
/* See "Introduction to Number Theory" page 100 */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
typedef long long llong;

llong B, P, M;

int read(){
  cin >> B >> P >> M;
  if ( cin.eof() ) return 0;
  return 1;
}

void work(){
  int b = 1;
  
  while ( P >= 1 ){
    if ( P%2 != 0 ) b = B*b % M;
    B = B*B % M;
    P = P/2;
  }

  cout << b << endl;

}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
