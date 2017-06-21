// @JUDGE_ID:  17051CA  476  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

#define LEFT 0
#define RIGHT 1
#define ON 10

struct Point{
  double x, y;
};

int point_in(Point p0, Point p1, Point p2){
  double dx1, dy1, dx2, dy2;
//  cout << "check (" << p0.x << "," << p0.y << ") (" <<  p1.x << "," << p1.y << ") (" <<  p2.x << "," << p2.y << ")";
  dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
  dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;

  if(dx1*dy2 > dy1*dx2) return LEFT;
  if(dx1*dy2 < dy1*dx2) return RIGHT;

  return ON;
}

class Rectangle{
 public:
  vector<Point> r;
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



vector<Rectangle> rect;
vector<Point> point;

int read(){
  char c;
  double x1, y1, x2, y2;
  
  Point p;

  while(1){
    cin >> c;
    if(c=='*') break;
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
      rect.push_back(rec);
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

  for(int i=0; i<rect.size(); i++){
    Rectangle r = rect[i];
    
    for(int j=0; j<point.size(); j++){
      if(r.contain(point[j])){
	contain[j].push_back(i);
      }
    }
  }

  for(int i=0; i<point.size(); i++){
    if(contain[i].size()==0){
      cout << "Point " << i+1 << " is not contained in any figure" << endl;
    }else{
      for(int j=0; j<contain[i].size(); j++){
	cout << "Point " << i+1 << " is contained in figure " << contain[i][j]+1 << endl;
      }
    }
  }

}

main(){
  read();
  work();
}
// @end_of_source_code
