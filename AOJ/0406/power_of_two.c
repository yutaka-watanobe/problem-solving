#include <stdio.h>

int main() {
  int N, p = 0;
  scanf("%d", &N);

  while ( N > 1 ) {
    N >>= 1;
    ++p;
  }

  printf("%d\n", 1 << p);
  return 0;
}
