#include<stdio.h>

int main(){
  int d;
  scanf("%d", &d);

  printf("%d ",  d / 3600);
  printf("%d ",  d % 3600 / 60);
  printf("%d\n", d % 60);

  return 0;
}
