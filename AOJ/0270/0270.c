#include<stdio.h>
#define MAX 300000

int T[MAX+1], L[MAX+1];

int main(){
  int N, Q, q, x, i, m, maxv, cur, p;

  scanf("%d %d", &N, &Q);

  for ( i = 0; i < N; i++ ) {
    scanf("%d", &x);
    T[x] = 1;
  }

  m = 0;
  for ( i = 1; i <= MAX; i++ ){
    L[i] = m;
    if ( T[i] ) m = i;
  }

  for ( i = 0; i < Q; i++ ){
    scanf("%d", &q);
    maxv = 0;
    cur = m;
    while(cur){
      p = cur % q;
      maxv = (maxv > p ? maxv : p);
      if ( cur - p < 0 ) break;
      cur = L[cur - p];
    }
    printf("%d\n", maxv);
  }

  return 0;
}
