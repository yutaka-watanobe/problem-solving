// @JUDGE_ID:  17051CA  10112  C++
// @begin_of_source_code
/* Geometory */
/* 点の集合から３つの点を選び,面積が最大のものを探す */
/* ただし、中に点を含んではならない */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#include<cmath>

#define LEFT 1
#define RIGHT -1
#define ON 2

class Point{
 public:
  string name;
  double x, y;
  Point(){}
  Point(string name, int x, int y): name(name), x(x), y(y){}
};

int cross_product(Point p0, Point p1, Point p2){
  double dx1, dy1, dx2, dy2;

  dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
  dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;

  if(dx1*dy2 > dy1*dx2) return LEFT;
  if(dx1*dy2 < dy1*dx2) return RIGHT;

  /* same line */
  if((dx1*dx2 < 0) || (dy1*dy2 < 0)) return 0; /* p2--p0--p1 */
  if((dx1*dx1+dy1*dy1)<(dx2*dx2+dy2*dy2)) return 0; /* p0--p1--p3 */

  return ON; /* p0--p2--p1 */
}

int n;
vector<Point> v;

int read(){
  v.clear();
  cin >> n;
  if(n==0) return 0;
  string c;
  double x, y;
  for(int i=0; i<n; i++){
    cin >> c >> x >> y;
    v.push_back(Point(c, x, y));
  }
  return 1;
}

bool inside(Point p1, Point p2, Point p3){

  Point t; /* target */
  for(int i=0; i<v.size(); i++){
    t = v[i];
    if(t.name != p1.name && t.name != p2.name && t.name != p3.name){
      int cp1, cp2, cp3;
      cp1 =  cross_product(p1, p2, t);
      cp2 =  cross_product(p2, p3, t);
      cp3 =  cross_product(p3, p1, t);
      if((cp1==LEFT && cp2==LEFT && cp3==LEFT) ||
	 (cp1==RIGHT && cp2==RIGHT && cp3==RIGHT) ||
	 cp1==ON || cp2==ON || cp3==ON){
	return true;
      }
	 
    }
  }
  return false;
}

double getArea(Point p1, Point p2, Point p3){
  return abs(0.5 * ((p3.y-p1.y)*(p2.x-p1.x)-(p2.y-p1.y)*(p3.x-p1.x)));
}

void work(){
  
  Point p1, p2, p3;
  double M = 0;
  double area;
  string power = "";
  for(int i=0; i<n-2; i++){
    for(int j=i+1; j<n-1; j++){
      for(int k=j+1; k<n; k++){
	p1 = v[i]; p2 = v[j]; p3 = v[k];
	area = getArea(p1, p2, p3);
	if(M<area){
	  if(!inside(p1, p2, p3)){
	    M = area;
	    power = p1.name + p2.name + p3.name;
	  }
	}
      }
    }
  }
  sort(power.begin(), power.end());
  cout << power << endl;
}

main(){
  while(read()) work();
}
// @end_of_source_code
