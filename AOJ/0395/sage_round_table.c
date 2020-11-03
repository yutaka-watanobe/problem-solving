#include<stdio.h>
#define INF 100000

int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a > b ? a : b; }

int main() {
  int i, N;
  int a[10], w;
  int lmin = INF;
  int rmin = INF;

  scanf("%d", &N);
  for ( i = 0; i < N; ++i ) scanf("%d", &a[i]);

  for ( i = 0; i < N; ++i ) {
    scanf("%d", &w);
    if ( a[i] ) rmin = min(rmin, w);
    else lmin = min(lmin, w);
  }
    
  if ( rmin == INF || lmin == INF ) printf("0\n");
  else printf("%d\n", rmin + lmin);
  return 0;
}
