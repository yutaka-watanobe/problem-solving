#include<iostream>
#include<cfloat>
#include<cassert>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define EPS (1e-8)
#define equals(a, b) (fabs((a) - (b)) < EPS )
#define dle(a, b) (equals(a, b) || a < b )
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define MAX 100

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

static const int CIRCLE_NON = 0;
static const int CIRCLE_OUT = 1;
static const int CIRCLE_IN = 2;
static const int CIRCLE_CROSS = 3;

class Circle{
    public:
    Point c;
    double r;
    vector<double> angleList;
    Circle(Point c = Point(), double r = 0.0): c(c), r(r){}
    void angleSort(){
	sort(angleList.begin(), angleList.end());
    }
};

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

// intersect Segment p1-p2 and Segment p3-p4 ?
bool isIntersect(Point p1, Point p2, Point p3, Point p4){
    return ( ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
	     ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0 );
}

// 0 <= a <= 360
double getAngleTheta(Point p){
    double polar = atan2(p.y, p.x);
    double rad = (dle(0, polar))? polar : 2*PI+polar;
    return rad*180.0/acos(-1);
}
// 0 <= a <= 2pi
double getAngle(Point p){
    double polar = atan2(p.y, p.x);
    return (dle(0, polar))? polar : 2*PI+polar;
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
    assert( isIntersect( c1, c2 ) == CIRCLE_CROSS );
    double d = abs(c1.c - c2.c);
    double a = acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c+polar(c1.r, t+a), c1.c+polar(c1.r, t-a));
}

#define STATE_IN 1
#define STATE_OUT -1
#define STATE_ON 0

bool check(int n, int state[MAX], int tstate[MAX] ){
    rep(i, n){
	if ( tstate[i] == STATE_ON ) continue;
	if ( tstate[i] != state[i] ) return false;
    }
    return true;
}

void compute(int n, Circle C[MAX], Point target){
    rep(i, n) rep(j, n){
	if ( i == j ) continue;
	if ( isIntersect(C[i], C[j]) != CIRCLE_CROSS) continue;
	pair<Point, Point> cp = getCrossPoints(C[i], C[j]);
	C[i].angleList.push_back(getAngle(cp.first - C[i].c));
	C[i].angleList.push_back(getAngle(cp.second - C[i].c));
    }
    rep(i, n){
	C[i].angleList.push_back(0.0);
	C[i].angleList.push_back(2*PI-EPS);
	C[i].angleSort();
    }

    int state[MAX]; 
    rep(i, n){
	double d = getDistance(C[i].c, target);
	if ( equals(d, C[i].r) ) state[i] = STATE_ON;
	else if ( d > C[i].r ) state[i] = STATE_OUT;
	else state[i] = STATE_IN;
    }

    double sum = 0.0;

    rep(i, n){
	Circle source = C[i];
	rep(j, source.angleList.size()-1){
	    double a1 = source.angleList[j];
	    double a2 = source.angleList[j+1];
	    Point m = source.c + polar(source.r, (a1+a2)/2.0);
	    int tstate[MAX];
	    rep(t, n){
		double d = getDistance(C[t].c, m);
		if ( equals(d, C[t].r) ) tstate[t] = STATE_ON;
		else if ( d > C[t].r ) tstate[t] = STATE_OUT;
		else tstate[t] = STATE_IN;
	    }
	    if ( check(n, state, tstate) ){
		sum += (a2 - a1)*source.r;
	    }
	}
    }

    printf("%.8lf\n", sum);

    
}

int main(){
    int n;
    Circle C[MAX];
    double x, y, r;
    Point target;
    while ( cin >> n && n){
	rep(i, n){
	    cin >> x >> y >> r; C[i] = Circle(Point(x, y), r);
	}
	cin >> target.x >> target.y;
	compute(n, C,target);
    }
    return 0;
}
