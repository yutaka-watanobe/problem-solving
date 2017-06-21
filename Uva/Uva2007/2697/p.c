// @JUDGE_ID:  17051CA  2697   C++
// @begin_of_source_code
/* Log10 */
#include<stdio.h>
#include<iostream>
#include<cmath>
typedef long long llong;

void work(){
  double sum = 0;
  llong n;
  scanf( "%lld", &n );
  for ( int i = 1; i <= n; i++ ){
    sum += log10 ( i );
  }
  printf( "%d\n", (int)sum + 1 );
}

main(){
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    work();
  }
}

// @end_of_source_code


