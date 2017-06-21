#include<iostream>
#include<cfloat>
#include<cassert>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define EPS (1e-8)
#define equals(a, b) (fabs((a) - (b)) < EPS )
#define dle(a, b) (equals(a, b) || a < b )

class Point{
    public:
    double x, y;
    
    Point ( double x = 0, double y = 0): x(x), y(y){}
    
    Point operator + ( Point p ){ return Point(x + p.x, y + p.y); }
    Point operator - ( Point p ){ return Point(x - p.x, y - p.y); }
    Point operator * ( double a ){ return Point(x*a, y*a); }
    Point operator / ( double a ){ return Point(x/a, y/a); }

    double abs() { return sqrt(norm());}
    double norm() { return x*x + y*y; }

    bool operator < ( const Point &p ) const {
	return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == ( const Point &p ) const {
	return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
    }
};

typedef Point Vector;

class Segment{
    public:
    Point p1, p2;
    Segment(Point s = Point(), Point t = Point()): p1(s), p2(t){}
};

typedef vector<Point> Polygon;

double norm( Vector a ){ return a.x*a.x + a.y*a.y; }
double abs( Vector a ){ return sqrt(norm(a)); }
Point polar( double a, double r ){ return Point(cos(r)*a, sin(r)*a);}
double getDistance( Vector a, Vector b ){ return abs(a - b); }
double dot( Vector a, Vector b ){ return a.x*b.x + a.y*b.y; }
double cross( Vector a, Vector b ){ return a.x*b.y - a.y*b.x; }

bool isOnSegment( Point a, Point b, Point c){
    if ( a == c || b == c ) return true;
    return (abs(a-c) + abs(c-b) < abs(a-b) + EPS );
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw( Point p0, Point p1, Point p2 ){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if ( cross(a, b) > EPS ) return COUNTER_CLOCKWISE;
    if ( cross(a, b) < -EPS ) return CLOCKWISE;
    if ( dot(a, b) < -EPS ) return ONLINE_BACK;
    if ( norm(a) < norm(b) ) return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool isIntersect(Point p1, Point p2, Point p3, Point p4){
    return ( ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
	     ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0 );
}

bool isIntersect(Segment s1, Segment s2){
    return isIntersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

Polygon andrewScan( Polygon s ){
    Polygon u, l;
    if ( s.size() < 3 ) return s;
    sort(s.begin(), s.end());
    u.push_back(s[0]);
    u.push_back(s[1]);
    l.push_back(s[s.size()-1]);
    l.push_back(s[s.size()-2]);
    int n;
    for ( int i = 2; i < s.size(); i++ ){
	for ( int n = u.size(); n >= 2 && ccw(u[n-2], u[n-1], s[i]) != CLOCKWISE; n--){
	    u.pop_back();
	}
	u.push_back(s[i]);
    }

    for ( int i = s.size()-3; i >= 0; i-- ){
	for ( int n = l.size(); n >= 2 && ccw(l[n-2], l[n-1], s[i]) != CLOCKWISE; n--){
	    l.pop_back();
	}
	l.push_back(s[i]);
    }
    reverse(l.begin(), l.end());
    for ( int i = u.size()-2; i >= 1; i-- ) l.push_back(u[i]);
    return l;
}

// convec polygon with conter clockwise
bool isInside(Polygon pol, Point p){
    for ( int i = 0; i < pol.size(); i++ ){
      if ( ccw(pol[i], pol[(i+1)%pol.size()], p) == CLOCKWISE) return false;
    }
    return true;
}

bool check(int n, int m, Polygon b, Polygon w){
  b = andrewScan(b);
  w = andrewScan(w);
  
    int t = b.size() + w.size();
    if ( t == 2 ) {
      return false;
    } else if ( t == 3 ){
      if ( b.size() == 1 ) return isOnSegment(w[0], w[1], b[0] );
      return isOnSegment(b[0], b[1], w[0]);
    } else if ( t == 4 ){
      if ( b.size() == 1 ) return isInside(w, b[0]);
      else if ( w.size() == 1 ) return isInside(b, w[0]);
      else return isIntersect(Segment(w[0], w[1]), Segment(b[0], b[1]));
    }
    
    for ( int i = 0; i < b.size(); i++ )
      if ( isInside(w, b[i]) ) return true;
    for ( int i = 0; i < w.size(); i++ )
      if ( isInside(b, w[i]) ) return true;
    for ( int i = 0; i < b.size(); i++ ){
      Segment s1 = Segment(b[i], b[(i+1)%b.size()]);
      for ( int j = 0; j < w.size(); j++ ){
	Segment s2 = Segment(w[j], w[(j+1)%w.size()]);
	if ( isIntersect(s1, s2) ) return true;
      }
    }
    return false;
}

int main(){
  int n, m;
  double x, y;
  while(1){
    cin >> n >> m;
    if ( n == 0 && m == 0 ) break;
    Polygon b, w;
    for ( int i = 0; i < n; i++ ){
      cin >> x >> y; b.push_back(Point(x, y));
    }
    for ( int i = 0; i < m; i++ ){
      cin >> x >> y; w.push_back(Point(x, y));
    }
    if ( check(n, m, b, w) ) cout << "NO" << endl;
    else cout << "YES" << endl;
  }
}
