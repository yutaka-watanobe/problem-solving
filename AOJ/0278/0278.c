#include <stdio.h>

int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a > b ? a : b; }

int main() {
  int N, x, y, b, p, i;
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d %d %d %d", &x, &y, &b, &p);
    printf("%d\n", min(x*b+y*p, (x*max(b,5)+y*max(p,2))*4/5) );
  }
  return 0;
}
