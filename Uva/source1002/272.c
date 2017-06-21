// @JUDGE_ID:  17051CA  272  C++
// @begin_of_source_code
#include<stdio.h>
main(){
  char c;
  int isFirst;
  isFirst = 1;
  while( scanf("%c", &c) != EOF ){
    if( c == '"' ){
      if(isFirst){
	printf("%c%c", '`', '`');
	isFirst = 0;
      }else{
	printf("%c%c", '\'', '\'');
	isFirst = 1;
      }
    }else{
      printf("%c", c);
    }
  }
  return 0;
}
// @end_of_source_code
