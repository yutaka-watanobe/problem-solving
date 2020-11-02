#include <stdio.h>
#include <string.h>

int main() {
  int i, L, N;
  char snake[101];
  long long oocnt = 0, total = 0;
  scanf("%d %d %s", &L, &N, snake);

  for ( i = 0; i < L - 1; i++ ) {
    if ( snake[i] == 'o' && snake[i + 1] == 'o' )
      ++oocnt;
  }
  
  for ( i = 0; i < N; i++ ) {
    total += oocnt;
    oocnt *= 2;
  }

  printf("%lld\n", 3 * total + L);
  return 0;
}
