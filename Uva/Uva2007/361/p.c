// @JUDGE_ID:  17051CA  361  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#include<math.h>
#include<float.h>
#define LEFT 1
#define RIGHT 0
#define ON 2
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
  bool operator==(const point &p) const {
    return deq(x, p.x) && deq(y, p.y);
  }
};

/*
 * 多角形オブジェクト
 */
class polygon {
 public:
  vector<point> v;
  point l, u;

  polygon(){}
  polygon(const polygon &p): v(p.v){}
  void push_back(const point &p){
    v.push_back(p);
    find_most();
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
double angle(const point &p, point o=point(0, 0)){
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
  if(deq(tmp, 0)) return 2;
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

/**
 * create convex hull
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

int cross_product(point p0, point p1, point p2){
  double dx1, dy1, dx2, dy2;

  dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
  dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;
 
  /* p0--p1 に対してp2が左にある(反時計回り) */
  if(dx1*dy2 > dy1*dx2) return LEFT; 
  /* p0--p1 に対してp2が右にある(時計回り) */
  if(dx1*dy2 < dy1*dx2) return RIGHT;

  /* same line */
  /* 問題に応じて返り値を調整すること！！ */
  if((dx1*dx2 < 0) || (dy1*dy2 < 0)) return 0; /* p2--p0--p1 */
  if((dx1*dx1+dy1*dy1)<(dx2*dx2+dy2*dy2)) return 0; /* p0--p1--p3 */

  return ON; /* p0--p2--p1 */
}

int c, r, o;
polygon C;
polygon R;
vector<point> O;

int read(){
  C.clear();
  R.clear();
  O.clear();
  cin >> c >> r >> o;
  if ( c == 0 && r == 0 && o == 0 ) return 0;
  double x, y;

  for ( int i = 0; i < c; i++ ){
    cin >> x >> y;
    C.push_back( point( x, y ) );
  }

  for ( int i = 0; i < r; i++ ){
    cin >> x >> y;
    R.push_back( point( x, y ) );
  }

  for ( int i = 0; i < o; i++ ){
    cin >> x >> y;
    O.push_back( point( x, y ) );
  }

  return 1;
}

void work(){

  vector<bool> safe, robbed;
  safe.resize( O.size(), false );
  robbed.resize( O.size(), false );

  polygon cvxC, cvxR;
  
  if( c >= 3 ) convex(C, cvxC);
  if( r >= 3 ) convex(R, cvxR);
  
  int direction;

  for ( int n = 0; n < O.size(); n++){
    cout << "     Citizen at (" << O[n].x << "," << O[n].y << ") is ";
    
    safe[n] = true;

    if( c < 3 ) {
      safe[n] = false;
      goto next1;
    }
    for(int i = 0; i < cvxC.size()-1; i++){
      direction = is_left(cvxC[i], cvxC[i+1], O[n]);
      if ( direction == ON ){
	safe[n] = true;
	goto next1;
      }
      if ( direction == 0 ){
	safe[n] = false;
	goto next1;
      }
    }
    direction = is_left(cvxC[cvxC.size()-1], cvxC[0], O[n]);
    if ( direction == ON){
      safe[n] = true;
      goto next1;
    }
    if ( direction == 0 ){
      safe[n] = false;
      goto next1;
    }
    
  next1:;
    
    robbed[n] = true;
    
    if( r < 3 ) {
      robbed[n] = false;
      goto next2;
    }
    for(int i = 0; i < cvxR.size()-1; i++){
      direction = is_left(cvxR[i], cvxR[i+1], O[n]);
      if ( direction == ON){
	robbed[n] = true;
	goto next2;
      }
      if ( direction == 0){
	robbed[n] = false;
	goto next2;
      }
    }
    direction = is_left(cvxR[cvxR.size()-1], cvxR[0], O[n]);
    if ( direction == ON){
      robbed[n] = true;
      goto next2;
    }
    if ( direction == 0 ){
      robbed[n] = false;
      goto next2;
    }
    
  next2:;
    
    if( safe[n] ) cout << "safe." << endl;
    else if ( robbed[n] ) cout << "robbed." << endl;
    else cout << "neither." << endl;
  }  
  
}

main(){
  for ( int i = 1; read(); i++ ) {
    cout << "Data set " << i << ":" << endl;
    work();
    cout << endl;
  }
}
// @end_of_source_code
