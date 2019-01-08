#include<stdio.h>

int main(){
  int c1, c5, c10, c50, c100, c500, sum;
  scanf("%d %d %d %d %d %d", &c1, &c5, &c10, &c50, &c100, &c500);

  sum = c1 + c5*5 + c10*10 + c50*50 + c100*100 + c500*500;

  if (sum >= 1000)  printf("1\n");
  else printf("0\n");

  return 0;
}
