#include<iostream>
#include<cfloat>
#include<cmath>

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

bool circleIsInTriangle(Circle c, Point t[3] ){
    int ccw1 = ccw(t[0], t[1], c.c);
    int ccw2 = ccw(t[1], t[2], c.c);
    int ccw3 = ccw(t[2], t[0], c.c);
    if ( !(ccw1 == ccw2 && ccw2 == ccw3 ) ) return false;
    for ( int i = 0; i < 3; i++ ){
	Line l =  Line(t[i], t[(i+1)%3]);
	if ( c.r > getDistanceLP(l, c.c) ) return false;
    }
    return true;
}

bool triangleIsInCircle(Circle c, Point t[3] ){
    for ( int i = 0; i < 3; i++ ){
	if ( c.r < getDistance(t[i], c.c) ) return false;
    }
    return true;
}

bool isIntersect(Circle c, Point t[3]){
    for ( int i = 0; i < 3; i++ ){
	Line l =  Line(t[i], t[(i+1)%3]);
	if ( !isIntersect(c, l) ) continue;
	pair<Point, Point> pp = getCrossPoints(c, l);
	if ( ccw(l.p1, l.p2, pp.first) == ON_SEGMENT ) return true; 
	if ( ccw(l.p1, l.p2, pp.second) == ON_SEGMENT ) return true;
    }
    return false;
}

int main(){
    double x, y, r;
    Circle c;
    Point T[3];
    while(1){
	cin >> x >> y;
	if ( x == 0 && y == 0 ) break;
	T[0] = Point(x, y);
	cin >> x >> y;
	T[1] = Point(x, y);
	cin >> x >> y;
	T[2] = Point(x, y);
	cin >> x >> y >> r;
	c = Circle(Point(x, y), r);
	if ( circleIsInTriangle(c, T) ) cout << "a" << endl;
	else if ( triangleIsInCircle(c, T) ) cout << "b" << endl;
	else if ( isIntersect(c, T) ) cout << "c" << endl;
	else cout << "d" << endl;
    }
    return 0;
}
