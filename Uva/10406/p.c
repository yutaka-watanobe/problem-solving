// @JUDGE_ID:  17051CA  10406  C++
// @begin_of_source_code
/* Geometory */
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<stl.h>
#include<float.h>
#define INCLUDE_POINT
#define EPS DBL_EPSILON
#define M_PI 3.14159265358979323846
#define deq(a, b) (fabs(a-b) < EPS)
#define dlt(a, b) (!deq(a, b) && a<b)
#define dle(a, b) (deq(a, b) || a<b)

class point{
 public:
  double x, y;
  point(){}
  point(double x, double y): x(x), y(y){}
  point operator+(const point &p) const{ return point(x+p.x, y+p.y); }
  point operator-(const point &p) const{ return point(x-p.x, y-p.y); }
  point operator*(double a) const{ return point(a*x, a*y); }
  double operator*(const point &p) const{ return x*p.y - y*p.x; }
};

bool on_segment(point pi, point pj, point pk){
  if( min(pi.x, pj.x) <= pk.x && pk.x <= max(pi.x, pj.x) &&
      min(pi.y, pj.y) <= pk.y && pk.y <= max(pi.y, pj.y)) return true;
  else return false;
}

point intersect(point p1, point p2, point p3, point p4){
  double num, denom, r;
  
  num = (p1.y - p3.y) * (p4.x - p3.x)
    - (p1.x - p3.x) * (p4.y - p3.y);
  denom = (p2.x - p1.x) * (p4.y - p3.y)
    - (p2.y - p1.y) * (p4.x - p3.x);
  
  assert( ! deq(denom, 0) );
  r = num / denom;
  
  return point(p1.x + r*(p2.x - p1.x), p1.y + r*(p2.y - p1.y));
}

/**
 * 水平線からの角度 (degree)
 */
double getRealTheta(point p1, point p2){
  double k;
  double dx, dy;

  dx = p2.x - p1.x;
  dy = p2.y - p1.y;

  if( dx == 0 ){
    if( dy > 0 ){
      return 90;
    }else{
      return 180+90;
    }
  }

  k = atan( dy/dx )/ M_PI * 180;
  if( dx < 0 ){
    k += 90 + 90;
  }else if( dy < 0 ){
    k += 90 + 180 + 90;
  }
  return k;
  }
/*
double getRealTheta(point p1, point p2 ){
  double dx, dy, ax, ay;
  double t;
  dx = p2.x - p1.x; ax = fabs(dx);
  dy = p2.y - p1.y; ay = fabs(dy);
  t = (fabs(ax - ay) < 0.0000000000001 ) ? 0 : (double) dy/(ax + ay);
  if ( dx < 0 ) t = 2 - t;
  else if ( dy < 0 ) t = 4 + t;
  return t * 90.0;
  }*/

/**
 * 進行方向の右に向かって d 平行移動
 */
void parallelShift(point p1, point p2, point &pp1, point &pp2, double d){
  if(p1.y == p2.y){
    if(p1.x <= p2.x){
      pp1 = point(p1.x, p1.y-d);
      pp2 = point(p2.x, p2.y-d);
    }else{
      pp1 = point(p1.x, p1.y+d);
      pp2 = point(p2.x, p2.y+d);
    }
    return;
  }
  if(p1.x == p2.x){
    if(p1.y <= p2.y){
      pp1 = point(p1.x+d, p1.y);
      pp2 = point(p2.x+d, p2.y);
    }else{
      pp1 = point(p1.x-d, p1.y);
      pp2 = point(p2.x-d, p2.y);
    }
    return;
  }
  double px, py;
  double theta = getRealTheta(p1, p2);
  theta = 90 - theta;
  px = d*cos(theta*M_PI/180);
  py = d*sin(theta*M_PI/180);

  pp1 = point(p1.x + px, p1.y - py);
  pp2 = point(p2.x + px, p2.y - py);
}

double getPolygonArea(vector<point> p){
  double sum = 0;
  for(int i=0; i<p.size()-1; i++){
    sum += p[i].x*p[i+1].y - p[i+1].x*p[i].y;
  }
  sum += p[p.size()-1].x*p[0].y - p[0].x*p[p.size()-1].y;
  return abs(sum/2);
}

double d;
int n;

int read(){
  cin >> d >> n;
  if(d==0 && n==0) return 0;
  return 1;
}

void work(){
  vector<point> p;
  double x, y;
  
  for(int i=0; i<n; i++){
    cin >> x >> y;
    p.push_back(point(x, y));
  }

  vector<pair<point, point> > seg;

  point p1, p2;
  for(int i=0; i<n-1; i++){
    parallelShift(p[i], p[i+1], p1, p2, d);
    seg.push_back(pair<point, point>(p1, p2));
  }
  parallelShift(p[n-1], p[0], p1, p2, d);
  seg.push_back(pair<point, point>(p1, p2));

  vector<point> sp;
  for(int i=0; i<seg.size()-1; i++){
    point ip = intersect(seg[i].first, seg[i].second, seg[i+1].first, seg[i+1].second);

    sp.push_back(ip);
  }
  point ip = intersect(seg[seg.size()-1].first, seg[seg.size()-1].second, seg[0].first, seg[0].second);
  sp.push_back(ip);

  double area = getPolygonArea(sp);

  printf("%.3f\n", area);

}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
