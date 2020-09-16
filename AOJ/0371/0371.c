#include<stdio.h>

int main() {
  int n, t[100000], divisors[10000], cnt = 0;
  scanf("%d", &n);
  int maxt = 0;
  for( int i = 0; i < n; i++ ) {
    scanf("%d", &t[i]);
    if ( t[i] > maxt ) maxt = t[i];
  }
  
  for ( int i = 1; i <= maxt; i++ )
    if ( maxt % i == 0 ) divisors[cnt++] = i;
  
  long long ans = 0;
  for( int i = 0; i < n; i++ ) {
    for ( int j = 0;; j++ ){
      if ( divisors[j] >= t[i] ){
	ans += divisors[j] - t[i];
	break;
      }
    }
  }
  printf("%lld\n", ans);

  return 0;
}
