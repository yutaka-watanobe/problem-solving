// @JUDGE_ID:  17051CA  424  C++
// @begin_of_source_code
#include<stdio.h>
#include<string>
#include<stdlib.h>

main(){
  int line[102];
  char tmp[102];
  int ans[102];

  for(int i=0 ; i<102 ; i++){
    ans[i] = 0;
  }

  int i, j, n;
  char c;
  j=0;
  while( scanf("%c", &c ) != EOF){
    char cc[0];
    cc[0] = c;
    tmp[j] = atoi( cc );
    
    if( c == '\n' ){
      for(int a=0 ; a<102 ; a++){
	if( a > j) line[a] = 0;
	else line[a] = tmp[j-a-1];
      }
      /* add */
      int carry = 0;
      int add = 0;
      for(int k=0 ; k<102 ; k++){
	add = ans[k] + line[k] + carry;
	carry = add/10;
	ans[k] = add%10;
      }
      j = 0;
    }else{
      j++;
    }
  }

  int s=101;
  while( ans[s] == 0 ){
    s--;
  }
  for(int i=s ; i>=0 ; i--){
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
// @end_of_source_code
