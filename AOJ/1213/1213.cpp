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

typedef Segment Line;

typedef vector<Point> Polygon;

double norm( Vector a ){ return a.x*a.x + a.y*a.y; }
double abs( Vector a ){ return sqrt(norm(a)); }
Point polar( double a, double r ){ return Point(cos(r)*a, sin(r)*a);}
double getDistance( Vector a, Vector b ){ return abs(a - b); }
double dot( Vector a, Vector b ){ return a.x*b.x + a.y*b.y; }
double cross( Vector a, Vector b ){ return a.x*b.y - a.y*b.x; }

double arg(Vector p){
    return atan2(p.y, p.x);
}

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

Point getCrossPointLines( Line s1, Line s2){
    Vector a = s1.p2 - s1.p1;
    Vector base = s2.p2 - s2.p1;
    return s1.p1 + a * cross(base, s2.p1 - s1.p1)/cross(base, a);
}

double getAngleTheta(Point p){
    double polar = atan2(p.y, p.x);
    double rad = (dle(0, polar))? polar : 2*acos(-1)+polar;
    return rad*180.0/acos(-1);
}

double getAngle(Point p){
    double polar = atan2(p.y, p.x);
    return (dle(0, polar))? polar : 2*acos(-1)+polar;
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

Line getCutLine( Point p1, Point p2 ){
    Vector v = p2 - p1;
    v = polar(abs(v), arg(v)+PI/2.0);
    double dx = (p2.x + p1.x)/2.0;
    double dy = (p2.y + p1.y)/2.0;
    return Line(Point(dx, dy), Point(v.x+dx, v.y+dy));
}

double getArea(Polygon p){
    double sum = 0.0;
    for(int i = 0; i < p.size(); i++){
	sum += cross(p[i], p[(i+1)%p.size()]);
    }
    return abs(sum/2);
}

int main(){
    double x1, y1, x2, y2, x3, y3;
    Point P[3];
    Polygon B; 
    int tcase = 1;
    while(1){
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if ( x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 && y3 == 0 ) break;
	P[0] = Point(x1, y1);
	P[1] = Point(x2, y2);
	P[2] = Point(x3, y3);
	B.clear();
	B.push_back(Point(0, 0));
	B.push_back(Point(10000, 0));
	B.push_back(Point(10000, 10000));
	B.push_back(Point(0, 10000));

	B = cutPolygon(B, getCutLine(P[0], P[1]));
	B = cutPolygon(B, getCutLine(P[0], P[2]));
	
	printf("%d %.12lf\n", tcase++, getArea(B)/(100000000));

    }
    return 0;
}
