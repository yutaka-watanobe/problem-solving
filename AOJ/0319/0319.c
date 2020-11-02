#include<stdio.h>

int main(){
  int N, i, j, tmp, ans; 
  int p[101];
  scanf("%d", &N);
  for ( i = 0; i < N; i++ ) scanf("%d", &p[i]);

  /* バブルソート（降順） */
  for ( i = 0; i < N - 2; i++ )
    for ( j = N - 2; j >= i; j-- )
      if ( p[j] < p[j + 1] ){
	tmp = p[j]; p[j] = p[j + 1]; p[j + 1] = tmp;
      }
  
  ans = 0;
  for ( i = 0; i < N; i++ ){
    if ( p[i] >= i + 1 ) ans = i + 1;
  }

  printf("%d\n", ans);
  return 0;
}

