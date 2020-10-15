#include<stdio.h>

int main(){
  int N, A[1000], i;
  int maxr = 0, cnt = 0;
  scanf("%d", &N);
  for ( i = 0; i < N; i++ ) scanf("%d", &A[i]);
  for ( i = N - 1; i >= 0; i-- ){
    if ( A[i] > maxr ) cnt++;
    maxr = ( A[i] > maxr ? A[i] : maxr);
  }
  printf("%d\n", cnt);
  return 0;
}
