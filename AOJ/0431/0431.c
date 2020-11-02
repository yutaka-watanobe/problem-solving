#include<stdio.h>

int main(){
  int i;
  int N, r[1000];  /* 1000個の円盤の半径を記録できる配列 */
  int maxr = 0, cnt = 0;
  scanf("%d", &N);
  for ( i = 0; i < N; i++ ) scanf("%d", &r[i]);
  for ( i = N - 1; i >= 0; i-- ){
    if ( r[i] > maxr ) {
      cnt++;
      maxr = r[i];
    }
  }
  printf("%d\n", cnt);
  return 0;
}
