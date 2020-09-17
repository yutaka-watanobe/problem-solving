#include<stdio.h>

int calcID(int r, int t) { return r + 5 * t; }

int main() {
  int i, n, r, t, onR, onT;
  scanf("%d", &n);
  for ( i = 0; i < n; ++i ) {
    scanf("%d %d", &r, &t);
    onR = r % 100 == 0;
    onT = t % 30 == 0;
    r /= 100;
    t /= 30;
    if ( onR && onT ) printf("%d\n", calcID(r, t));
    else if ( onR ) printf("%d %d\n", calcID(r, t), calcID(r, t + 1));
    else if ( onT ) printf("%d %d\n", calcID(r, t), calcID(r + 1, t));
    else {
      printf("%d %d %d %d\n", calcID(r, t), 
             calcID(r + 1, t), calcID(r, t + 1), calcID(r + 1, t + 1));
    }
  }

  return 0;
}
