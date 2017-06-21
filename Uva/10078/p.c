// @JUDGE_ID:  17051CA  10078  C++
// @begin_of_source_code
/* Geometory */
/* is Convex ?? */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<math.h>
#include<float.h>
#define LEFT 1
#define RIGHT 0
#define ON 2
#define IN 1
#define FRONT 3
#define BACK 4

class Point{
 public:
  double x, y;
  Point(){}
  Point(int x, int y): x(x), y(y){}
};

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
  if((dx1*dx2 < 0) || (dy1*dy2 < 0)) return BACK; /* p2--p0--p1 */
  if((dx1*dx1+dy1*dy1)<(dx2*dx2+dy2*dy2)) return FRONT; /* p0--p1--p2 */

  return ON; /* p0--p2--p1 */
}


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

int n;

int read(){
  cin >> n;
  if(n==0) return 0;
  return 1;
}

void work(){
  double x, y;
  vector<Point> p;

  for(int i=0; i<n; i++){
    cin >> x >> y;
    p.push_back(Point(x, y));
  }

  bool isConvex = is_convex(p);

  if(!isConvex) cout << "Yes" << endl;
  else cout << "No" << endl;
}

main(){
  while(read()) work();
}
// @end_of_source_code
