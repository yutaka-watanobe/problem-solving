// @JUDGE_ID:  17051CA  113  C++
// @begin_of_source_code
#include<stdio.h>
#include<math.h>

main(){
  int n;
  double p;
  while( scanf("%d", &n) != EOF){
    scanf("%lf", &p);
    printf("%.0f\n", exp( log(p)/n ) );
  }
  return 0;
}
// @end_of_source_code
