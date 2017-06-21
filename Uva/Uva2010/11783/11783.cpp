// 11783:Nails:2.5:Geometry, Segment Intersection
#include<iostream>
#include<cfloat>
#include<cassert>
#include<cmath>
#include<vector>

using namespace std;

#define rep(i, n) for ( int i = 0; i < n; i++ )
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

static const int CIRCLE_NON = 0;
static const int CIRCLE_OUT = 1;
static const int CIRCLE_IN = 2;
static const int CIRCLE_CROSS = 3;

class Circle{
    public:
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0): c(c), r(r){}
};



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

bool isOrthogonal( Vector a, Vector b ){
     return equals( dot(a, b), 0.0 );
}

bool isOrthogonal( Point a1, Point a2, Point b1, Point b2 ){
    return isOrthogonal( a1 - a2, b1 - b2 );
}

bool isOrthogonal( Segment s1, Segment s2 ){
    return equals( dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0 );
}

bool isParallel( Vector a, Vector b ){
    return equals( cross(a, b), 0.0 );
}

bool isParallel( Point a1, Point a2, Point b1, Point b2){
    return isParallel( a1 - a2, b1 - b2 );
}

bool isParallel( Segment s1, Segment s2 ){
    return equals( cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0 );
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

// 0 <= a <= 360
double getAngleTheta(Point p){
    double polar = atan2(p.y, p.x);
    double rad = (dle(0, polar))? polar : 2*PI+polar;
    return rad*180.0/acos(-1);
}
// 0 <= a <= 2pi
double getAngle(Point p){
    double polar = atan2(p.y, p.x);
    return (dle(0, polar))? polar : 2*PI+polar;
}

double getAngle(Vector v1, Vector v2 ){

}

int isIntersect(Circle c1, Circle c2){
    double d = abs(c1.c - c2.c);
    if ( c1.r + c2.r < d ) return CIRCLE_NON; // no overlap
    if ( d + c2.r < c1.r ) return CIRCLE_IN;  // c1 includes c2
    if ( d + c1.r < c2.r ) return CIRCLE_OUT;  // c2 includes c1
    return CIRCLE_CROSS;
}

double getDistanceLP(Line s, Point p){ 
    return abs(cross(s.p2 - s.p1, p - s.p1)/abs(s.p2 - s.p1));
}

double arg(Vector p){
    return atan2(p.y, p.x);
}



pair<Point, Point> getCrossPoints(Circle c1, Circle c2){
    assert( isIntersect( c1, c2 ) );
    double d = abs(c1.c - c2.c);
    double a = acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c+polar(c1.r, t+a), c1.c+polar(c1.r, t-a));
}

bool isIntersect( Circle c1, Line l ){
    double d = getDistanceLP(l, c1.c);
    return ( equals(d, c1.r) || d < c1.r );
}

pair<Point, Point> getCrossPoints(Circle c1, Line l ){
    assert( isIntersect( c1, l ) );
    double d = getDistanceLP(l, c1.c);
    Point v = l.p2 - l.p1;
    if ( ccw(l.p1, l.p2, c1.c) == COUNTER_CLOCKWISE ){
	//v = polar(c1.r, arg(v)-acos(-1)/2);
	v = polar(abs(v), arg(v)-acos(-1)/2);
    } else {
	//v = polar(c1.r, arg(v)+acos(-1)/2);
	v = polar(abs(v), arg(v)+acos(-1)/2);
    }
    double th = acos(d/c1.r);
    Point v1 = polar(c1.r, arg(v) + th );
    Point v2 = polar(c1.r, arg(v) - th );
    return make_pair(c1.c+v1, c1.c+v2);
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

bool yxCmp( const Point &p1, const Point &p2 ) {
    return (p1.y == p2.y) ? p1.x < p2.x : p1.y < p2.y;
}

class PolarAngleCmp{
    public:
    Point o;
    PolarAngleCmp( Point o): o(o){}
    bool operator()( const Point &p1,  const Point &p2) const {
	Vector a = Vector(p1.x-o.x, p1.y-o.y); // p1 - o
	Vector b = Vector(p2.x-o.x, p2.y-o.y); // p2 - o
	double c = cross(a, b);
	if ( c == 0 ) return abs(a) < abs(b);
	return c > 0;
    }
};

Polygon grahamScan( Polygon s ){
    Polygon h;
    Point lm = *min_element(s.begin(), s.end(), yxCmp);
    sort(s.begin(), s.end(), PolarAngleCmp(lm));
    for ( int i = 0; i <= 2; i++ ) h.push_back(s[i]);
    for ( int i = 3; i < s.size(); i++ ){
	while( h.size() >= 2 && ccw(h[h.size()-2], h.back(), s[i]) == CLOCKWISE )
	    h.pop_back();
	h.push_back(s[i]);
    }
    return h;
}


/*
 * Area of Triangle
 * if area < 0 --> ClockWise
 * else if --> Anti- ClockWise
 * Solved 10112
 */
double getArea(Point p1, Point p2, Point p3){
    return abs(0.5 * ((p3.y-p1.y)*(p2.x-p1.x)-(p2.y-p1.y)*(p3.x-p1.x)));
}
/**
 * Area of polygon
 * if area < 0 --> ClockWise
 * else if --> Anti- ClockWise
 * Solved 10406 need veri
 */
double getArea(Polygon p){
    double sum = 0.0;
    for(int i = 0; i < p.size(); i++){
	sum += cross(p[i], p[(i+1)%p.size()]);
    }
    return abs(sum/2);
}


// verified 1283
Segment shift(Segment s, double d ){
    Vector v = polar(d, arg(s.p2 - s.p1)+PI/2 );
    Segment m = Segment(s.p1 + v, s.p2 + v );
    return m;
}

// it does not work if p is on edges of pol
bool isInside(Polygon pol, Point p){
    double a = 0.0;
    for ( int i = 0; i < pol.size(); i++ ){
	a += getAngle(pol[i] - p, pol[(i+1)%pol.size()] - p );
    }
    cout << a << endl;
    return equals(fabs(a), 2*PI);
}

#define MAX 1000

int compute(Segment S[MAX], int n){
  bool isCross[MAX];
  rep(i, n) isCross[i] = false;

  int sum = 0;
  for ( int i = 0; i < n-1; i++ ){
    for ( int j = i+1; j < n; j++ ){
      if ( isIntersect(S[i], S[j]) ){
	sum++;
	isCross[i] = isCross[j] = true;
      }
    }
  }
  rep(i, n) if ( !isCross[i] ) sum += 2;
  return sum;
}

int main(){
  Segment S[MAX];
  double x1, y1, x2, y2;
  int n;
  while( cin >> n && n ){
    rep(i, n){
      cin >> x1 >> y1 >> x2 >> y2;
      S[i] = Segment(Point(x1, y1), Point(x2, y2));
    }
    cout << compute(S, n) << endl;
  }

  return 0;
}
