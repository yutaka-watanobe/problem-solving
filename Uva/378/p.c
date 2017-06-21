// @JUDGE_ID:  17051CA  378  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>
#include<stl.h>
#include <float.h>
#define EPS DBL_EPSILON
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
 * p0p2がp0p1の左(反時計回り)にあるかどうか。
 * 注意： 返り値 -1 は p0, p1, p2が一直線上にあるとき。
 */
int is_left(const point &p0, const point &p1, const point &p2){
  double tmp = (p2-p0)*(p1-p0);

  if(deq(tmp, 0)) return -1;
  return tmp<0;
}

/*
 * pがp1, p2の作る長方形の中にあるかどうか。
 */
bool is_inbox(const point &p1, const point &p2, const point &p){
  return dle(min(p1.x, p2.x), p.x) && dle(p.x, max(p1.x, p2.x))
    &&   dle(min(p1.y, p2.y), p.y) && dle(p.y, max(p1.y, p2.y));
}
/*
 * pがp1p2上にあるかどうか。
 * 要件: 関数 is_inbox、is_left
 */
bool is_on_seg(const point &p1, const point &p2, const point &p){
  return is_inbox(p1, p2, p) && is_left(p1, p2, p)==-1;
}
/*
 * p1p2, p3p4が交差するかどうか。（-1はp1p2, p3p4が重なっているとき）
 * 要件: 関数 is_inbox, is_left
 */
int is_intersect(const point &p1, const point &p2, 
		 const point &p3, const point &p4){
  int d1, d2, d3, d4;
  int b1, b2, b3, b4;

  d1 = is_left(p3, p4, p1);
  d2 = is_left(p3, p4, p2);
  d3 = is_left(p1, p2, p3);
  d4 = is_left(p1, p2, p4);

  b1 = is_inbox(p3, p4, p1);
  b2 = is_inbox(p3, p4, p2);
  b3 = is_inbox(p1, p2, p3);
  b4 = is_inbox(p1, p2, p4);

  if(d1==-1 && d2==-1 && (b1 || b2)) return -1;
  if(d1==-1 && b1) return 1;
  if(d2==-1 && b2) return 1;
  if(d3==-1 && b3) return 1;
  if(d4==-1 && b4) return 1;
  if(d1!=d2 && d3!=d4) return 1;
  return 0;
}
/*
 * p1p2, p3p4 の交点。
 * 要件: 関数 is_on_seg、p1p2とp3p4は交差し、重ならないこと。
 */
point intersect(const point &p1, const point &p2,
		const point &p3, const point &p4){
 /*  if(on_segment(p3, p4, p1)) return p1; */
/*   if(on_segment(p3, p4, p2)) return p2; */
/*   if(on_segment(p1, p2, p3)) return p3; */
/*   if(on_segment(p1, p2, p4)) return p4; */
  if(is_on_seg(p3, p4, p1)) return p1;
  if(is_on_seg(p3, p4, p2)) return p2;
  if(is_on_seg(p1, p2, p3)) return p3;
  if(is_on_seg(p1, p2, p4)) return p4;
  double x1, x2, y1, y2, d1, d2;
  point p;

  x1 = p1.x-p2.x;
  x2 = p3.x-p4.x;
  y1 = p1.y-p2.y;
  y2 = p3.y-p4.y;
  d1 = p1*p2;
  d2 = p3*p4;

  /* p.x = -(x1*d2-x2*d1)/(x1*y2-x2*y1); */
/*   p.y = -(y1*d2-y2*d1)/(x1*y2-x2*y1); */
  p.x = (x2*d1-x1*d2)/(x1*y2-x2*y1);
  p.y = (y2*d1-y1*d2)/(x1*y2-x2*y1);

  if(p.x==0) p.x = 0;
  if(p.y==0) p.y = 0;
  return p;
}

bool isParallel(point p1, point p2, point p3, point p4){
  double dx1, dx2, dy1, dy2;
  dx1 = p2.x - p1.x;
  dy1 = p2.y - p1.y;
  dx2 = p4.x - p3.x;
  dy2 = p4.y - p3.y;
  return dy1*dx2 == dy2*dx1;
}
/*
 線分 s との交点を返す.
 線分 s と交わり, 平行でないことを確かめて実行すること.
 交わっていない場合も延長線上の交点を返すが, それは
 保証ではないので外部からは使うべきではない.
 Computational Geometry in C*/
point intersection(point p1, point p2, point p3, point p4){
  double num, denom, r;
  
  num = (p1.y - p3.y) * (p4.x - p3.x)
    - (p1.x - p3.x) * (p4.y - p3.y);
  denom = (p2.x - p1.x) * (p4.y - p3.y)
    - (p2.y - p1.y) * (p4.x - p3.x);
  
  assert( ! deq(denom, 0) );
  r = num / denom;
  
  return point(p1.x + r*(p2.x - p1.x), p1.y + r*(p2.y - p1.y));
}

void work(){
  double x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

  point p1 = point(x1, y1);
  point p2 = point(x2, y2);
  point p3 = point(x3, y3);
  point p4 = point(x4, y4);

  if(direction(p1, p2, p3)==0 && direction(p1, p2, p4)==0 ){ 
    cout << "LINE" << endl;
    return;
  }
  
  if(isParallel(p1, p2, p3, p4)){
    cout << "NONE" << endl;
    return;
  }

  point p = intersect(p1, p2, p3, p4);
  cout << "POINT ";
  printf("%.2lf %.2lf\n", p.x, p.y);
}

main(){
  int n;
  cin >> n;
  cout << "INTERSECTING LINES OUTPUT" << endl;
  for(int i=0; i<n; i++){
    work();
  }
  cout << "END OF OUTPUT" << endl;
}
// @end_of_source_code
