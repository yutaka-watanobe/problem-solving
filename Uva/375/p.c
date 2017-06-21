// @JUDGE_ID:  17051CA  375  C++
// @begin_of_source_code
/* Mathmatic */
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<stl.h>
double B, H;
double PI;

void work(){
  scanf("%lf %lf", &B, &H );

  double sum = 0.0;

  double base, side, height, newHeight;
  double s, r;

  base = B;
  height = H;

  while ( 1 ){
    side = sqrt( height*height + base*base/4.0 );
    r = base*height/(base + 2*side );
    if ( r < 0.000001 ) break;
    sum += r;
    newHeight = height - 2*r;
    base = newHeight*base / height;
    height = newHeight;
  }

  sum = sum*2*PI;
  printf("%13.6lf\n", sum );
}

main(){
  PI = 2*acos( 0.0 );
  int tcase;
  scanf("%d", &tcase);
  for ( int i = 0; i < tcase; i++ ){
    if ( i ) printf("\n");
    work();
  }
}
// @end_of_source_code
