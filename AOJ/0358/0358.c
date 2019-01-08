#include<stdio.h>

int main(){
  int m, f, b;
  scanf("%d %d %d", &m, &f, &b);
  if ( m  + f < b ) printf("NA\n");
  else if ( m >= b ) printf("0\n");
  else printf("%d\n",  b - m);
  return 0;
}
