// @JUDGE_ID:  17051CA  2362  C++
// @begin_of_source_code
/* Simplest Calculation */
#include<stdio.h>
#include<iostream>
#include<stl.h>

main(){
  double d;
  double sum;
  int cnt = 0;
  while ( cin >> d ){
    sum += d;
    cnt++;
  }

  assert( cnt == 12 );

  printf("$%.2lf\n", sum / cnt );
}
// @end_of_source_code
