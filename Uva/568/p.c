// @JUDGE_ID:  17051CA  568  C++
// @begin_of_source_code
/* Calculation */
#include<stdio.h>
#include<iostream>
#include<string>

int T[10001];

void init(){
  
  int f = 1;
  int k;
  for ( int i = 1; i <= 10000; i++ ){
    k = i;
    while ( k % 10 == 0 ) k /= 10;
    f *= k;
    while ( f % 10 == 0 ) f /= 10;
    f %= 100000;
    T[i] = f % 10;
  }

}

int n;

int read(){
  cin >> n;
  if ( cin.eof() ) return 0;
  return 1;
}

void work(){
  printf("%5d", n );
  cout << " -> " << T[n] << endl;
}

main(){
  init();
  while ( read() ){
    work();
  }
}
// @end_of_source_code
