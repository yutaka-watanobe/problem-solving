// @JUDGE_ID:  17051CA  10233  C++
// @begin_of_source_code
#include<stdio.h>
#include<cmath>
#include<iostream>
class Point{
 public:
  double x, y;
  Point(){}
  Point(double x, double y ): x(x), y(y){}
};

long source, target, D, S;
Point p1, p2;
double h1, h2, H;

Point getPoint(int p){
  double x, y, xS;
  D = (long)sqrt( p ); S = D*D;
  if ( (p - S) % 2 == 0 ) y = (D-1)*H + h2;
  else  y = (D-1)*H + h1;
  xS = -D*0.5;
  x = xS + (p-S)*0.5;
  return Point(x, y);
}

main(){
  H = sqrt(3.0)/2;
  h1 = 1/(2*sqrt(3.0));
  h2 = 1 / sqrt(3.0);
  while( scanf("%ld %ld", &source, &target) != EOF ){
    p1 = getPoint( source );
    p2 = getPoint( target );
    double dist = sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
    printf("%.3lf\n", dist );
  }
}
// @end_of_source_code
