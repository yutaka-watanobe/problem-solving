// @JUDGE_ID:  17051CA  478  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

#define LEFT -1
#define RIGHT 1
#define ON 2
#define IN 1

struct Point{
  double x, y;
};

int point_in(Point p0, Point p1, Point p2){
  double dx1, dy1, dx2, dy2;
  dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
  dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;
  if(dx1*dy2 > dy1*dx2) return LEFT;
  if(dx1*dy2 < dy1*dx2) return RIGHT;
  return ON;
}

int circle_in(Point c, double r, Point p){
  double R = (c.x-p.x)*(c.x-p.x)+(c.y-p.y)*(c.y-p.y);
  if( R < r*r ) return IN;
  else if( R==r*r) return ON;

  return -1;
}

class Rectangle{
 public:
  vector<Point> r;
  int id;

  Rectangle(vector<Point> p){ r = p;};

  bool contain(Point p){
    int sum = 0;
    int p1, p2;
    for(int i=0; i<4; i++){
      p1 = i;
      p2 = i+1;
      if(i==3) p2 = 0;
      sum += point_in(r[p1], r[p2], p);
    }
    if(sum==4) return true;
    else return false;
  }
};

class Triangle{
 public:
  vector<Point> r;
  int id;

  Triangle(vector<Point> p){ r = p;};

  bool contain(Point p){
    if(point_in(r[0], r[1], p) + point_in(r[0], r[2], p)==0 && 
       point_in(r[1], r[0], p) + point_in(r[1], r[2], p)==0 ){
      return true;
    }else{ return false;}
  }
};

class Circle{
 public:
  Point c;
  double r;
  int id;
  Circle(Point p, double d){c = p; r = d;}

  bool contain(Point p){
    if( circle_in(c, r, p)==IN) return true;
    else return false;
  }
};


vector<Rectangle> rect;
vector<Circle> circle;
vector<Triangle> triangle;
vector<Point> point;

int read(){
  char c;
  double x1, y1, x2, y2, x3, y3, rad;
  
  Point p;

  int i = 1;
  while(1){
    cin >> c;
    if(c=='*') break;
    else if(c=='t'){
      cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      vector<Point> r;
      p.x = x1; p.y = y1;
      r.push_back(p);
      p.x = x2; p.y = y2;
      r.push_back(p);
      p.x = x3; p.y = y3;
      r.push_back(p);
      Triangle tri = Triangle(r);
      tri.id = i++;
      triangle.push_back(tri);
    }
    else if(c=='r'){
      cin >> x1 >> y1 >> x2 >> y2;
      vector<Point> r;
      p.x = x1; p.y = y1;
      r.push_back(p);
      p.x = x2; p.y = y1;
      r.push_back(p);
      p.x = x2; p.y = y2;
      r.push_back(p);
      p.x = x1; p.y = y2;
      r.push_back(p);
      Rectangle rec = Rectangle(r);
      rec.id = i++;
      rect.push_back(rec);
    }else if(c=='c'){
      cin >> x1 >> y1 >> rad;
      p.x = x1; p.y = y1;
      Circle cir = Circle(p, rad);
      cir.id = i++;
      circle.push_back(cir);
    }
  }
  
  while(1){
    cin >> x1 >> y1;
    if(x1==9999.9 && y1==9999.9) break;
    p.x = x1; p.y = y1;
    point.push_back(p);
  }

  return 1;
}

void work(){
  vector<vector<int> > contain;
  contain.resize(point.size());

  for(int i=0; i<point.size(); i++){
    for(int j=0; j<rect.size(); j++){
      Rectangle r = rect[j];
      if(r.contain(point[i])){
	contain[i].push_back(r.id);
      }
    }

    for(int j=0; j<circle.size(); j++){
      Circle c = circle[j];
      if(c.contain(point[i])){
	contain[i].push_back(c.id);
      }
    }

    for(int j=0; j<triangle.size(); j++){
      Triangle t = triangle[j];
      if(t.contain(point[i])){
	contain[i].push_back(t.id);
      }
    }
  }

  for(int i=0; i<point.size(); i++){
    if(contain[i].size()==0){
      cout << "Point " << i+1 << " is not contained in any figure" << endl;
    }else{
      sort(contain[i].begin(), contain[i].end());
      for(int j=0; j<contain[i].size(); j++){
	cout << "Point " << i+1 << " is contained in figure " << contain[i][j] << endl;
      }
    }
  }

}

main(){
  read();
  work();
}
// @end_of_source_code
