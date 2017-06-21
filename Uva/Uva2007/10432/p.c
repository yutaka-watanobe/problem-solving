// @JUDGE_ID:  17051CA  10432  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<cmath>
#define M_PI            3.14159265358979323846

class PolygonInsideACircle{
 public:
  int  n;
  double r;

  PolygonInsideACircle(){}

  bool read(){
    return ( cin >> r >> n );
  }

  void work(){
    double S = n*r*r*sin(2*M_PI/n)/2;
    printf("%.3lf\n", S);
  }

};

main(){
  PolygonInsideACircle PIAC;

  while ( PIAC.read() ){
    PIAC.work();
  }
}

// @end_of_source_code


