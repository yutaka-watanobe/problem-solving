#include<stdio.h>

int main() {
  int i, n, k, less1Cnt, zeroCnt;
  
  while ( 1 ) {
    scanf("%d", &n);
    if ( n == 0 ) break;
    less1Cnt = zeroCnt = 0;
    for ( i = 0; i < n; ++i ) {
      scanf("%d", &k);
      if ( k <= 1 ) ++less1Cnt;
      if ( k == 0 ) ++zeroCnt;
    }
    if ( n == less1Cnt ) printf("NA\n");
    else printf("%d\n", n - zeroCnt + 1);
  }

  return 0;
}
