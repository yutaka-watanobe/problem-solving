// @JUDGE_ID:  17051CA  10678  C++
// @begin_of_source_code
#include<stdio.h>
#include<cmath>

main(){
  int tcase;
  scanf("%d", &tcase);
  double D, L, d, l;
  double a, b;
  for ( int i = 0; i < tcase; i++ ){
    scanf("%lf %lf", &D, &L );
    l = L/2;
    d = D/2;
    a = sqrt(l*l - d*d );
    b = (L-D)/2 + d;
    printf("%.3lf\n", 2*acos(0.0)*a*b);
  }
}
// @end_of_source_code
