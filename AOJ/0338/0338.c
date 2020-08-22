#include<stdio.h>

int gcd(int a, int b){
  if ( b == 0 ) return a;
  return gcd(b, a % b);
}

int main(){
  int W, H, C;
  scanf("%d %d %d", &W, &H, &C);
  printf("%d'n", (W / gcd(W, H)) * (H / gcd(W, H)) * C);
  return 0;
}
