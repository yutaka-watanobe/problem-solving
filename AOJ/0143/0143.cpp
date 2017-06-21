#include<cstdio>
#include<cfloat>
#include<cassert>
#include<cmath>
#include<vector>

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
    bool operator < ( const Point &p ) const {
	return x != p.x ? x < p.x : y < p.y;
    }
    bool operator == ( const Point &p ) const {
	return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
    }
};

typedef Point Vector;

double norm( Vector a ){ return a.x*a.x + a.y*a.y; }
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

int side( Point p1, Point p2, Point p3, Point t ){
    int ccw1 = ccw( p1, p2, t );
    int ccw2 = ccw( p2, p3, t );
    int ccw3 = ccw( p3, p1, t );
    if ( ccw1 == ccw2 && ccw2 == ccw3 ) return 1; // int
    return 0; // out
}

int main(){
    int tcase; scanf("%d", &tcase);
    double x1, y1, x2, y2, x3, y3, sx, sy, tx, ty;
;
    for ( int i = 0; i < tcase; i++ ){
	scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &sx, &sy, &tx, &ty);
	Point p1 = Point(x1, y1);
	Point p2 = Point(x2, y2);
	Point p3 = Point(x3, y3);
	if ( side( p1, p2, p3, Point(sx, sy)) == side( p1, p2, p3, Point(tx, ty)) ){
	    printf("NG\n");
	} else {
	    printf("OK\n");
	}

    }
    return 0;
}
