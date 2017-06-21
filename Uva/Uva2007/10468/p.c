// @JUDGE_ID:  17051CA  10468  C++
// @begin_of_source_code
/* Math - Geometory */
/* use rotate function & vector operation */
#include<stdio.h>
#include<iostream>

class RigidCirclePacking{
 public:
  double radius;
  double R2, R3;
  double nineCircles, tenCircles;

  RigidCirclePacking(){
    R2 = sqrt( 2 );
    R3 = sqrt( 3 );
  }

  void compute9(){
    double h = radius * sqrt( 1 + 2*R2 );
    double diagonal = ( 3*R2 + R3 + 2 )*radius + h;
    nineCircles = R2*diagonal / 2;
  }

  void compute10(){
    double x1 = (3*R2 + R3 + 1 )*radius / R2;
    double y1 = (3*R2 + R3 - 1 )*radius / R2;
    double x2 = 5*radius;
    double y2 = radius;

    double d = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
    double h = sqrt( 4*radius*radius - ( d/2 )*( d/2 ) );

    double ex = ( x1 - x2 ) / d;
    double ey = ( y1 - y2 ) / d;

    double fx = +ey;
    double fy = -ex;

    double x = ( x1 + x2 ) / 2.0 + fx * h;
    
    tenCircles = x + radius;
  }

  void work(){
    compute9();
    compute10();
    printf("%.5lf %.5lf\n", nineCircles, tenCircles );
  }

  bool read(){
    if ( !( cin >> radius ) ) return false;
    return true;
  }
};

main(){
  RigidCirclePacking packing;
  while ( packing.read() ){
    packing.work();
  }
}
// @end_of_source_code


