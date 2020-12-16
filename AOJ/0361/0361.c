#include<stdio.h>

int gcd(int x, int y){
  return y ? gcd(y, x % y) : x;
}

int main(){
  int x, y;
  scanf("%d %d", &x, &y);
  printf("%d\n", x + y - gcd(x, y) + 1);
  return 0;
}
