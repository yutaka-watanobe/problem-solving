#include<stdio.h>

int main(){
  int i, N, K, P;
  scanf("%d", &N);
  for ( i = 0; i < N; i++ ){    /* N 回繰り返す */
    scanf("%d %d", &K, &P);
    printf("%d\n", (K - 1) % P + 1);
  }
  return 0;
}
  
