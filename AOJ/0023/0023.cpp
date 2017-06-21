#include<iostream>
#include<cfloat>
#include<cassert>
#include<cmath>

using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS )

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

double norm( Vector a ){ return a.x*a.x + a.y*a.y; }
double abs( Vector a ){ return sqrt(norm(a)); }

static const int CIRCLE_NON = 0;
static const int CIRCLE_OUT = 1;
static const int CIRCLE_IN = 2;
static const int CIRCLE_CROSS = 3;

class Circle{
    public:
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0): c(c), r(r){}

    int isIntersect(Circle t){
	double d = abs(c - t.c);
	if ( r + t.r < d ) return CIRCLE_NON; // no overlap
	if ( d + t.r < r ) return CIRCLE_IN;  // this includes t
	if ( d + r < t.r ) return CIRCLE_OUT;  // this is included by t
	return CIRCLE_CROSS;
    }
};


main(){
    int tcase;
    double ax, ay, ar, bx ,by, br;
    cin >> tcase;
    
    for ( int i = 0; i < tcase; i++ ){
	cin >> ax >> ay >> ar >> bx >> by >> br;
	Circle a = Circle(Point(ax, ay), ar);
	Circle b = Circle(Point(bx, by), br);
	int rs = a.isIntersect(b);
	if ( rs == CIRCLE_IN ) cout << 2 << endl;
	else if ( rs == CIRCLE_OUT ) cout << -2 << endl;
	else if ( rs == CIRCLE_CROSS ) cout << 1 << endl;
	else cout << 0 << endl;
    }
}
