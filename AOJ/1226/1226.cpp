#include<iostream>
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

Point getCrossPoint(Segment s1, Segment s2){
    assert( isIntersect(s1, s2) );
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1/(d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1)*t;
}

double getArea(Polygon p){
    double sum = 0.0;
    for(int i = 0; i < p.size(); i++){
	sum += cross(p[i], p[(i+1)%p.size()]);
    }
    return abs(sum/2);
}

#define MAX 30

int main(){
    double a[MAX+2], b[MAX+2], c[MAX+2], d[MAX+2];
    int n;
    Segment V[MAX+2], H[MAX+2];

    Point P[MAX+2][MAX+2];

    while( cin >> n && n ){
	for ( int i = 1; i <= n; i++ ) cin >> a[i];
	for ( int i = 1; i <= n; i++ ) cin >> b[i];
	for ( int i = 1; i <= n; i++ ) cin >> c[i];
	for ( int i = 1; i <= n; i++ ) cin >> d[i];

	V[0] = Segment(Point(0, 0), Point(0, 1));
	for ( int i = 1; i <= n; i++ ){
	    V[i] = Segment(Point(a[i], 0), Point(b[i], 1));
	}
	V[n+1] = Segment(Point(1, 0), Point(1, 1));

	H[0] = Segment(Point(0, 0), Point(1, 0));
	for ( int i = 1; i <= n; i++ ){
	    H[i] = Segment(Point(0, c[i]), Point(1, d[i]));
	}
	H[n+1] = Segment(Point(0, 1), Point(1, 1));

	
	for ( int y = 0; y < n+2; y++ ){
	    for ( int x = 0; x < n+2; x++ ){
		P[y][x] = getCrossPoint(H[y], V[x]);
	    }
	}

	double maxa = 0;

	for ( int y = 1; y < n+2; y++ ){
	    for ( int x = 1; x < n+2; x++ ){
		Polygon S;
		S.push_back(P[y][x]);
		S.push_back(P[y][x-1]);
		S.push_back(P[y-1][x-1]);
		S.push_back(P[y-1][x]);
		maxa = max( maxa, getArea(S) );
	    }
	}

	printf("%.12lf\n", maxa);
    }



    return 0;
}
