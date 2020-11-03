#include <stdio.h>

int main() {
  int i, N, x, xmin = 2000, xmax = 0;
  scanf("%d", &N);

  for ( i = 0; i < N; i++ ) {
    scanf("%d", &x);
    if ( x < xmin ) xmin = x;
    if ( x > xmax ) xmax = x;
  }

  printf("%d\n", xmax - (xmin + xmax) / 2);
  return 0;
}
