// @JUDGE_ID:  17051CA  100  C++
// @begin_of_source_code
#include<stdio.h>
#include<algorithm>

int i, j;

int compute(int n){

  int sum = 0;

  while ( 1 ){
    sum++;
    if ( n == 1 ) return sum;
    if ( n % 2 == 0 ) n = n/2;
    else n = 3*n + 1;
  }

}

void work(){

  int start = min( i, j );
  int end = max( i, j );

  int maxLength = 0;

  for ( int current = start; current <= end; current++ ){
    maxLength = max( maxLength, compute(current) );
  }

  printf("%d %d %d\n", i, j, maxLength);

}

main(){
  while ( scanf("%d %d", &i, &j) != EOF ){
    work();
  }
}

// @end_of_source_code


