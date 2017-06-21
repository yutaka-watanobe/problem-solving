// @JUDGE_ID:  17051CA  142  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define LEFT 0
#define RIGHT 1
#define ON 1
#define IN 1

struct Point{
  double x, y;
};

class Icon{
 public:
  Point p;
  Icon(Point a){p = a;}

};

class Rectangle{
 public:
  vector<Point> r;
  Rectangle(vector<Point> v){ r = v;}

};

class Mouse{
 public:
  Point p;
  Mouse(Point a){p = a;}
};

int cross_product(Point p0, Point p1, Point p2){
  double dx1, dy1, dx2, dy2;

  dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
  dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;

  if(dx1*dy2 > dy1*dx2) return RIGHT;
  if(dx1*dy2 < dy1*dx2) return LEFT;

  return ON;
}

vector<Icon> icon;
vector<Rectangle> rect;
vector<Mouse> mouse;
string label = "ABCDEFGHIGKLMNOPQRSTUVWXYZ";

int read(){
  char ch;
  int x1, x2, y1, y2;
  Point p;

  while(1){
    cin >> ch;
    if(ch=='#') return 0;

    if(ch=='I'){
      cin >> x1 >> y1;
      p.x = x1; p.y = y1;
      Icon ic = Icon(p);
      icon.push_back(ic);
    }else if(ch=='R'){
      cin >> x1 >> y1 >> x2 >> y2;
      vector<Point> v;
      p.x = x1; p.y = y1;
      v.push_back(p);
      p.x = x2; p.y = y1;
      v.push_back(p);
      p.x = x2; p.y = y2;
      v.push_back(p);
      p.x = x1; p.y = y2;
      v.push_back(p);
      Rectangle r = Rectangle(v);
      rect.push_back(r);
    }else if(ch=='M'){
      cin >> x1 >> y1;
      p.x = x1; p.y = y1;
      Mouse m = Mouse(p);
      mouse.push_back(m);
    }
  }

  return 1;
}

bool checkRect(Point p, char &ch){

  bool contain = false;
  
  for(int i=0; i<rect.size(); i++){
    Rectangle rec = rect[i];
    int sum = 0;
    /*cout << p.x << ", " << p.y << endl; */
    int k;
    for(int l=0; l<4; l++){
      if(l==3)	{
	k =  cross_product(rec.r[l], rec.r[0], p);
	/* cout << rec.r[l].x << ", " << rec.r[l].y << "---" << rec.r[0].x << ", " << rec.r[0].y << "   " << k <<endl; */
      } else {
	k =  cross_product(rec.r[l], rec.r[l+1], p);
	/* cout << rec.r[l].x << ", " << rec.r[l].y << "---" << rec.r[l+1].x << ", " << rec.r[l+1].y << "   " << k <<endl; */
      }
      sum += k;
    }
    /* cout << "sum " << sum << endl; */
    if(sum==4){
      contain = true;
      ch = label[i];
    }
  }
  return contain;
}

void checkIcon(Point p, vector<int> &v){
  double d, m;
  m = 10000;
  vector<double> dtable;
  dtable.resize(icon.size());
  for(int i=0; i<icon.size(); i++){
    Icon ic = icon[i];
    d = sqrt( (p.x-ic.p.x)*(p.x-ic.p.x) + (p.y-ic.p.y)*(p.y-ic.p.y));
    dtable[i] = d;
    if(d<m) m = d;
  }

  for(int i=0; i<dtable.size(); i++){
    if(dtable[i]==m){
      v.push_back(i+1);
    }
  }

  sort(v.begin(), v.end());
}

void work(){
  char ch;
  for(int i=0; i<mouse.size(); i++){
    Mouse ms = mouse[i];
    
    /* check rect */
    if(checkRect(ms.p, ch)){
      cout << ch << endl;
      continue;
    }

    /* check icon */
    vector<int> iconList;
    checkIcon(ms.p, iconList);
    for(int j=0; j<iconList.size(); j++){
      printf("%3d", iconList[j]);
    }
    cout << endl;


  }



}

main(){
  read();
  work();
}
// @end_of_source_code
