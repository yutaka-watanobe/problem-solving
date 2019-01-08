#include<stdio.h>

int main(){
  int H, R; 
  scanf("%d %d", &H, &R);
  if ( H*(-1) == R ) printf("0\n");
  else if ( H*(-1) > R ) printf("-1\n");
  else if ( H*(-1) < R ) printf("1\n");

  return 0;
}

