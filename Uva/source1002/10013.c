// @JUDGE_ID:  17051CA  10013  C++
// @begin_of_source_code
#include<stdio.h>
#include<stdlib.h>

main(){

  int n,  k, i, j;
  long m;
  int *a1, *a2, *v;
  scanf("%d", &n);
  for(k=0 ; k < n ; k++){
    scanf("%ld", &m);
    a1 = (int *)malloc(m*sizeof(int));
    a2 = (int *)malloc(m*sizeof(int));
    v = (int *)malloc(m*sizeof(int));
    for(j=m-1 ; j >= 0 ; j--){
      scanf("%d %d", &a1[j], &a2[j]);
    }
    int sum = 0;
    int carry = 0;
    for( i = 0 ; i < m ; i++){
      sum = a1[i] + a2[i] + carry;
      carry = 0;
      carry = sum/10;
      if( carry == 0 ) v[i] = sum;
      else v[i] = sum%10;
    }
    for( i = m-1 ; i >= 0 ; i--){
      printf("%d", v[i]);
    }
    free( v );
    free( a1 );
    free( a2 );
    printf("\n");
    if( k != n-1) printf("\n");
  }
  return 0;
}
// @end_of_source_code
