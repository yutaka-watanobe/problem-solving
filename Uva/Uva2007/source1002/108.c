// @JUDGE_ID:  17051CA  108  C++
// @begin_of_source_code
#include<stdio.h>
main(){
  int n, a;
  int max = 0;
  int grid[200][200];
  int value;
  scanf("%d", &n);

  for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<n ; j++){
      scanf("%d", &a);
      grid[i][j] = a;
    }
  }

  for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<n ; j++){

      for(int k=0 ; k<n-i ; k++){
	for(int l=j ; l<n ; l++){
	  for(int kk=i ; kk<=i+k ; kk++){
	    value = value + grid[kk][l];
	  }
	  if(value>max) max = value;
	}
	value = 0;
      }

    }
  }
  printf("%d\n", max);
  return 0;
}
// @end_of_source_code
