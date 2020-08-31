#include<stdio.h>

int main() {
  int n, t[100000], p[10000], cnt = 0;
  scanf("%d", &n);
  int maxv = 0;
  for( int i = 0; i < n; i++ ) {
    scanf("%d", &t[i]);
    if ( t[i] > maxv ) maxv = t[i];
  }
  
  for ( int i = 1; i <= maxv; i++ )
    if ( maxv % i == 0 ) p[cnt++] = i;
  
  long long ans = 0;
  for( int i = 0; i < n; i++ ) {
    for ( int j = 0;; j++ ){
      if ( p[j] >= t[i] ){
	ans += p[j] - t[i];
	break;
      }
    }
  }
  printf("%lld\n", ans);

  return 0;
}
