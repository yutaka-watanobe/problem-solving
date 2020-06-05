#include<stdio.h>

int main(){
  int h1, h2, k1, k2, a, b, c, d, hiroshi, kenjiro;
  scanf("%d %d %d %d", &h1, &h2, &k1, &k2);
  scanf("%d %d %d %d", &a, &b, &c, &d);
  hiroshi = h1*a + h2*b + (h1/10)*c + (h2/20)*d;
  kenjiro = k1*a + k2*b + (k1/10)*c + (k2/20)*d;

  if ( hiroshi > kenjiro ) printf("hiroshi\n");
  else if ( hiroshi < kenjiro ) printf("kenjiro\n");
  else printf("even\n");

  return 0;
}
