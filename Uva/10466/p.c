// @JUDGE_ID:  17051CA  10466  C++
// @begin_of_source_code
/* Math */
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<vector>
#define PI 3.14159265358979323846

class Body{
 public:
  double posX, posY;
  int radius, rtime, T;
  double dist;
  Body(){}
  Body( double posX, double posY, int radius, int rtime, int T ):
    posX(posX), posY(posY), radius(radius), rtime(rtime), T(T){
  }

  void compute( double centerX, double centerY ){
    double rad = 2.0 * PI * ( (T % rtime ) /(double) rtime);
    double x = centerX + radius * cos( rad );
    double y = centerY + radius * sin( rad );
    dist = sqrt( x*x + y*y );
    posX = x;
    posY = y;
  }
};

class HowFar{
 public:
  int n, T;

  vector<Body> bodies;
  
  HowFar(){}

  void work(){
    for ( int i = 1; i < bodies.size(); i++ ){
      bodies[i].compute( bodies[i-1].posX, bodies[i-1].posY );
    }

    for ( int i = 1; i < bodies.size(); i++ ){
      if ( i-1 ) cout << " ";
      printf("%.4lf", bodies[i].dist );
    }
    cout << endl;
  }

  bool read(){
    bodies.clear();
    if ( !( cin >> n >> T ) ) return false;
    bodies.resize( n + 1 );
    int r, t;
    bodies[0] = Body( 0, 0, 0, 1, 1 );

    for ( int i = 1; i <= n; i++ ){
      scanf("%d %d", &r, &t );
      bodies[i] = Body( bodies[i-1].posX + r, 0, r, t, T );
    }
    return true;
  }
};

main(){
  HowFar far;
  while ( far.read() ){
    far.work();
  }
}

// @end_of_source_code


