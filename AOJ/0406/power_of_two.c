#include <stdio.h>

int main() {
  int N, ans = 1;
  scanf("%d", &N);

  while ( ans <= N ) {
    ans *= 2;
  }

  printf("%d\n", ans / 2);
  return 0;
}
