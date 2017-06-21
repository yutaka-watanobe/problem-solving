/*********************
 * Geometory General *
 *********************/

#include<stdio.h>
#define IN 1

#define LEFT 1
#define RIGHT (-1)
#define ONBACK (-1)
#define ONFRONT 1
#define ON 0

class Point{
 public:
  char name;
  double x, y;
  Point(){}
  Point(char name, int x, int y) name(name), x(x), y(y){}
}

/**
 * Solved 476, 10112
 */
int cross_product(Point p0, Point p1, Point p2){
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
  if((dx1*dx1+dy1*dy1)<(dx2*dx2+dy2*dy2)) return 0; /* p0--p1--p2 */

  return ON; /* p0--p2--p1 */
}

int crossProduct(point p0, point p1, point p2){
  double dx1, dy1, dx2, dy2;

  dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
  dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;

  /* p0--p1 に対してp2が左にある(反時計回り) */
  if(dx1*dy2 > dy1*dx2) return LEFT; 
  /* p0--p1 に対してp2が右にある(時計回り) */
  if(dx1*dy2 < dy1*dx2) return RIGHT;

  /* same line */
  /* 問題に応じて返り値を調整すること！！ */
  if((dx1*dx2 < 0) || (dy1*dy2 < 0)) return ONBACK; /* p2--p0--p1 */
  if((dx1*dx1+dy1*dy1)<(dx2*dx2+dy2*dy2)) return ONFRONT; /* p0--p1--p3 */

  return ON; /* p0--p2--p1 */
}

int segments_intersect(const point &p1, const point &p2, 
		 const point &p3, const point &p4){

  return ( (crossProduct(p1, p2, p3) * crossProduct(p1, p2, p4)) <= 0 &&
	   (crossProduct(p3, p4, p1) * crossProduct(p3, p4, p2)) <= 0 );
}

/**
 * ポイントの集合が凸であるか
 * 時計回りまたは反時計回りにならんでいる必要がある
 * Solved 10078
 */
bool is_convex(vector<Point> p){

  int pre = cross_product(p[p.size()-1], p[0], p[1]);
  int dir;
  for(int i=0; i<p.size()-2; i++){
    dir = cross_product(p[i], p[i+1], p[i+2]);
    if(pre != dir) return false;
    pre = dir;
  }
  dir = cross_product(p[p.size()-2], p[p.size()-1], p[0]);
  if(pre != dir) return false;

  return true;
}

int circle_in(Point c, double r, Point p){
  double R = (p.x-c.x)*(p.x-c.x)+(p.y-c.y)*(p.y-c.y);
  if( R < r*r ) return IN;
  else if( R==r*r) return ON;

  return -1
}

/**
 * x 座標最大, y 座標最小の点を探す
 */
int getMost(vector<point> p){
  int minIndex;
  int minY, maxX;
  
  minY = p[0].y; maxX = p[0].x;
  minIndex = 0;
  for ( int i = 0; i < p.size(); i++ ){
    if ( minY > p[i].y || ( minY == p[i].y && maxX < p[i].x )){
      maxX = p[i].x; minY = p[i].y;
      minIndex = i
    }
  }
  return minIndex;
}
