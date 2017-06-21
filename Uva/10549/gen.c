#include<stdio.h>

main(){
  printf("100\n");
  for ( int i = 0; i < 100; i++ ){
    printf("%d %d %d\n", 200 - i*2, 200 - i*2, 1 );
  }
printf("0\n");
}
