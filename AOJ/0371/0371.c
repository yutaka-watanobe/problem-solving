#include<stdio.h>

int main() {
  int n, t[100000], divisors[10000];
  int maxt = 0, cnt = 0;
  scanf("%d", &n);


  for( int i = 0; i < n; i++ ) {
    scanf("%d", &t[i]);
    /* 間隔が一番長いmaxtを更新 */
    if ( t[i] > maxt ) maxt = t[i];
  }
  /* maxtの約数を昇順に列挙 */
  for ( int i = 1; i <= maxt; i++ )
    if ( maxt % i == 0 ) divisors[cnt++] = i;
  
  long long ans = 0;
  for( int i = 0; i < n; i++ ) {
    /* tを増やしたときに最初に一致する
       maxtの約数を線形探索 */
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
