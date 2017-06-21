// @JUDGE_ID:  17051CA  109  C++
// @begin_of_source_code
/* Geometory */
/* Convex Hull + Interior ditection + Polygon Area */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<math.h>
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
  bool operator==(const point &p) const {
    return deq(x, p.x) && deq(y, p.y);
  }
};

/*
 * 多角形オブジェクト
 */
class polygon {
 public:
  vector<point> v;
  point l, u;

  polygon(){}
  polygon(const polygon &p): v(p.v){}
  void push_back(const point &p){
    v.push_back(p);
    find_most();
  }
  void clear(){ v.clear(); }
  void resize(int n){ v.resize(n); }
  int size(){ return v.size(); }
  /* i >= -size()であること。 */
  point &operator[](int i){ return v[(i+size())%size()]; }
  void find_most(){
    if(size()==0) return;

    u = l = v[0];
    for(int i=1; i<size(); i++){
      if(deq(v[i].y, l.y) && v[i].x<l.x || v[i].y<l.y)
	l = v[i];
      if(deq(v[i].y, u.y) && v[i].x<u.x || v[i].y>u.y)
	u = v[i];
    }
  }
  
  double getPolygonArea(){
    double sum = 0;
    for(int i=0; i<v.size()-1; i++){
      sum += v[i].x*v[i+1].y - v[i+1].x*v[i].y;
    }
    sum += v[v.size()-1].x*v[0].y - v[0].x*v[v.size()-1].y;
    return fabs(sum/2);
  }

};

/*
 * p1とp2の距離。
 */
double dist(const point &p1, const point &p2){
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

/*
 * 線分(p, o)と線 y=o.y との（反時計回りの）角度。
 * 注意: 返り値は [0, 2*M_PI)である。
 */
double angle(const point &p, point o=point(0, 0)){
  double a = atan2(p.y-o.y, p.x-o.x);
  
  if(dle(0, a)) return a;
  return 2*M_PI+a;
}

/*
 * 線分(p1, o)から線分(p2, o)への（反時計回りの）角度。
 * 要件: 関数 angle(const point&, point)
 */
double angle(const point &p1, const point &p2, const point &o){
  double a = angle(p2, o)-angle(p1, o);
  
  if(dle(0, a)) return a;
  return 2*M_PI+a;
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

int is_left_turn(const point &p0, const point &p1, const point &p2){
  double tmp = (p2-p0)*(p1-p0);

  if(fabs(tmp)<EPS) return -1;
  return tmp<0;
}

class cmp_by_angle: binary_function<const point&, const point&, bool>{
 public:
  point o;

  cmp_by_angle(const point o=point(0, 0)): o(o){}
  bool operator()(const point &p1, const point &p2) const {
    double a = angle(p2, o)-angle(p1, o);

    if(fabs(a)<EPS){
      return dist(p1, o)<dist(p2, o);
    }
    return a>0;
  }
};

/**
 * create convex hull
 * Solved 218, 10135
 */
void convex(polygon &s, polygon &t){
  vector<point> v(s.v);

  s.find_most();
  sort(v.begin(), v.end(), cmp_by_angle(s.l));
  
  t.clear();
  for(int i=0; i<3; i++) t.push_back(v[i]);
  for(int i=3; i<v.size(); i++){
    while(is_left(t[t.size()-2], t.v.back(), v[i])==0 && t.size()>1)
      t.v.pop_back();
    t.push_back(v[i]);
  }
  t.find_most();
}

vector<polygon> I;
vector<polygon> K;
vector<point> M;

int read(){
  int N;
  double x, y;

  while(1){
    cin >> N;
    if(N==-1) break;
    polygon p;
    for(int i=0; i<N; i++){
      cin >> x >> y;
      p.push_back(point(x, y));
    }
    I.push_back(p);
  }

  while(cin >> x >> y){
    M.push_back(point(x, y));
  }
  
}

void work(){
  K.clear();
  for(int i=0; i<I.size(); i++){
    polygon cvx;
    convex(I[i], cvx);
    K.push_back(cvx);
  }

  double area = 0;
  for(int i=0; i<K.size(); i++){
    polygon cvx = K[i];

    for(int m=0; m<M.size(); m++){

      for(int j=0; j<cvx.size()-1; j++){
	if(!is_left(cvx[j], cvx[j+1], M[m]) ){
	  goto next;
	}
      }
      if(!is_left(cvx[cvx.size()-1], cvx[0], M[m])) goto next;

      area += cvx.getPolygonArea();
      goto next_king;
    next:;
    }
  next_king:;
  }

  printf("%.2f\n", area);
}

main(){
  read();
  work();
}
// @end_of_source_code
