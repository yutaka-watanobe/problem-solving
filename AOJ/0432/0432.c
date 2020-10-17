#include<stdio.h>
#include<string.h>

int N;
char G[1000][1001];

void rotate(){
  int i, j;
  char T[1000][1001];
  for ( i = 0; i < N; i++ ) strcpy(T[i], G[i]);
  for ( i = 0; i < N; i++ )
    for ( j = 0; j < N; j++ )
      G[j][N-i-1] = T[i][j];
}

int main(){
  int Q, i, q;
  int cnt = 4 * 100000;
  scanf("%d", &N);
  for ( i = 0; i < N; i++ ) scanf("%s", G[i]);
  scanf("%d", &Q);
  for ( i = 0; i < Q; i++ ){
    scanf("%d", &q);
    cnt += q;
  }
  cnt %= 4;
  for ( i = 0; i < cnt; i++ ) rotate();
  for ( i = 0; i < N; i++ ) printf("%s\n", G[i]);
  
  return 0;
}
