#include<stdio.h>

int main(){
  int N, C, i, p, sum = 0;
  scanf("%d %d", &N, &C);
  N++;
  
  for ( i = 0; i < C; i++ ){
    scanf("%d", &p);
    sum += p;
  }

  printf("%d\n", sum / N + (sum % N == 0 ? 0 : 1));
  return 0;
}
