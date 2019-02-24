#include<stdio.h>

int main(){
  char D[][4] = {"thu", "fri", "sat", "sun", "mon", "tue", "wed"};
  int x;
  scanf("%d", &x);
  printf("%s\n", D[x%7]);
  return 0;
}
