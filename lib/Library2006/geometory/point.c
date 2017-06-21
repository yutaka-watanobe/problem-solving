/****************
 * Point - Line *
 ****************/
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
 * p1とp2の距離。
 */
double dist(const point &p1, const point &p2){
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

/*
 * ３点でできる面積
 * if area < 0 --> ClockWise
 * else if --> Anti- ClockWise
 * Solved 10112
 */
double getArea(point p1, point p2, point p3){
  return abs(0.5 * ((p3.y-p1.y)*(p2.x-p1.x)-(p2.y-p1.y)*(p3.x-p1.x)));
}

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

  // ここが非常にあやしい
  if(on_segment(p3, p4, p1)) return p1;
  if(on_segment(p3, p4, p2)) return p2;
  if(on_segment(p1, p2, p3)) return p3;
  if(on_segment(p1, p2, p4)) return p4;
  // ここまで


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

/**
 * Solved
 */
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
 交わっていない場合も延長線上の交点を返す。
 Computational Geometry in C
 Solved 10406*/
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


/**
 * 水平線からの角度 (degree)
 * Solved 10406
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

double getRealTheta(pont p1, point p2 ){



}

/**
 * 進行方向の右に向かって d 平行移動
 * Solved 10406
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

  cout << theta << " " << d << " " <<px << " " << py << endl;
  pp1 = point(p1.x + px, p1.y - py);
  pp2 = point(p2.x + px, p2.y - py);
}

/**
 * polygon の面積
 * if area < 0 --> ClockWise
 * else if --> Anti- ClockWise
 * Solved 10406
 */
double getPolygonArea(vector<point> p){
  double sum = 0;
  for(int i=0; i<p.size()-1; i++){
    sum += p[i].x*p[i+1].y - p[i+1].x*p[i].y;
  }
  sum += p[p.size()-1].x*p[0].y - p[0].x*p[p.size()-1].y;
  return abs(sum/2);
}

main(){

  point pp1, pp2;
  point p1 = point(0, 0);
  point p2 = point(1, 10);

  parallelShift(p2, p1, pp1, pp2, 10);

  cout << "(" << pp1.x << "," << pp1.y << ")" << "(" << pp2.x << "," << pp2.y << ")" << endl;

  cout << getArea( point( 0, 0 ), point(0, -3 ), point( 3, 0 ) ) << endl;
}









