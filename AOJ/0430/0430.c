#include<stdio.h>

int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a > b ? a : b; }

int main(){
  int N, x, d, R, L, i, minv, maxv;
  scanf("%d %d", &N, &x);
  R = L = x;
  for ( i = 0; i < N; i++ ){
    scanf("%d", &d);
    R = max(R, d);
    L = min(L, d);
  }
  minv = min(R - x, x - L);
  maxv = max(R - x, x - L);
  printf("%d\n", minv * 2 + maxv);
  return 0;
}
