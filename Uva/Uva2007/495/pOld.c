// @JUDGE_ID:  17051CA  495  C++
// @begin_of_source_code
#include<stdio.h>
main(){
  int n;
  int fib[1050];
  int tmp1[1050];
  int tmp2[1050];

  while( scanf("%d", &n) != EOF){
    if( n==0 ){
      printf("The Fibonacci number for 0 is 0\n");
    }else if(n==1){
      printf("The Fibonacci number for 1 is 1\n");
    }else{
      printf("The Fibonacci number for %d is ", n);
      
      for(int i=0 ; i<1050 ; i++){
	fib[i] = 0;
	tmp1[i] = 0;
	tmp2[i] = 0;
      }
      
      int add, carry;
      tmp1[0] = 0;
      tmp2[0] = 1;
      for(int i=0 ; i<n-1 ; i++){
	add = 0;
	carry = 0;
	for(int j=0 ; j<1050 ; j++){
	  add = tmp1[j] + tmp2[j] + carry;
	  carry = add/10;
	  fib[j] = add%10;
	}
	tmp1 = tmp2;
	tmp2 = fib;
      }
      
      int idx = 1049;
      while( fib[idx] == 0){
	idx--;
      }
      
      for(int i=idx ; i>=0 ; i--){
	printf("%d", fib[i]);
      }
      printf("\n");
      
    }
  }
  return 0;
}
// @end_of_source_code
