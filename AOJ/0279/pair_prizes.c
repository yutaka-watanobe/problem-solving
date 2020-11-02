#include<stdio.h>

int main() {
  int i, N, k, less1Cnt, zeroCnt;
  
  while ( 1 ) { /*  無限ループ */
    scanf("%d", &N);
    if ( N == 0 ) break; /* データセットの終わり  */
    less1Cnt = zeroCnt = 0;
    for ( i = 0; i < N; ++i ) {
      scanf("%d", &k);
      if ( k <= 1 ) ++less1Cnt;
      if ( k == 0 ) ++zeroCnt;
    }
    if ( N == less1Cnt ) printf("NA\n");
    else printf("%d\n", N - zeroCnt + 1);
  }

  return 0;
}
