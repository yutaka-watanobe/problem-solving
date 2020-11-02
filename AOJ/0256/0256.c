#include<stdio.h>

int main(){
  int i = 0, s, total = 0;
  while ( i < 10 ) {           /* 繰り返し処理の範囲始まり */
    scanf("%d", &s);
    total += s;
    i++;
  }                            /* 繰り返し処理の範囲終わり */
  printf("%d\n", total);
  return 0;
}
 
