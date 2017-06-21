// @JUDGE_ID:  17051CA  846  C++
// @begin_of_source_code
#include<stdio.h>
#include<cmath>

main(){
  int tcase, x, y, dist, base, ans;
  scanf("%d", &tcase );
  for ( int i = 0; i < tcase; i++ ){
    scanf("%d %d", &x, &y);
    dist = y - x;
    base = (int)(sqrt(dist) - 0.00000001 );

    if ( dist <= (base+1)*(base+1) - (base+1) ) ans = 2*base;
    else ans = 2*base + 1;

    printf("%d\n", ans );
  }
}

// @end_of_source_code


