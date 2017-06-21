// kasu
#include<stdio.h>

main(){
  int x;

  while ( 1 ){
    scanf("%d", &x);
    if ( x == 0 ) break;
    
    if ( x <= 101 ) printf("f91(%d) = %d\n", x, 91);
    else printf("f91(%d) = %d\n", x, x - 10);
  }
}
