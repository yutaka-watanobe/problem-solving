// @JUDGE_ID:  17051CA  591  C++
// @begin_of_source_code
#include<stdio.h>
main(){
  int n;
  int brick[51];
  int total, height, count;
  int set = 0;
  while(1){
    scanf("%d", &n);
    if( n == 0 ) return 0;
    set++;
    total = 0;
    count = 0;
    for(int i=1 ; i<=n ; i++){
      scanf("%d", &brick[i]);
      total = total + brick[i];
    }
    height = total / n;
    for(int i=1 ; i<=n ; i++){
      while( brick[i] > height ){
	brick[i]--;
	for(int j=1 ; j<=n ; j++){
	  if( brick[j] < height ){
	    brick[j]++;
	    count++;
	  }
	}
      }
    }
    printf("Set #%d\n", set);
    printf("The minimum number of moves is %d.\n", count);
  }
  
  return 0;
}
// @end_of_source_code
