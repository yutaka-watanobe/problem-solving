// @JUDGE_ID:  17051CA  191  C++
// @begin_of_source_code
/* Geometory - Line Intersection */
#include<stdio.h>
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

/**
 * segment が intersect するか否か？
 * Solved 273, 
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

int px1, py1, px2, py2, left, top, right, bottom;

bool is_intersect_rectangle(){
  point p1 = point( px1, py1 );
  point p2 = point( px2, py2 );
  if ( segments_intersect( p1, p2, point(left, top), point(right, top) ) ) return true;
  if ( segments_intersect( p1, p2, point(left, top), point(left, bottom) ) ) return true;
  if ( segments_intersect( p1, p2, point(left, bottom), point(right, bottom) ) ) return true;
  if ( segments_intersect( p1, p2, point(right, top), point(right, bottom) ) ) return true;

  /* in */
  if ( min( px1, px2 ) >= left &&
       max( px1, px2 ) <= right &&
       max( py1, py2 ) <= top &&
       min( py1, py2 ) >= bottom ) return true;

  return false;
}


void work(){
  if ( is_intersect_rectangle() ) cout << "T" << endl;
  else cout << "F" << endl;
}

main(){
  int test;
  cin >> test ;
  int l, t, r, b;
  for ( int i = 0; i < test; i++ ){
    cin >> px1 >> py1 >> px2 >> py2 >> l >> t >> r >> b;
    left = min( l, r );
    right = max( l, r );
    top = max( t, b );
    bottom = min( t, b );
    work();
  }
}
// @end_of_source_code
