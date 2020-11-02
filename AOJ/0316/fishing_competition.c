#include<stdio.h>

int getScore(int iwa, int yam,
	     int a, int b, int c, int d) {
  return iwa * a + yam * b +
    (iwa / 10) * c + (yam / 20) * d;  
}
		
int main() {
  int h1, h2, k1, k2, hiro, ken;
  int a, b, c, d;
  scanf("%d %d %d %d", &h1, &h2, &k1, &k2);
  scanf("%d %d %d %d", &a, &b, &c, &d);

  hiro = getScore(h1, h2, a, b, c, d);
  ken = getScore(k1, k2, a, b, c, d);

  if      ( hiro > ken ) printf("hiroshi\n");
  else if ( hiro < ken ) printf("kenjiro\n");
  else printf("even\n");

  return 0;
}
