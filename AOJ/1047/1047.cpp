#include<iostream>
#include<cfloat>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define EPS (1e-10)
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

double getAngle(Point p){
    double polar = atan2(p.y, p.x);
    return (dle(0, polar))? polar : 2.0*acos(-1)+polar;
}

int isIntersect(Circle c1, Circle c2){
    double d = abs(c1.c - c2.c);
    if ( c1.r + c2.r < d ) return CIRCLE_NON; // no overlap
    if ( d + c2.r < c1.r ) return CIRCLE_IN;  // c1 includes c2
    if ( d + c1.r < c2.r ) return CIRCLE_OUT;  // c2 includes c1
    return CIRCLE_CROSS;
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


Circle C[100];
int n;

void compute(){
    double len = 0.0;

    for ( int i = 0; i < n; i++ ){
	vector<double> angles;
	for ( int j = 0; j < n; j++ ){
	    if ( i == j ) continue;
	    if ( isIntersect(C[i], C[j]) != CIRCLE_CROSS ) continue;
	    pair<Point, Point> pp = getCrossPoints(C[i], C[j]);
	    angles.push_back(getAngle(pp.first - C[i].c));
	    angles.push_back(getAngle(pp.second - C[i].c));
	}
	angles.push_back(0.0);
	angles.push_back(2*PI);

	sort( angles.begin(), angles.end() );

	for ( int a = 1; a < angles.size(); a++ ) {
	    Point m = C[i].c + polar(C[i].r, (angles[a]+angles[a-1])/2.0);
	    bool included = false;
	    for ( int t = 0; t < n; t++ ){
		if ( t == i ) continue;
		if ( dle(getDistance(m, C[t].c), C[t].r) ) included = true;
	    }

	    if ( !included ){
		len += (angles[a] - angles[a-1])*C[i].r;
	    }
	}
    }

    printf("%.12lf\n", len);
}

int main(){
    double x, y, r;
    while( cin >> n  ){
	if ( n == 0 ) break;
	for ( int i = 0; i < n; i++ ){
	    cin >> x >> y >> r; C[i] = Circle( Point(x, y), r);
	}
	compute();
    }
    
    return 0;
}
