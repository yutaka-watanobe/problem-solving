#include<stdio.h>

int main(){
  int i, b, st = 0;
  for ( i = 0; i < 3; i++ ){
    scanf("%d", &b);
    if ( b == 1 ) st += (1<<i);
  }
  if ( st >= 3 ) printf("Open\n");
  else printf("Close\n");
  return 0;
}
