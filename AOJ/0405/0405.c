#include<stdio.h>

int main(){
  int N;
  scanf("%d", &N);
  if ('A' <= N && N <= 'Z' ) printf("1\n");
  else if ( 'a' <= N && N <= 'z' ) printf("2\n");
  else printf("0\n");

  return 0;
}
