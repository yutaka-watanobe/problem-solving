// 10823:Of Circles and Squares:2.5:Geometry, Circle + Square
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)
#define EPS 1e-12
#define MAX 100

bool eq(double a, double b){
  return fabs(a-b)<EPS;
}

class Obj{
public:
  string type;
  double x, y, l;
  int r, g, b;
  Obj(string t="", double x=0, double y=0, double l=0, int r=0, int g=0, int b=0): type(t), x(x), y(y), l(l), r(r), g(g), b(b){}

  bool circleOn(double px, double py){
    double d = sqrt((px-x)*(px-x)+(py-y)*(py-y));
    return eq(d, l);
  }
  bool circleIn(double px, double py){
    double d = sqrt((px-x)*(px-x)+(py-y)*(py-y));
    return d < l;
  }
  bool squareOn(double px, double py){
    if ( eq(py, y) || eq(py, y+l) ){
      if ( eq(px, x) || eq(px, x+l) || (x < px && px < x+l) ) return true;
    } else if ( eq(px, x) || eq(px, x+l) ){
      if ( eq(py, y) || eq(py, y+l) || (y < py && py < y+l) ) return true;
    }
    return false;
  }
  bool squareIn(double px, double py){
    return x < px && px < x+l && y < py && py < y+l ;
  }

};

void printColor(double x, double y, int R, Obj obj[MAX]){
  int n = 0;
  int sr = 0, sg = 0, sb = 0;
  rep(i, R){
    if ( obj[i].type == "CIRCLE" ){
      if ( obj[i].circleOn(x, y) ){
	cout << "(0, 0, 0)" << endl; return;
      } else if ( obj[i].circleIn(x, y) ){
	sr += obj[i].r;
	sg += obj[i].g;
	sb += obj[i].b;
	n++;
      }
    } else if ( obj[i].type == "SQUARE"){
      if ( obj[i].squareOn(x, y) ){
	cout << "(0, 0, 0)" << endl; return;
      } else if ( obj[i].squareIn(x, y) ){
	sr += obj[i].r;
	sg += obj[i].g;
	sb += obj[i].b;
	n++;
      }
    } else { assert(false); }
  }
  if ( n == 0 ){
    cout << "(255, 255, 255)" << endl; return;
  }

  int ir = (int)(1.0*sr/n + 0.5);
  int ig = (int)(1.0*sg/n + 0.5);
  int ib = (int)(1.0*sb/n + 0.5);

  cout << "(" << ir << ", " << ig << ", " << ib << ")" << endl;
}

void compute(){
  int R, P, r, g, b;
  Obj obj[MAX];
  string type;
  double x, y, l;
  cin >> R >> P;
  rep(i, R){
    cin >> type >> x >> y >> l >> r >> g >> b;
    obj[i] = Obj(type, x, y, l , r, g, b);
  }
  rep(i, P){
    cin >> x  >> y ;
    printColor(x, y, R, obj);
  }
}

main(){
  int tcase; cin >> tcase;
  rep(t, tcase) {
    if ( t ) cout << endl;
    cout << "Case " << t+1 << ":" << endl;
    compute();
  }
}





