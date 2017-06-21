// @JUDGE_ID:  17051CA  495  C
// @begin_of_source_code
#include<stdio.h>
main(){
  int i,j,n;
  int add, carry, idx;
  unsigned char fib[5001][1050];

  for(i=0 ; i<5001 ; i++){
    for(j=0 ; j<1050 ; j++){
      fib[i][j] = 0;
    }
  }

  add = 0;
  carry = 0;
  fib[0][0] = 0;
  fib[1][0] = 1;
  for(i=2 ; i<5001 ; i++){
    for(j=0 ; j<1050 ; j++){
      add = fib[i-1][j] + fib[i-2][j] + carry;
      carry = add/10;
      fib[i][j] = add%10;
    }
  }
  
  while( scanf("%d", &n) != EOF){
    if( n==0 ){
      printf("The Fibonacci number for 0 is 0\n");
    }else{
      printf("The Fibonacci number for %d is ", n);
    
      idx = 1049;
      while( fib[n][idx] == 0){
	idx--; 
	if( idx < 0 ) break;
      }
      for(i=idx ; i>=0 ; i--){
	printf("%d", fib[n][i]);
      }
      printf("\n");
    }
  }
  return 0;
}
// @end_of_source_code
