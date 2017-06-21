#include<iostream>
#include<cmath>
#include<vector>
#include<float.h>
#include<set>

using namespace std;
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

    bool operator == ( const point &p ) const{
	return x == p.x && y == p.y;
    }

    bool operator < ( const point &p ) const{
	if ( x == p.x ) return y < p.y;
	return x < p.x;
    }
};

int direction(point pi, point pj, point pk){
  /* (pk - pi)*(pj - pi) */
  return (int)((pk.x - pi.x)*(pj.y - pi.y) - (pj.x - pi.x)*(pk.y - pi.y));
}

double dist(const point &p1, const point &p2){
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
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
bool segments_intersect(const point &p1, const point &p2, 
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

double getPolygonArea(vector<point> p){
  double sum = 0;
  for(int i=0; i<p.size()-1; i++){
    sum += p[i].x*p[i+1].y - p[i+1].x*p[i].y;
  }
  sum += p[p.size()-1].x*p[0].y - p[0].x*p[p.size()-1].y;
  return abs(sum/2);
}

point P[3][2];

double getArea(){
    set<point> sv;
    vector<point> v;
    for ( int i = 0; i < 2; i++ ){
	for ( int j = i+1; j < 3; j++ ){
	    if ( segments_intersect( P[i][0], P[i][1], P[j][0], P[j][1] )){
		sv.insert(intersection(P[i][0], P[i][1], P[j][0], P[j][1] ));
	    }
	}
    }

    set<point>::iterator it;
    for ( it = sv.begin(); it != sv.end(); it++ ) v.push_back(*it);

    if ( v.size() < 3 ) return -1;
    return getPolygonArea(v);
}

int main(){

    while(1){
	cin >> P[0][0].x >> P[0][0].y >> P[0][1].x >> P[0][1].y;
	if ( P[0][0].x == 0 && P[0][0].y == 0 &&
	     P[0][1].x == 0 && P[0][1].y == 0  ) break;
	     
	cin >> P[1][0].x >> P[1][0].y >> P[1][1].x >> P[1][1].y;
	cin >> P[2][0].x >> P[2][0].y >> P[2][1].x >> P[2][1].y;

	double area = getArea();
	//	printf("%lf  ", area);
	if ( area <= 0 ) cout << "kyo" << endl;
	else if ( 0 < area && area < 100000 ) cout << "syo-kichi" << endl;
	else if ( 100000 <= area && area < 1000000 ) cout << "kichi" << endl;
	else if ( 1000000 <= area && area < 1900000 ) cout << "chu-kichi" << endl;
	else if ( 1900000 <= area ) cout << "dai-kichi" << endl;
	
    }
}
