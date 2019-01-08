#include<stdio.h>

int main(){
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  if ( a == b && c == d ||
       a == c && b == d ||
       a == d && b == c ) printf("yes\n");
  else printf("no\n");

  return 0;
}
