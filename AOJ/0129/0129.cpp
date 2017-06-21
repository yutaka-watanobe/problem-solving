#include<iostream>
#include<cfloat>
#include<cassert>
#include<cmath>
#include<vector>

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

double arg(Vector p){
    return atan2(p.y, p.x);
}

double getDistanceLP(Line s, Point p){
    return abs(cross(s.p2 - s.p1, p - s.p1)/abs(s.p2 - s.p1));
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
	v = polar(abs(v), arg(v)-acos(-1)/2);
    } else {
	v = polar(abs(v), arg(v)+acos(-1)/2);
    }
    double th = acos(d/c1.r);
    Point v1 = polar(c1.r, arg(v) + th );
    Point v2 = polar(c1.r, arg(v) - th );
    return make_pair(c1.c+v1, c1.c+v2);
}

#define MAX 100

Circle C[MAX];
int n, m;

bool judge( Line l ){
    for ( int i = 0; i < n; i++ ){
	if ( !isIntersect(C[i], l) ) continue;
	pair<Point, Point> pp = getCrossPoints(C[i], l);
	if ( ccw(l.p1, l.p2, pp.first ) == ON_SEGMENT ||
	     ccw(l.p1, l.p2, pp.second ) == ON_SEGMENT ) return true;
    }
    return false;
}

main(){
    double x1, y1, x2, y2;
    while( cin >> n && n ){
	for ( int i = 0; i < n; i++ ){
	    cin >> C[i].c.x >> C[i].c.y >> C[i].r;
	}
	cin >> m;
	for ( int i = 0; i < m; i++ ){
	    cin >> x1 >> y1 >> x2 >> y2;
	    if ( judge( Line(Point(x1, y1), Point(x2, y2))) ) cout << "Safe" << endl;
	    else cout << "Danger" << endl;
	}
    }
}
