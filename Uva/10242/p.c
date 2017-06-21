// @JUDGE_ID:  17051CA  10242  C++
// @begin_of_source_code
/* Math + Geometory */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#define EPS 0.0000001
#define deq(a, b) (fabs(a-b) < EPS)

class FourthPoint{
 public:
  double x1, y1, x2, y2, x3, y3, x4, y4;

  void work(){
    x4 = x1 + x3 - x2;
    y4 = y1 + y3 - y2;
    printf("%.3lf %.3lf\n", x4, y4 );
  }

  bool read(){
    pair<double, double> point[4];
    if ( !( cin >> point[0].first >> point[0].second ) ) return false;
    cin >> point[1].first >> point[1].second;
    cin >> point[2].first >> point[2].second;
    cin >> point[3].first >> point[3].second;

    if ( deq( point[0].first, point[1].first ) && deq( point[0].second, point[1].second ) ){
      x2 = point[0].first;
      y2 = point[0].second;
      x1 = point[2].first;
      y1 = point[2].second;
      x3 = point[3].first;
      y3 = point[3].second;
    } else if ( deq( point[0].first, point[2].first ) && deq( point[0].second, point[2].second ) ){
      x2 = point[0].first;
      y2 = point[0].second;
      x1 = point[1].first;
      y1 = point[1].second;
      x3 = point[3].first;
      y3 = point[3].second;
    } else if ( deq( point[0].first, point[3].first ) && deq( point[0].second, point[3].second ) ){
      x2 = point[0].first;
      y2 = point[0].second;
      x1 = point[2].first;
      y1 = point[2].second;
      x3 = point[1].first;
      y3 = point[1].second;
    } else if ( deq( point[1].first, point[2].first ) && deq( point[1].second, point[2].second ) ){
      x2 = point[1].first;
      y2 = point[1].second;
      x1 = point[0].first;
      y1 = point[0].second;
      x3 = point[3].first;
      y3 = point[3].second;
    } else if ( deq( point[1].first, point[3].first ) && deq( point[1].second, point[3].second ) ){
      x2 = point[1].first;
      y2 = point[1].second;
      x1 = point[0].first;
      y1 = point[0].second;
      x3 = point[2].first;
      y3 = point[2].second;
    } else if ( deq( point[2].first, point[3].first ) && deq( point[2].second, point[3].second ) ){
      x2 = point[2].first;
      y2 = point[2].second;
      x1 = point[0].first;
      y1 = point[0].second;
      x3 = point[1].first;
      y3 = point[1].second;
    }
    return true;
  }
};

main(){
  FourthPoint FP;
  while ( FP.read() ){
    FP.work();
  }
}

// @end_of_source_code


