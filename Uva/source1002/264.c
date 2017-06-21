// @JUDGE_ID:  17051CA  264  C++
// @begin_of_source_code
#include<stdio.h>
main(){
  
  long x, y;
  int i, n;
  int state;
  while( (scanf("%d", &n)) != EOF){
    i = 1;
    x = 1; y = 1; state = 1;
    while(1){
      if(i==n) break;
      if(state==2){
	x++; y--;
	if(y==1) state = 3;
      }else if(state==4){
	x--; y++;
	if(x==1) state=1;
      }else if(state==1) {
	y++; 
	state = 2;
      }else if(state==3){
	x++;
	state = 4;
      }
      i++;
    }
    printf("TERM %d IS %d/%d\n", n, x, y);
  }
  return 0;
}
// @end_of_source_code

