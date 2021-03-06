#include<stdio.h>
#define N 12
int e[N];

int check(){
  int i, j, minj, t;
  /* 選択ソート */
  for ( i = 0; i < N - 1; i++ ){
    minj = i;
    for ( j = i + 1; j < N; j++ )
      if ( e[j] < e[minj] ) minj = j;
    t = e[minj];
    e[minj] = e[i];
    e[i] = t;
  }
  
  for ( i = 0; i < N; i += 4)
    if ( e[i] != e[i + 3] ) return 0;
  return 1;
}

int main(){
  int i;
  for ( i = 0; i < N; i++ ) scanf("%d", &e[i]);
  printf(check() ? "yes\n": "no\n");
  return 0;
}
