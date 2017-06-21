#include<iostream>
#include<cfloat>
#include<cassert>
#include<cmath>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;

#define EPS (1e-8)
#define equals(a, b) (fabs((a) - (b)) < EPS )
#define dle(a, b) (equals(a, b) || a < b )

static const double PI = acos(-1);

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

typedef Segment Line;

typedef vector<Point> Polygon;

double norm( Vector a ){ return a.x*a.x + a.y*a.y; }
double abs( Vector a ){ return sqrt(norm(a)); }
Point polar( double a, double r ){ return Point(cos(r)*a, sin(r)*a);}
double getDistance( Vector a, Vector b ){ return abs(a - b); }
double dot( Vector a, Vector b ){ return a.x*b.x + a.y*b.y; }
double cross( Vector a, Vector b ){ return a.x*b.y - a.y*b.x; }

Point project( Segment s, Point p ){
    Vector base = s.p2 - s.p1;
    double t = dot(p - s.p1, base)/norm(base);
    return s.p1 + base*t;
}

Point reflect( Segment s, Point p ){
    return p + (project(s, p) - p)*2.0;
}

// verified by uoa2062
bool isOnSegment( Point a, Point b, Point c){
    if ( a == c || b == c ) return true;
    return (abs(a-c) + abs(c-b) < abs(a-b) + EPS );
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

// EPS can be 0
// need to check for 920, 833, 866
int ccw( Point p0, Point p1, Point p2 ){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if ( cross(a, b) > EPS ) return COUNTER_CLOCKWISE;
    if ( cross(a, b) < -EPS ) return CLOCKWISE;
    if ( dot(a, b) < -EPS ) return ONLINE_BACK;
    if ( norm(a) < norm(b) ) return ONLINE_FRONT;
    return ON_SEGMENT;
}

// intersect Segment p1-p2 and Segment p3-p4 ?
bool isIntersect(Point p1, Point p2, Point p3, Point p4){
    return ( ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
	     ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0 );
}

// intersect Segment s1 and Segment s2 ?
// verified by 920, 833, 866, uoa2062
bool isIntersect(Segment s1, Segment s2){
    return isIntersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

// verified by 920, 833, uoa2062
Point getCrossPoint(Segment s1, Segment s2){
    assert( isIntersect(s1, s2) );
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1/(d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1)*t;
}

Point getCrossPointLines( Line s1, Line s2){
    Vector a = s1.p2 - s1.p1;
    Vector base = s2.p2 - s2.p1;
    return s1.p1 + a * cross(base, s2.p1 - s1.p1)/cross(base, a);
}

double arg(Vector p){
    return atan2(p.y, p.x);
}

Polygon cutPolygon( Polygon P, Line l ){
    Polygon u;
    for ( int i = 0; i < P.size(); i++ ){
	Point a = P[i], b = P[(i+1)%P.size()];
	if ( ccw(l.p1, l.p2, a) != CLOCKWISE ) u.push_back(a);
	if ( ccw(l.p1, l.p2, a) * ccw(l.p1, l.p2, b) == -1 ){
	    u.push_back(getCrossPointLines(Segment(a, b), l));
	}
    }
    return u;
}

double getArea(Polygon p){
    double sum = 0.0;
    for(int i = 0; i < p.size(); i++){
	sum += cross(p[i], p[(i+1)%p.size()]);
    }
    return abs(sum/2);
}

Line getCutLine( Point p1, Point p2 ){
    Vector v = p2 - p1;
    v = polar(abs(v), arg(v)+PI/2.0);
    double dx = (p2.x + p1.x)/2.0;
    double dy = (p2.y + p1.y)/2.0;
    return Line(Point(dx, dy), Point(v.x+dx, v.y+dy));
}

vector<Polygon> getVoronoi( vector<Point> PV ){
  static const int  X_MIN = -1000000;
  static const int Y_MIN = -1000000;
  static const int X_MAX = 1000000;
  static const int Y_MAX = 1000000;
  vector<Polygon> V;
  for ( int i = 0; i < PV.size(); i++ ){
    Polygon P;
    P.push_back(Point(X_MIN, Y_MIN));
    P.push_back(Point(X_MAX, Y_MIN));
    P.push_back(Point(X_MAX, Y_MAX));
    P.push_back(Point(X_MIN, Y_MAX));
    for ( int j = 0; j < PV.size(); j++ ){
      if ( i == j ) continue;
      P = cutPolygon(P, getCutLine(PV[i], PV[j]));
    }
    V.push_back(P);
  }
  return V;
}

int main(){
  int N, M;
  double S[100];

  while(1){
    cin >> N >> M;
    if ( N == 0 && M == 0 ) break;
    vector<Point> P;
    int x, y, dx, dy, s;
    set<Point> ps;
    for ( int i = 0; i < N; i++ ){
      cin >> x >> y;
      P.push_back(Point(x, y));
      ps.insert(Point(x, y));
    }
    assert(ps.size()==N);
    vector<Polygon> G = getVoronoi(P);

    for ( int i = 0; i < N; i++ ) S[i] = 0;
    double maxscore = 0;

    for ( int i = 0; i < M; i++ ){
      cin >> x >> y >> dx >> dy >> s;
      Polygon sq;
      sq.push_back(Point(x-dx, y-dy));
      sq.push_back(Point(x+dx, y-dy));
      sq.push_back(Point(x+dx, y+dy));
      sq.push_back(Point(x-dx, y+dy));
      
      for ( int p = 0; p < N; p++ ){
	Polygon sx = sq;
	Polygon g = G[p];
	for ( int j = 0; j < g.size(); j++ ){
	  Line l = Line(g[j], g[(j+1)%g.size()]);
	  sx = cutPolygon(sx, l);
	}
	S[p] += s*getArea(sx)/(dx*2*dy*2);
      }
    }

    for ( int i = 0; i < N; i++ ) maxscore = max(maxscore, S[i]);

    printf("%.8lf\n", maxscore);
  }
}
