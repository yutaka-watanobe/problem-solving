// 1051: Citation Format
#include<stdio.h>
#define MAX 101

main(){
  int n, A[MAX], i, pre, cnt;
  while(1){
    scanf("%d", &n);
    if ( n == 0 ) break;
    for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
    A[n] = 1000;
    pre = A[0];

    printf("%d", A[0]);
    for ( i = 1, cnt = 0; i <= n; pre = A[i++] ){
      if ( pre == A[i]-1 ) { 
	cnt++;
      } else {
	if ( cnt ) printf("-%d", pre);
	if ( i != n ) printf(" %d", A[i]);
	cnt = 0;
      }
    }
    printf("\n");
  }
}
