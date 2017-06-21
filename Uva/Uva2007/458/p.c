// @JUDGE_ID:  17051CA  458  C++
// @begin_of_source_code
#include<stdio.h>
main(){
  
  int sub = 'C' - 'J';
  char c;

  while( scanf("%c", &c) != EOF){
    if( c == '\n') printf("\n");
    else printf("%c", c + sub );
  }
  
  return 0;
}
// @end_of_source_code
