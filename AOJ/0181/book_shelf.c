#include<stdio.h>

int m, n;
int w[100];

int isStorable(int width) {
  int row = 0, c = 0, i = 0;
  while ( i < n ) {
    if ( c + w[i] <= width ) {
      c += w[i];
      ++i;
    }
    else if ( ++row < m ) c = 0;
    else return 0;
  }
  return 1;
}

int main() {
  int i, minw, maxw, mid;

  while ( scanf("%d %d", &m, &n) == 2 && m && n ) {

    for ( i = 0; i < n; ++i ) scanf("%d", &w[i]);

    minw = 1;
    maxw = 1500000;
    if ( !isStorable(maxw) ) printf("NA\n");

    while ( maxw > minw ) {
      mid = (maxw + minw) / 2;
      if ( isStorable(mid) ) maxw = mid;
      else                   minw = mid + 1;
    }

    printf("%d\n", minw);
  }
  return 0;
}
