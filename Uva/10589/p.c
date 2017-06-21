// @JUDGE_ID:  17051CA  10589  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
main(){
  int N;
  double  A, AA, x, y;
  int M;

  while( scanf("%d %lf", &N, &A) ){
    if ( N == 0 && A == 0 ) break;
    AA = A*A;
    M = 0;
    for ( int i = 0; i < N; i++ ){
      scanf("%lf %lf", &x, &y);
      if ( ( x*x + y*y < AA ) &&
	   ( (x-A)*(x-A) + y*y < AA ) &&
	   ( (x-A)*(x-A) + (y-A)*(y-A) < AA ) &&
	   ( x*x + (y-A)*(y-A) < AA ) ) M++;
    }
    printf("%.5lf\n", M*A*A/N);
  }

}

// @end_of_source_code


