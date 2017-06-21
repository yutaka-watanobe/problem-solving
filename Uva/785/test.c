#include<stdio.h>

main(){
  char c;
  while(1){
    if(scanf("%c", &c) == EOF )return 0;
    if( c == '_') printf("Y");
    else printf("%c", c);
  }

}
