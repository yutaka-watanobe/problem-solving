#include<stdio.h>

int main(){
  int N, A[101], B[101], C[101];
  int i, X, Y, Z, a, b, c, ans = 0;
  
  scanf("%d", &N);
  for ( i = 1; i <= N; i++ ) A[i] = B[i] = C[i] = 0;
	
  scanf("%d", &X);
  for ( i = 0; i < X; i++ ) { scanf("%d", &a); A[a] = 1; }
  scanf("%d", &Y);
  for ( i = 0; i < Y; i++ ) { scanf("%d", &b); B[b] = 1; }
  scanf("%d", &Z);
  for ( i = 0; i < Z; i++ ) { scanf("%d", &c); C[c] = 1; }

  for ( i = 1; i <= N; i++ ){
    if (!A[i] && C[i] || B[i] && C[i]) ans++;
  }

  printf("%d\n", ans);
  return 0;
}

