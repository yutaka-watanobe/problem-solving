// @JUDGE_ID:  17051CA  10215  C++
// @begin_of_source_code
/* Mathmatic */
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>

double W, L;

void work(){
  double max_x, min_x1, min_x2;
  
  min_x1 = 0;
  min_x2 = min ( W/2.0, L/2.0 );

  double x1 = ( 4*(W+L) - sqrt( 16*(W+L)*(W+L) - 48*W*L ) ) / 24.0;
  double x2 = ( 4*(W+L) + sqrt( 16*(W+L)*(W+L) - 48*W*L ) ) / 24.0;

  double vol1 = x1*(W-2*x1)*(L-2*x1);
  double vol2 = x1*(W-2*x2)*(L-2*x2);
  
  if ( vol1 > vol2 ) max_x = x1;
  else max_x = x2;

  printf("%.3f %.3f %.3f\n", max_x, min_x1, min_x2 );
}

main(){
  while ( cin >> W >> L ) work();
}
// @end_of_source_code
