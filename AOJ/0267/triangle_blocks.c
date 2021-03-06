#include<stdio.h>
#define MAX_CNT 10000

int b[MAX_CNT], tmp[MAX_CNT];

int main() {
  int i, N, m, cnt, isTriangle;
  
  while ( scanf("%d", &N) == 1 && N != 0 ) {
    for ( i = 0; i < N; i++ ) scanf("%d", &b[i]);
    cnt = 0;
    while ( cnt <= MAX_CNT ) {
      /* 三角形になっているかを判定する */
      isTriangle = 1; 
      if ( b[0] != 1 ) isTriangle = 0;
      for ( i = 1; i < N; i++ ) {
        if ( b[i] != b[i - 1] + 1 ) {
          isTriangle = 0;
          break;
        }
      }
      if ( isTriangle ) break;
      /* ブロックの数が１より多い列で新しい列を作る */
      m = 0; 
      for ( i = 0; i < N; i++ ) 
        if ( b[i] > 1 )  tmp[m++] = b[i] - 1;
      for ( i = 0; i < m; i++ ) b[i] = tmp[i];
      b[m] = N;

      N = m + 1;
      ++cnt;
    }

    if ( cnt > MAX_CNT ) printf("-1\n");
    else printf("%d\n", cnt);
  }

  return 0;
}
