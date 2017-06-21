// @JUDGE_ID:  17051CA  273  C++
// @begin_of_source_code
/* Geometory */
/* segment intersection + Disjoint Set */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

class DisjointSet{
 public:
  vector<int> rank, p;

  DisjointSet(int size){
    rank.resize(size, 0);
    p.resize(size, 0);
  }

  void makeSet(int x){
    p[x] = x;
    rank[x] = 0;
  }

  void merge(int x, int y){
    link(findSet(x), findSet(y));
  }

  void link(int x, int y){
    if(rank[x] > rank[y]){
      p[y] = x;
    }else{   
      p[x] = y;
      if(rank[x] == rank[y]){
	rank[y] = rank[y] + 1;
      }
    }
  }

  int findSet(int x){
    if(x != p[x]){
      p[x] = findSet(p[x]);
    }
    return p[x];
  }
};

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

class seg{
 public:
  double x1, y1, x2, y2;
  seg(){}
  seg(double x1, double y1, double x2, double y2): x1(x1), y1(y1), x2(x2), y2(y2){}
};

int direction(point pi, point pj, point pk){
  /* (pk - pi)*(pj - pi) */
  return (int)((pk.x - pi.x)*(pj.y - pi.y) - (pj.x - pi.x)*(pk.y - pi.y));
}

bool on_segment(point pi, point pj, point pk){
  if( min(pi.x, pj.x) <= pk.x && pk.x <= max(pi.x, pj.x) &&
      min(pi.y, pj.y) <= pk.y && pk.y <= max(pi.y, pj.y)) return true;
  else return false;
}

#define LEFT 1
#define RIGHT (-1)
#define ONBACK (-1)
#define ONFRONT 1
#define ON 0

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

int n;
vector<seg> v;

int read(){
  double x1, y1, x2, y2;
  cin >> n;
  v.clear();
  for(int i=0; i<n; i++){
    cin >> x1 >> y1 >> x2 >> y2;
    v.push_back(seg(x1, y1, x2, y2));
  }
}

void work(){
  DisjointSet dset = DisjointSet(n);
  for(int i=0; i<n; i++){
    dset.makeSet(i);
  }

  seg seg1, seg2;

  for(int i=0; i<v.size()-1; i++){
    for(int j=i+1; j<v.size(); j++){
      seg1 = v[i];
      seg2 = v[j];
      if(segments_intersect(point(seg1.x1, seg1.y1), 
			    point(seg1.x2, seg1.y2),
			    point(seg2.x1, seg2.y1),
			    point(seg2.x2, seg2.y2))){
	dset.merge(i, j);
      }
    }
  }
  
  int a, b;
  while(1){
    cin >> a >> b;
    if(a==0 && b==0) return;
    a--; b--;
    if(dset.findSet(a)==dset.findSet(b)){
      cout << "CONNECTED" << endl;
    }else{
      cout << "NOT CONNECTED" << endl;
    }
  }
}

main(){
  int testCase;
  cin >> testCase;
  for(int i=0; i<testCase; i++){
    if(i) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
