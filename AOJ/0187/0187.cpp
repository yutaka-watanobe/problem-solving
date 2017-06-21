#include<iostream>
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
double dot( Vector a, Vector b ){ return a.x*b.x + a.y*b.y; }
double cross( Vector a, Vector b ){ return a.x*b.y - a.y*b.x; }

bool isParallel( Vector a, Vector b ){
    return equals( cross(a, b), 0.0 );
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

bool isIntersect(Point p1, Point p2, Point p3, Point p4){
    return ( ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
	     ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0 );
}

bool isIntersect(Segment s1, Segment s2){
    return isIntersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

Point getCrossPoint(Segment s1, Segment s2){
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1/(d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1)*t;
}

double getArea(Point p1, Point p2, Point p3){
    return abs(0.5 * ((p3.y-p1.y)*(p2.x-p1.x)-(p2.y-p1.y)*(p3.x-p1.x)));
}

double getTArea( vector<Point> P){
    if ( P.size() != 3 ) return 0;
    if ( isParallel(P[2]-P[0], P[1]-P[0]) ) return 0;
    return getArea(P[0], P[1], P[2] );
}

int main(){
    double x1, y1, x2, y2;
    Segment S[3];
    vector<Point> P;

    while(1){
	cin >> x1 >> y1 >> x2 >> y2; S[0] = Segment(Point(x1, y1), Point(x2, y2));
	if ( x1 == 0.0 && y1 == 0.0 && x2 == 0.0 && y2 == 0.0 ) break;
	cin >> x1 >> y1 >> x2 >> y2; S[1] = Segment(Point(x1, y1), Point(x2, y2));
	cin >> x1 >> y1 >> x2 >> y2; S[2] = Segment(Point(x1, y1), Point(x2, y2));
	if ( isIntersect( S[0], S[1] )) P.push_back(getCrossPoint(S[0], S[1]));
	if ( isIntersect( S[0], S[2] )) P.push_back(getCrossPoint(S[0], S[2]));
	if ( isIntersect( S[1], S[2] )) P.push_back(getCrossPoint(S[1], S[2]));

	double area = getTArea(P);
	printf("%.20lf\n", area);
	if ( 1900000 <= area) cout << "dai-kichi" << endl;
	else if ( 1000000 <= area && area < 1900000 ) cout << "chu-kichi" << endl;
	else if ( 100000 <= area && area < 1000000 ) cout << "kichi" << endl;
	else if ( 0 < area && area < 100000 ) cout << "syo-kichi" << endl;
	else cout << "kyo" << endl;
	P.clear();
    }

    return 0;
}
