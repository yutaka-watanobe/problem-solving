#include<stdio.h>

int main() {
  int n, k, res = 0, row = 1, w = 0;

  scanf("%d %d", &n, &k);

  while ( n >= row ) {
    if ( row * k >= w ) {
      ++res;
      w += row;
      n -= row;
    }
    else if ( n >= row + 1 ) ++row;
    else break;
  }
    
  printf("%d\n", res);
  return 0;
}
