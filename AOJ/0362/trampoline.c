#include<stdio.h>

int N;
int d[300000];

int isReachable() {
  int i, current = 0;
  for ( i = 0; i < N; ++i ) {
    if ( current < 10 * i ) return 0;
    if ( current < 10 * i + d[i] ) current = 10 * i + d[i];
    if ( current >= 10 * N ) return 1;
  }
  return 0;
}

int main() {
  int i;
  scanf("%d", &N);
  for ( i = 0; i < N; i++ ) scanf("%d", &d[i]);
  if ( !isReachable() ) {
    printf("no\n");
    return 0;
  }
    
  for ( i = 0; i < N / 2; i++ ) { /* 列の要素を逆順に変換する */
    int tmp = d[i];
    d[i] = d[N - i - 1];
    d[N - i - 1] = tmp;
  }
  if ( !isReachable() ) printf("no\n");
  else printf("yes\n");
    
  return 0;
}
