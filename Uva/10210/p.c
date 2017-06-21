// @JUDGE_ID:  17051CA  10210  C++
// @begin_of_source_code
/* Mathematic */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<cmath>

class Point{
 public:
  double x, y;
  Point(){}
  Point(double x, double y ): x(x), y(y){}
};

Point A, B;
double CMD, ENF;
#define PI 3.14159265358979323846

double getDistance(Point p1, Point p2 ){
  return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) );
}

int read(){
  cin >> A.x >> A.y >> B.x >> B.y >> CMD >> ENF;
  if ( cin.eof() ) return 0;
  return 1;
}

void work(){
  double d, r1, r2, h1, h2;

  d = getDistance( A, B );

  r1 = d / sin( ENF*PI/180.0 );
  r2 = d / sin( CMD*PI/180.0 );

  h1 = r1 * cos ( ENF*PI/180.0 );
  h2 = r2 * cos ( CMD*PI/180.0 );

  printf( "%.3f\n", h1 + h2 );

}

main(){
  while ( read() ) work();
}
// @end_of_source_code
