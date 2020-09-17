#include<stdio.h>

int main(){
  char D[][4] = {"thu", "fri", "sat", "sun", "mon", "tue", "wed"}; /* 曜日を表す配列 */
  int X;
  scanf("%d", &X);
  printf("%s\n", D[X % 7]); /* 7で割った余りから曜日を求めてその文字列を出力 */
  return 0;
}
