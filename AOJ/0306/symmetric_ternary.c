#include<stdio.h>

int main() {
  int w, i, r, k = 0;
  char res[20];
  scanf("%d", &w);

  while ( w > 0 ) {
    r = w % 3;
    if ( r == 0 ){
      res[k++] = '0';
      w /= 3;
    } else if ( r == 1 ){
      res[k++] = '+';
      w /= 3;
    } else if ( r == 2 ){
      res[k++] = '-';
      w = w / 3 + 1;
    }
  }
  for ( i = k - 1; i >= 0; i-- ) printf("%c", res[i]);
  printf("\n");
  return 0;
}
