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

/*
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
*/

void compute(Point p, Vector v, double D){
    assert( 0.1 <= p.abs() && p.abs() <= 0.9 );
    assert( 0.1 <= v.abs() && v.abs() <= 10.0 );
    assert( 0.1 <= D && D <= 50.0 );
  
    Point c = Point(0, 0);
    int dir = ccw(p, p+v, c);
    double dist = 0.0;

    if ( dir == ONLINE_FRONT || dir == ON_SEGMENT ){
	dist = getDistance(c, p);
    } else if ( dir == ONLINE_BACK ){
	dist = 2.0 - getDistance(c, p);
    } else {
	cout << "impossible" << endl;
	return;
    }

    if ( D < dist ){
	cout << "impossible" << endl;
    } else {
	assert(  D-(1.0e-3) > dist );
	printf("%.12lf\n",  dist);
    }
    
}


int main(){
  Point p;
    Vector v;
    double D;
    while(1){
	cin >> D;
	if ( D == 0 ) break;
	cin >> p.x >> p.y >> v.x >> v.y; 
	compute(p, v, D);
    }
    return 0;
}
