// @JUDGE_ID:  17051CA  137  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<cmath>
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
 * 重なる場合は 0 を返す
 */
int direction(point pi, point pj, point pk){
  /* (pk - pi)*(pj - pi) */
  return (int)((pk.x - pi.x)*(pj.y - pi.y) - (pj.x - pi.x)*(pk.y - pi.y));
}

bool on_segment(point pi, point pj, point pk){
  if( min(pi.x, pj.x) <= pk.x && pk.x <= max(pi.x, pj.x) &&
      min(pi.y, pj.y) <= pk.y && pk.y <= max(pi.y, pj.y)) return true;
  else return false;
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
/**
 * segment が intersect するか否か？
 * Solved 273, 191
 */
int segments_intersect(const point &p1, const point &p2, 
		 const point &p3, const point &p4){
  int d1, d2, d3, d4;
  bool on1, on2, on3, on4;

  d1 = direction(p3, p4, p1);
  d2 = direction(p3, p4, p2);
  d3 = direction(p1, p2, p3);
  d4 = direction(p1, p2, p4);

  on1 = on_segment(p3, p4, p1);
  on2 = on_segment(p3, p4, p2);
  on3 = on_segment(p1, p2, p3);
  on4 = on_segment(p1, p2, p4);



  if( ((d1>0 && d2<0)||(d1<0 && d2>0)) &&
      ((d3>0 && d4<0)||(d3<0 && d4>0)) ) return true;
  else if( d1==0 && on1 ) return true;
  else if( d2==0 && on2 ) return true;
  else if( d3==0 && on3 ) return true;
  else if( d4==0 && on4 ) return true;
  else return false;
}

/*
 * p1p2, p3p4 の交点。交わっていない場合も延長線上の交点を返す。
 * 要件: 関数 is_on_seg、p1p2とp3p4は交差し、重ならないこと。
 * Solved
 * need check!!!! 10406?
 */
point intersect(const point &p1, const point &p2,
		const point &p3, const point &p4){
  if(on_segment(p3, p4, p1)) return p1;
  if(on_segment(p3, p4, p2)) return p2;
  if(on_segment(p1, p2, p3)) return p3;
  if(on_segment(p1, p2, p4)) return p4;

  double x1, x2, y1, y2, d1, d2;
  point p;

  x1 = p1.x-p2.x;
  x2 = p3.x-p4.x;
  y1 = p1.y-p2.y;
  y2 = p3.y-p4.y;
  d1 = p1*p2;
  d2 = p3*p4;

  p.x = -(x1*d2-x2*d1)/(x1*y2-x2*y1);
  p.y = -(y1*d2-y2*d1)/(x1*y2-x2*y1);

  return p;
}

double getPolygonArea(vector<point> p){

  if ( p.size() < 3 ) return 0;

  double sum = 0;
  for(int i=0; i<p.size()-1; i++){
    sum += p[i].x*p[i+1].y - p[i+1].x*p[i].y;
  }
  sum += p[p.size()-1].x*p[0].y - p[0].x*p[p.size()-1].y;
  return fabs(sum/2.0);
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

  if( v.size() < 3 ) return ;


  for(int i=0; i<3; i++) t.push_back(v[i]);
  for(int i=3; i<v.size(); i++){
    while(is_left(t[t.size()-2], t.v.back(), v[i])==0 && t.size()>1)
      t.v.pop_back();
    t.push_back(v[i]);
  }

}



bool include(polygon pol, point p){
  
  if ( pol.size() < 3 ) return false;

  for ( int i = 0; i < pol.size()-1; i++ ){
    if ( !is_left(pol[i], p, pol[i+1]) ) return false;
  }
  
  if ( !is_left(pol[pol.size()-1], p, pol[0]) ) return false;
  return true;
 }

polygon pol1, pol2;
polygon P;

void work(){
  P.clear();
  
  for ( int i = 0; i < pol1.size()-1; i++ ){
    for ( int j = 0; j < pol2.size()-1; j++ ){
      if (segments_intersect(pol1[i], pol1[i+1], pol2[j], pol2[j+1])){
	  P.push_back(intersect(pol1[i], pol1[i+1], pol2[j], pol2[j+1]));
      }
    }
  }
  
  for ( int i = 0; i < pol1.size(); i++ ){
    if(include(pol2, pol1[i])){
      P.push_back( pol1[i] );
    }
  }
  
  for ( int i = 0; i < pol2.size(); i++ ){
    if(include(pol1, pol2[i])){
      P.push_back( pol2[i] );
    }
  }
  
  polygon P2;
  convex(P, P2);

  cout << "List = ";
  for (int i = 0; i < P2.size(); i++ ){
    cout << "(" << P2[i].x << "," << P2[i].y << ")";
  }
  cout << endl;

  double sum = getPolygonArea(pol1.v) + getPolygonArea(pol2.v) - getPolygonArea(P2.v)*2;
  
  /*
  cout << getPolygonArea(pol1.v) << " + ";
  cout << getPolygonArea(pol2.v) << " - ";
  cout << getPolygonArea(P2.v) << "*2" << endl;
  */
  printf("%8.2lf", sum);
}



bool read(){
  int n, m, x, y;
  cin >> n;
  if ( n == 0 ) return false;
  
  pol1.clear();
  pol2.clear();
  
  for ( int i = 0; i < n; i++ ){
    cin >> x >> y;
    pol1.push_back( point(x, y) );
  }
  
  cin >> m;
  
  for ( int i = 0; i < m; i++ ){
    cin >> x >> y;
    pol2.push_back( point(x, y) );
  }
  
  return true;
}

main(){

  while ( read() ){
    work();
  }
  cout << endl;
}


// @end_of_source_code


