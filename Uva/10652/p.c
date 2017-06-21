// @JUDGE_ID:  17051CA  10652  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<math.h>
#include<float.h>
#define INCLUDE_POINT
#define EPS FLT_EPSILON
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
  bool operator==(const point &p) const {
    return deq(x, p.x) && deq(y, p.y);
  }
};

class polygon {
 public:
  vector<point> v;
  point l, u;

  polygon(){}
  polygon(const polygon &p): v(p.v){}
  void push_back(const point &p){
    v.push_back(p);
  }
  void clear(){ v.clear(); }
  void resize(int n){ v.resize(n); }
  int size(){ return v.size(); }

  point &operator[](int i){ return v[(i+size())%size()]; }
  void find_most(){
    if(size()==0) return;

    u = l = v[0];
    for(int i=1; i<size(); i++){
      if(deq(v[i].y, l.y) && v[i].x<l.x || v[i].y<l.y)
	l = v[i];
      if(deq(v[i].y, u.y) && v[i].x<u.x || v[i].y>u.y)
	u = v[i];
    }
  }
};

double dist(const point &p1, const point &p2){
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double angle(const point &p, point o=point(0, 0)){
  double a = atan2(p.y-o.y, p.x-o.x);
  
  if(dle(0, a)) return a;
  return 2*M_PI+a;
}


double angle(const point &p1, const point &p2, const point &o){
  double a = angle(p2, o)-angle(p1, o);
  
  if(dle(0, a)) return a;
  return 2*M_PI+a;
}

int is_left(const point &p0, const point &p1, const point &p2){
  double tmp = (p2-p0)*(p1-p0);

  if(deq(tmp, 0)) return -1;
  return tmp<0;
}

int is_left_turn(const point &p0, const point &p1, const point &p2){
  double tmp = (p2-p0)*(p1-p0);

  if(fabs(tmp)<EPS) return -1;
  return tmp<0;
}

class cmp_by_angle: binary_function<const point&, const point&, bool>{
 public:
  point o;

  cmp_by_angle(const point o=point(0, 0)): o(o){}
  bool operator()(const point &p1, const point &p2) const {
    double a = angle(p2, o)-angle(p1, o);

    if(fabs(a)<EPS){
      return dist(p1, o)<dist(p2, o);
    }
    return a>0;
  }
};

void convex(polygon &s, polygon &t){
  vector<point> v(s.v);

  s.find_most();
  sort(v.begin(), v.end(), cmp_by_angle(s.l));
  
  t.clear();
  for(int i=0; i<3; i++) t.push_back(v[i]);
  for(int i=3; i<v.size(); i++){
    while(is_left(t[t.size()-2], t.v.back(), v[i])==0 && t.size()>1)
      t.v.pop_back();
    t.push_back(v[i]);
  }
  t.find_most();
}

double getPolygonArea(vector<point> p){
  double sum = 0;
  for(int i=0; i<p.size()-1; i++){
    sum += p[i].x*p[i+1].y - p[i+1].x*p[i].y;
  }
  sum += p[p.size()-1].x*p[0].y - p[0].x*p[p.size()-1].y;
  return fabs(sum/2);
}

void add( double x, double y, double rad, polygon &P, double cx, double cy ){
  double xx, yy;
  x -= cx;
  y -= cy;

  xx = x*cos( rad ) - y*sin( rad );
  yy = x*sin( rad ) + y*cos( rad );

  P.push_back( point( xx + cx , yy + cy ) );
}

void work(){
  int n;
  cin >> n;
  double x, y, w, h, pi;
  double rad;

  double board_sum = 0;
  double area = 0;

  double cx, cy, x1, y1, x2, y2, x3, y3, x4, y4;
  double dx1, dy1, dx2, dy2;
  double ww, hh;

  polygon P;
  
  for ( int i = 0; i < n; i++ ){
    cin >> cx >> cy >> w >> h >> pi;
    ww = w/2;
    hh = h/2;

    rad = pi * M_PI / 180;

    x1 = cx - ww;
    y1 = cy + hh;
    x2 = cx + ww;
    y2 = cy + hh;
    x3 = cx - ww;
    y3 = cy - hh;
    x4 = cx + ww;
    y4 = cy - hh;

    rad = -rad;
    
    add( x1, y1, rad, P, cx, cy);
    add( x2, y2, rad, P, cx, cy);
    add( x3, y3, rad, P, cx, cy);
    add( x4, y4, rad, P, cx, cy);

    board_sum += h*w;
  }


  polygon cvx;

  convex( P, cvx );
  
  area = getPolygonArea( cvx.v );

  double ans = (100 * board_sum / area );
  printf("%.1lf %%\n", ans );
}

main(){
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    work();
  }
}
// @end_of_source_code


