#include <stdio.h>
#define MAX 5000
int max(int a, int b){ return a > b ? a : b; }
int min(int a, int b){ return a < b ? a : b; }

int main() {
  int N, p[MAX], r[MAX];
  scanf("%d", &N);
  for(int i = 0; i < N; i++ ) scanf("%d", &p[i]);
  int ans = (1<<29);
  
  for(int j = 0; j <= p[0]; j++) {
    int x = j;
    for(int i = 0; i < N; i++) r[i] = p[i];
    r[0] -= j;
    for(int i = 0; i < N - 1; i++) {
      int y = max(0, r[i]);
      r[i] -= y;
      r[i+1] -= y;
      x += y*2;
    }
    ans = min(ans, x + max(0, r[N-1]));
  }

  printf("%d\n", ans);
  
  return 0;
}
