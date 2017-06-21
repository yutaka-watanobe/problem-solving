// @JUDGE_ID:  17051CA  10038  C++
// @begin_of_source_code
#include<stdio.h> 
#include<iostream.h>
#include<math.h>

main(){
  
  int n;
  long x;
  long before;
  int notJ;
  while( scanf("%d", &n) != EOF){
    
    int i=0;
    notJ = 0;
    for(i=0; i<n; i++){
      scanf("%ld", &x);
      if(i != 0 ){
	long def = abs(x - before);
	/*printf("%d ", def);*/
	if( 1 <= def && def <= n-1 ){
	  /*printf("ok ");*/
	}else{
	  notJ = 1;
	  /*printf("no ");*/
	}
      }
      before = x;
    }

    if( notJ == 1 ){
      cout << "Not jolly" << endl;
    }else{
      cout << "Jolly" << endl;
    }

  }
  
  return 0;
}
// @end_of_source_code
