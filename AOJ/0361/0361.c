#include<stdio.h>

int gcd(int x, int y){
  return y ? gcd(y, x % y) : x;
}

int main(){
  int x, y;
  scanf("%d %d", &x, &y);
  printf("%d\n", (x + 1) + (y + 1) - (gcd(x, y) - 1) - 2);
  return 0;
}
