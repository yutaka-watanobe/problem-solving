#include<stdio.h>

int main() {
  int i, j, N, R, T;
  int p[100], filled[1000];
  int res = 0;

  scanf("%d %d %d", &N, &R, &T);
  for ( i = 0; i < N; i++ ) scanf("%d", &p[i]);
  for ( i = 0; i < R; i++ ) filled[i] = 0;

  for ( i = 1; i <= T; i++ ) {
    for ( j = 0; j < N; j++ ) {
      if ( filled[(p[j] * i) % R] <= 0 ) ++res;
      else --filled[(p[j] * i) % R];
    }

    if ( i > 1 ) {
      for ( j = 0; j < N; j++ ) ++filled[(p[j] * i) % R];
    }
  }

  printf("%d\n", res);
  return 0;
}
