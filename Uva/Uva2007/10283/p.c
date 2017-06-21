// @JUDGE_ID:  17051CA  10283  C++
// @begin_of_source_code
/* Geometory + Mathmatic */
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<stl.h>

double R;
double PI;

int N;

void work(){
  double r, d, A, B, X, triangle, polygon, petal, blue_area, green_area;

  A = 360.0 / N;
  B = 180.0 - A;
  
  X = 1.0 - cos( A*PI / 180.0 );
  r = ( sqrt( (2*R*X)*(2*R*X) + 4*R*R*X*(2 - X) ) - 2*R*X ) / ( 4 - 2*X );
  d = R - r;
  
  petal = r*r*( B*PI / 180.0 )/ 2.0 ;
  triangle = d*d*sin( A*PI / 180.0 ) / 2.0;

  blue_area = ( N * triangle ) - ( N * petal );
  green_area = R*R*PI - ( N*r*r*PI ) - blue_area;

  printf("%.10lf %.10lf %.10lf\n", r, blue_area, green_area );
}

void exception(){
  if ( N == 1 ){
    printf("%.10lf %.10lf %.10lf\n", R, 0.0, 0.0 );
  } else if ( N == 2 ){
    double r = R / 2.0;
    printf("%.10lf %.10lf %.10lf\n", r, 0.0, R*R*PI - 2*r*r*PI );
  } else {
    assert( false );
  }
}

main(){
  PI = 2.0*acos( 0.0 );
  while ( cin >> R >> N ){
    if ( N <= 2 ) exception();
    else work();
  }
}
// @end_of_source_code
