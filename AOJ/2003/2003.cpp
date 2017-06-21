#include<iostream>
#include<cfloat>
#include<cassert>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define EPS (1e-10)
#define equals(a, b) (abs((a) - (b)) < EPS )

class Point{
    public:
    double x, y;
    int place; 

    Point ( double x = 0, double y = 0): x(x), y(y){}
    
    Point operator + ( Point p ){
	return Point(x + p.x, y + p.y);
    }

    Point operator - ( Point p ){
	return Point(x - p.x, y - p.y);
    }

    Point operator * ( double a ){
	return Point(a*x, a*y);
    }

    double absolute() { return sqrt(norm());}
    double norm() { return x*x + y*y; }

    bool operator < ( const Point &p ) const {
	return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == ( const Point &p ) const {
	return abs(x-p.x) < EPS && abs(y-p.y) < EPS;
    }
};

typedef Point Vector;

class Segment{
    public:
    Point source, target;
    int comp, place;
    Segment(Point s = Point(), Point t = Point()): source(s), target(t){}
};

double norm( Vector a ){
    return a.x*a.x + a.y*a.y;
}

double absolute( Vector a ){
    return sqrt(norm(a));
}

double getDistance( Vector a, Vector b ){
    return absolute(a - b); 
}

double dot( Vector a, Vector b ){
    return a.x*b.x + a.y*b.y;
}

double cross( Vector a, Vector b ){
    return a.x*b.y - a.y*b.x;
}

Point project( Segment s, Point p ){
    Vector base = s.target - s.source;
    double t = dot(p - s.source, base)/norm(base);
    return s.source + (base)*t;
}

Point reflect( Segment s, Point p ){
    return p + (project(s, p) - p)*2.0;
}

// verified by uoa2062
bool isOnSegment( Point a, Point b, Point c){
    if ( a == c || b == c ) return true;
    return (absolute(a-c) + absolute(c-b) < absolute(a-b) + EPS );
}

bool isOrthogonal( Vector a, Vector b ){
     return equals( dot(a, b), 0.0 );
}

bool isOrthogonal( Point a1, Point a2, Point b1, Point b2 ){
    return isOrthogonal( a1 - a2, b1 - b2 );
}

bool isOrthogonal( Segment s1, Segment s2 ){
    return equals( dot(s1.target - s1.source, s2.target - s2.source), 0.0 );
}

bool isParallel( Vector a, Vector b ){
    return equals( cross(a, b), 0.0 );
}

bool isParallel( Point a1, Point a2, Point b1, Point b2){
    return isParallel( a1 - a2, b1 - b2 );
}

bool isParallel( Segment s1, Segment s2 ){
    return equals( cross(s1.target - s1.source, s2.target - s2.source), 0.0 );
}

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

// intersect Segment p1-p2 and Segment p3-p4 ?
bool isIntersect(Point p1, Point p2, Point p3, Point p4){
    return ( ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
	     ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0 );
}

// intersect Segment s1 and Segment s2 ?
// verified by 920, 833, 866, uoa2062
bool isIntersect(Segment s1, Segment s2){
    return isIntersect(s1.source, s1.target, s2.source, s2.target);
}

// verified by 920, 833, uoa2062
Point getCrossPoint(Segment s1, Segment s2){
    assert( isIntersect(s1, s2) );
    Vector base = s2.target - s2.source;
    double d1 = absolute(cross(base, s1.source - s2.source));
    double d2 = absolute(cross(base, s1.target - s2.source));
    double t = d1/(d1 + d2);
    return s1.source + (s1.target - s1.source)*t;
}


#define MY 1
#define OTHER 0
#define UP 1
#define DOWN 0
#define MAX 100

void compute( int n, Segment lines[MAX], Segment base ){
    vector<Point> P;

    P.push_back(base.source);
    P.push_back(base.target);

    for ( int i = 0; i < n; i++ ){
	Segment line = lines[i];

	if ( !isIntersect( base, line ) ) continue;
	Point cp = getCrossPoint(base, line);

	if ( line.comp == MY ){
	    if ( line.place == DOWN ) cp.place = DOWN;
	    else cp.place = UP;
	} else {
	    if ( line.place == DOWN ) cp.place = UP;
	    else cp.place = DOWN;
	}
	P.push_back(cp);
    }

    sort( P.begin(), P.end() );

    int ans = 0;
    for ( int i = 2; i < P.size()-1; i++ ){
	if ( P[i-1].place != P[i].place ) ans++;
    }
    cout << ans << endl;
}

int main(){
    double xa, ya, xb, yb, xs, ys, xt, yt;
    int  comp, place, n;
    Segment base, lines[MAX];
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	cin >> xa >> ya >> xb >> yb; 
	base = Segment(Point(xa, ya), Point(xb, yb));
	base.place = 0;
	base.comp = 0;
	cin >> n;
	for ( int j = 0; j < n; j++ ){
	    cin >> xs >> ys >> xt >> yt >> comp >> place;
	    lines[j] = Segment(Point(xs, ys), Point(xt, yt));
	    lines[j].comp = comp;
	    lines[j].place = place;
	}
	compute(n, lines, base);
    }
    return 0;
}
