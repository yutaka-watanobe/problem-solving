
// geometory convex hull
// ぐちゃぐちゃ。
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<float.h>
#include<stl.h>
#include<algorithm>
#define INCLUDE_POINT
#define EPS DBL_EPSILON
#define M_PI 3.14159265358979323846
#define deq(a, b) (fabs(a-b) < EPS)
#define dlt(a, b) (!deq(a, b) && a<b)
#define dle(a, b) (deq(a, b) || a<b)
#define IN 1

#define LEFT 1
#define RIGHT (-1)
#define ONBACK (-1)
#define ONFRONT 1
#define ON 0

using namespace std;

class point{
 public:
  double x, y;
  int id;
  point(){}
  point(double x, double y, int id): x(x), y(y), id(id){}
  point operator+(const point &p) const{ return point(x+p.x, y+p.y, id); }
  point operator-(const point &p) const{ return point(x-p.x, y-p.y, id); }
  point operator*(double a) const{ return point(a*x, a*y, id); }
  double operator*(const point &p) const{ return x*p.y - y*p.x; }
  bool operator==(const point &p) const {
    return deq(x, p.x) && deq(y, p.y);
  }
};

class line{
public:
  point p1, p2;
  int id;
  line(){}
  line( point p1, point p2, int id ): p1(p1), p2(p2), id(id){}

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
  /* i >= -size()であること。 */
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
/**
 * Solved 476, 10112
 */
int cross_product(point p0, point p1, point p2){
  double dx1, dy1, dx2, dy2;

  dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
  dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;

  if ( deq( dx1*dy2, dy1*dx2) ) return ON;
  /* p0--p1 に対してp2が左にある(反時計回り) */
  if(dx1*dy2 > dy1*dx2) return LEFT; 
  /* p0--p1 に対してp2が右にある(時計回り) */
  if(dx1*dy2 < dy1*dx2) return RIGHT;

  /* same line */
  /* 問題に応じて返り値を調整すること！！ */
  if((dx1*dx2 < 0) || (dy1*dy2 < 0)) return ON; /* p2--p0--p1 */
  if((dx1*dx1+dy1*dy1)<(dx2*dx2+dy2*dy2)) return ON; /* p0--p1--p3 */

  return ON; /* p0--p2--p1 */
}
/*
 * p1とp2の距離。
 */
double dist(const point &p1, const point &p2){
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

/*
 * 線分(p, o)と線 y=o.y との（反時計回りの）角度。
 * 注意: 返り値は [0, 2*M_PI)である。
 */
double angle(const point &p, point o=point(0, 0, -1)){
  double a = atan2(p.y-o.y, p.x-o.x);
  
  if(dle(0, a)) return a;
  return 2*M_PI+a;
}

/*
 * 線分(p1, o)から線分(p2, o)への（反時計回りの）角度。
 * 要件: 関数 angle(const point&, point)
 */
double angle(const point &p1, const point &p2, const point &o){
  double a = angle(p2, o)-angle(p1, o);
  
  if(dle(0, a)) return a;
  return 2*M_PI+a;
}

/*
 * p0p2がp0p1の左(反時計回り)にあるかどうか。
 * 注意： 返り値 -1 は p0, p1, p2が一直線上にあるとき。
 */
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

  cmp_by_angle(const point o=point(0, 0, -1)): o(o){}
  bool operator()(const point &p1, const point &p2) const {
    double a = angle(p2, o)-angle(p1, o);

    if(fabs(a)<EPS){
      return dist(p1, o)<dist(p2, o);
    }
    return a>0;
  }
};

/**
 * create convex hull
 * Solved 218,  109
 */
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

// 点 p1 を原点として p1-p2 を rad だけ半時計回りに回転した点に変更する.
void rotate( point &p1, point &p2, double rad ) {
  const double dx = p2.x - p1.x, dy = p2.y - p1.y;
  p2.x = dx*cos(rad) - dy*sin(rad) + p1.x;
  p2.y = dx*sin(rad) + dy*cos(rad) + p1.y;
}

string name;
point center;
polygon P;

bool aboveLine( point o1, point o2 ){

  point p1, p2, p3, p4;

  int cp;

  cp = cross_product( o1, o2, center);

  if ( cp != LEFT  ) return false;

  p1 = o1;
  p2 = o2;  
  rotate(p1, p2, M_PI/2.0);
    
  p3 = o2;
  p4 = o1;  
  rotate(p3, p4, 1.5*M_PI);

  cp = cross_product(p1, p2, center);
  if ( cp == ON ) return true;
  if ( cp == LEFT ) return false;

  cp = cross_product(p3, p4, center);
  if ( cp == ON ) return true;
  if ( cp == RIGHT) return false;

  return true;
}

void work(){
  polygon cvx;

  convex(P, cvx);

  vector<line> lines;

  point p1, p2;
  p1 = cvx[0];
  p2 = cvx[1];
  int m = max(p1.id, p2.id);

  for ( int i = 2; i < cvx.size() + 2; i++ ){
    if ( cross_product(p1, p2, cvx[i%cvx.size()]) == ON ) {
      p2 = cvx[i%cvx.size()];
      m = max( m, p2.id );
      
    } else {
      lines.push_back( line (p1, p2, m) );
      p1 = cvx[(i-1)%cvx.size()];
      p2 = cvx[(i)%cvx.size()];
      m = max(p1.id, p2.id);
    }
  }

  int minID = INT_MAX;

  for ( int i = 0; i < lines.size(); i++ ){
    p1 = lines[i].p1;
    p2 = lines[i].p2;
    if ( aboveLine( p1, p2 ) ){
      minID = min( minID, lines[i].id );
    }
  }
  printf("%-19s %2d\n", name.c_str(), minID);

}

bool read(){
  cin >> name;
  if ( name == "#" ) return false;
  double x, y;
  cin >> x >> y;
  
  center = point(x, y, -1);

  P.clear();

  int id = 1;
  while ( 1 ){
    cin >> x >> y;
    if ( x == 0 && y == 0 ) break;
    P.push_back( point(x, y, id++));
  }

  return true;
}

main(){
  while ( read() ){
    work();
  }
}

