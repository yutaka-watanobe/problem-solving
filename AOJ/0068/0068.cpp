#include<iostream>
#include<cfloat>
#include<cassert>
#include<cmath>
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

bool yxCmp( const Point &p1, const Point &p2 ) {
    return (p1.y == p2.y) ? p1.x < p2.x : p1.y < p2.y;
}

class PolarAngleCmp{
    public:
    Point o;
    PolarAngleCmp( Point o): o(o){}
    bool operator()( const Point &p1,  const Point &p2) const {
	Vector a = Vector(p1.x-o.x, p1.y-o.y); // p1 - o
	Vector b = Vector(p2.x-o.x, p2.y-o.y); // p2 - o
	double c = cross(a, b);
	if ( c == 0 ) return abs(a) < abs(b);
	return c > 0;
    }
};

Polygon grahamScan( Polygon &s ){
    Polygon h;
    Point lm = *min_element(s.begin(), s.end(), yxCmp);
    sort(s.begin(), s.end(), PolarAngleCmp(lm));
    for ( int i = 0; i <= 2; i++ ) h.push_back(s[i]);
    for ( int i = 3; i < s.size(); i++ ){
	while( h.size() >= 2 && ccw(h[h.size()-2], h.back(), s[i]) == CLOCKWISE )
	    h.pop_back();
	h.push_back(s[i]);
    }
    return h;
}

int main(){
    Polygon pol, hull;
    char ch;
    int n;
    
    while( cin >> n && n){
	pol.clear();
	double x, y;
	for ( int i = 0; i < n ;i++ ){
	    cin >> x >> ch >> y;
	    pol.push_back(Point(x, y));
	}
	hull = grahamScan(pol);
	cout << pol.size() - hull.size() << endl;
    }
    return 0;
}
