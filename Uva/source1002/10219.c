// @JUDGE_ID:  17051CA  10219  C++
// @begin_of_source_code
#include<stdio.h>
#include<math.h>

main(){
  long n, k, i, j;
  double x;

  while(scanf("%ld %ld", &n, &k)!=EOF){
    x = 0;

    if(k>=n/2) k = n-k;
    
    for(i=k; i>0; i--){
      x -= log10(i);
    }
    
    for(i=n; i>n-k; i--){
      x += log10(i);
    }
    
    x += 1;
    printf("%ld\n",(long)floor(x));
  }
}
// @end_of_source_code
