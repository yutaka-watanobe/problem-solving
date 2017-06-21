#include<stdio.h>

int main(){
  int total, sum, x, i;
  while( scanf("%d", &total) && total ){
    sum = 0;
    for ( i = 1; i < 10; i++ ){
      scanf("%d", &x);
      sum += x;
    }
    printf("%d\n", total - sum);
  }
  return 0;
}
