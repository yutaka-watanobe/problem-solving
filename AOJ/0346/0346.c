#include<stdio.h>
#define N 12
int e[N];

int check(){
  for ( int i = 0; i < N - 1; i++ ){
    int minj = i;
    for ( int j = i; j < N; j++ )
      if ( e[j] < e[minj] ) minj = j;
    int t = e[minj];
    e[minj] = e[i];
    e[i] = t;
  }
  
  for ( int i = 0; i < N; i += 4)
    if ( e[i] != e[i+3] ) return 0;
  return 1;
}

int main(){
  for ( int i = 0; i < N; i++ ) scanf("%d", &e[i]);
  printf(check() ? "yes\n": "no\n");
  return 0;
}
