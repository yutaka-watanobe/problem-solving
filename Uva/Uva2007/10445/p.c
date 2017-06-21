// @JUDGE_ID:  17051CA  10445  C++
// @begin_of_source_code
/* Geometory */
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<vector>
#define CLOCKWISE 0
#define ANTICLOCKWISE 1

class point{
 public:
  double x, y;
  point(){}
  point(double x, double y): x(x), y(y){}
};

/*
 * p1とp2の距離。
 */
double dist(const point &p1, const point &p2){
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
/**
 * polygon の面積
 * if area < 0 --> ClockWise
 * else if --> Anti- ClockWise
 */
double getPolygonArea(vector<point> &p){
  double sum = 0;
  for(int i=0; i<p.size()-1; i++){
    sum += p[i].x*p[i+1].y - p[i+1].x*p[i].y;
  }
  sum += p[p.size()-1].x*p[0].y - p[0].x*p[p.size()-1].y;
  return sum/2;
}

/*
 * ３点でできる面積
 * Solved 10112
 */
double getArea(point &p1, point &p2, point &p3){
  return 0.5 * ((p3.y-p1.y)*(p2.x-p1.x)-(p2.y-p1.y)*(p3.x-p1.x));
}

int N;
vector<point> P;
int direction;
double PI;

int read(){
  cin >> N;
  if ( N < 3 ) return 0;
  P.clear();
  double x, y;
  for ( int i = 0; i < N; i++ ){
    cin >> x >> y;
    P.push_back( point( x, y ) );
  }
  
  if ( getPolygonArea( P ) < 0 ) direction = CLOCKWISE;
  else direction = ANTICLOCKWISE;
  return 1;
}

void work(){
  point pi, pj, pk;
  double a, b, c, A, area, angle, degree;
  double max_angle = -INT_MAX;
  double min_angle = INT_MAX;

  for ( int i = 0; i < N; i++ ){
    pi = P[i];
    pj = P[(i+1)%N];
    pk = P[(i+2)%N];
    a = dist( pi, pj );
    b = dist( pj, pk );
    c = dist( pi, pk );
    A = acos( (a*a + b*b - c*c)/(2*a*b) );
    area = getArea( pi, pj, pk );
    if ( direction == ANTICLOCKWISE ){
      if ( area < 0 ) angle = 2*PI - A;
      else angle = A;
    } else if ( direction == CLOCKWISE ){
      if ( area > 0 ) angle = 2*PI - A;
      else angle = A;
    }
    degree = angle*180.0/PI;
    max_angle = max( max_angle, degree );
    min_angle = min( min_angle, degree );
  }

  printf("%.6lf %.6lf\n", min_angle, max_angle );

  
  
}

main(){
  PI = 2*acos( 0.0 );
  while ( read() ){
    work();
  }
}


// @end_of_source_code



