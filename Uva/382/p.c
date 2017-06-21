// @JUDGE_ID:  17051CA  382  C++
// @begin_of_source_code
#include<stdio.h>
main(){
  int n;
  long sum;
  printf("PERFECTION OUTPUT\n");
  while( scanf("%d", &n) ){
    if( n==0 ) break;
    
    sum = 0;
    for(int i=1; i<n; i++){
      if( n%i==0 ){
	sum = sum + i;
      }
    }
    
    if(sum == n) printf("%5d  PERFECT\n", n);
    if(sum < n) printf("%5d  DEFICIENT\n", n);
    if(sum > n) printf("%5d  ABUNDANT\n", n);
  }
  printf("END OF OUTPUT\n");
  return 0;
}
// @end_of_source_code
