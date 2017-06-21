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


#define NON 0
#define IN 1
#define OUT 2

double R;

class UFO{
    public:
    Circle body;
    double v, dx, dy;
    int state;

    UFO( Circle c = Circle(Point(0,0),0), double v=0):body(c), v(v){
	Point ct = Point(0, 0);
	Vector a = ct - body.c;
	dx = v*cos(arg(a));
	dy = v*sin(arg(a));
	state = NON;
    }

    void move(){
	if ( state != NON ) return;
	double pred = getDistance(Point(0, 0), body.c);
	if ( v > pred || equals(v, pred)){ state = IN; return; }
	body.c.x += dx;
	body.c.y += dy;
	double d = getDistance(Point(0, 0), body.c);
	if ( R > d || equals(R, d) ) state = IN;
    }
};

#define MAX 100

UFO U[MAX];
int n;

void attack( Point p1, Point p2){
    Line l = Line(p1, p2);
    for ( int i = 0; i < n; i++ ){
	if ( U[i].state != NON ) continue;
	if ( !isIntersect(U[i].body, l) ) continue;
	pair<Point, Point> pp = getCrossPoints(U[i].body, l);
	if ( equals( arg(p2 - p1), arg(pp.first - p1)) && getDistance(p1, pp.first) > R ) {
	    U[i].state = OUT;
	}
	if ( equals( arg(p2 - p1), arg(pp.second - p1)) && getDistance(p1, pp.second) > R ) {
	    U[i].state = OUT;
	}
    }
}

int simulate(){
    while(1){
	int life = 0;
	for ( int i = 0; i < n; i++ ) {
	    U[i].move();
	    if ( U[i].state == NON ) life++;
	}
	if ( life == 0 ) break;

	int target = -1;
	double md = 1000000;
	for ( int i = 0; i < n; i++ ){
	    if ( U[i].state != NON ) continue;
	    double d = getDistance(Point(0, 0), U[i].body.c);
	    assert( !equals(md, d) );
	    if ( d < md ){
		md = d;
		target = i;
	    }
	}
	attack(Point(0, 0), U[target].body.c);
    }

    int cnt = 0;
    for ( int i = 0; i < n; i++ ) if ( U[i].state == IN ) cnt++;
    return cnt;
}

main(){
    double x, y, r, v;
    while( cin >> R && R ){
	cin >> n;
	for ( int i = 0; i < n; i++ ){
	    cin >> x >> y >> r >> v;
	    U[i] = UFO(Circle(Point(x, y), r), v);
	}
	cout << simulate() << endl;
    }
}
