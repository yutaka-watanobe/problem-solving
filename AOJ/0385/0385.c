#include <stdio.h>
#define INF 2000000000
int N, A[300002], diff;

void update(int i, int v){
  if ( A[i - 1] > A[i] ) diff--;
  if ( A[i] > A[i + 1] ) diff--;
  A[i] = v;
  if ( A[i - 1] > A[i] ) diff++;
  if ( A[i] > A[i + 1] ) diff++;
}

int sort(){
  int Q, x, y, v1, v2, i;
  diff = 0;
  for ( i = 1; i <= N; i++ ) 
    if ( A[i - 1] > A[i] ) diff++;

  if ( diff == 0 ) return 0;

  scanf("%d", &Q);
  for ( i = 1; i <= Q; i++ ){
    scanf("%d %d", &x, &y);
    v1 = A[x];
    v2 = A[y];
    update(x, v2);
    update(y, v1);
    if ( diff == 0 ) return i;
  }

  return -1;
}

int main() {
  int i;
  scanf("%d", &N);
  for ( i = 1; i <= N; i++ ) scanf("%d", &A[i]);
  A[0] = -INF;
  A[N + 1] = INF;
  printf("%d\n", sort());
  return 0;
}

