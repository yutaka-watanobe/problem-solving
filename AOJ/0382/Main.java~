#include<stdio.h>

int main(){
  int N, C, i, x, sum = 0;
  scanf("%d %d", &N, &C);

  for ( i = 0; i < C; i++ ){
    scanf("%d", &x);
    sum += x;
  }
  N++;

  printf("%d\n", sum/N + (sum%N==0?0:1));

  return 0;
}
