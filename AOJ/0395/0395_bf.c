#include<stdio.h>
#define N_MAX 10
int N, a[N_MAX], w[N_MAX], ans;
int table[N_MAX]; /* 座席表 */
int sat[N_MAX];   /* 座ったかどうか */

void rec(int p){
  int sum, i;
  if ( p == N ){
    sum = 0;
    for ( i = 0; i < N; i++ ){
      if ( a[table[i]] == 0 && a[table[(i - 1 + N) % N]] == 1 ||
	   a[table[i]] == 1 && a[table[(i + 1) % N]] == 0 )
	sum += w[table[i]];
    }
    if ( sum < ans ) ans = sum;
    return;
  }
  for ( i = 0; i < N; i++ ){
    if ( sat[i] ) continue;
    sat[i] = 1;
    table[p] = i;
    rec(p + 1);
    sat[i] = 0;
  }
}

int main() {
  int i;
  scanf("%d", &N);
  for ( i = 0; i < N; i++ ) scanf("%d", &a[i]);
  for ( i = 0; i < N; i++ ) scanf("%d", &w[i]);
  ans = 1000 * N;
  rec(0);
  printf("%d\n", ans);
  return 0;
}

