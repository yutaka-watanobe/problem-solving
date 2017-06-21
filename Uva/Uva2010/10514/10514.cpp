#include<iostream>
#include<cfloat>
#include<cassert>
#include<cmath>
#include<vector>

using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++)
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

static const int CIRCLE_NON = 0;
static const int CIRCLE_OUT = 1;
static const int CIRCLE_IN = 2;
static const int CIRCLE_CROSS = 3;

typedef vector<Point> Polygon;

double norm( Vector a ){ return a.x*a.x + a.y*a.y; }
double abs( Vector a ){ return sqrt(norm(a)); }
Point polar( double a, double r ){ return Point(cos(r)*a, sin(r)*a);}
double getDistance( Vector a, Vector b ){ return abs(a - b); }
double dot( Vector a, Vector b ){ return a.x*b.x + a.y*b.y; }
double cross( Vector a, Vector b ){ return a.x*b.y - a.y*b.x; }

Point project( Segment s, Point p ){
    Vector base = s.p2 - s.p1;
    double t = dot(p - s.p1, base)/norm(base);
    return s.p1 + base*t;
}

Point reflect( Segment s, Point p ){
    return p + (project(s, p) - p)*2.0;
}

// verified by uoa2062
bool isOnSegment( Point a, Point b, Point c){
    if ( a == c || b == c ) return true;
    return (abs(a-c) + abs(c-b) < abs(a-b) + EPS );
}

bool isOrthogonal( Vector a, Vector b ){
     return equals( dot(a, b), 0.0 );
}

bool isOrthogonal( Point a1, Point a2, Point b1, Point b2 ){
    return isOrthogonal( a1 - a2, b1 - b2 );
}

bool isOrthogonal( Segment s1, Segment s2 ){
    return equals( dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0 );
}

bool isParallel( Vector a, Vector b ){
    return equals( cross(a, b), 0.0 );
}

bool isParallel( Point a1, Point a2, Point b1, Point b2){
    return isParallel( a1 - a2, b1 - b2 );
}

bool isParallel( Segment s1, Segment s2 ){
    return equals( cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0 );
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
    return isIntersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

// verified by 920, 833, uoa2062
Point getCrossPoint(Segment s1, Segment s2){
    assert( isIntersect(s1, s2) );
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1/(d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1)*t;
}

Point getCrossPointLines( Line s1, Line s2){
    Vector a = s1.p2 - s1.p1;
    Vector base = s2.p2 - s2.p1;
    return s1.p1 + a * cross(base, s2.p1 - s1.p1)/cross(base, a);
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

double getAngle(Vector v1, Vector v2 ){

}

double getDistanceLP(Line s, Point p){ 
    return abs(cross(s.p2 - s.p1, p - s.p1)/abs(s.p2 - s.p1));
}

double getDistance(Segment s, Point p){
    if ( dot(s.p2 - s.p1, p - s.p1) < 0.0 ) return abs(p - s.p1);
    if ( dot(s.p1 - s.p2, p - s.p2) < 0.0 ) return abs(p - s.p2);
    return abs(cross(s.p2 - s.p1, p - s.p1)/abs(s.p2 - s.p1));
}

double getDistance(Segment s1, Segment s2){
    if ( isIntersect(s1, s2) ) return 0.0;
    return min( min(getDistance(s1, s2.p1), getDistance(s1, s2.p2)),
		min(getDistance(s2, s1.p1), getDistance(s2, s1.p2)));
}

#define MAX 20
#define INFTY (1<<21)
double getCost(vector<Point> P1, vector<Point> P2){
    double minv = (1<<21);
    for ( int i = 0; i < P1.size()-1; i++ ){
	Segment s1 = Segment(P1[i], P1[i+1]);
	for ( int j = 0; j < P2.size()-1; j++ ){
	    Segment s2 = Segment(P2[j], P2[j+1]);
	    minv = min(minv, getDistance(s1, s2));
	}
    }
    //    cout << minv << endl;
    return minv;
}

double dijkstra(int n, double G[MAX][MAX] ){
    double D[MAX];
    bool V[MAX];
    rep(i, n) {
	D[i] = INFTY;
	V[i] = false;
    }
    D[0] = 0.0;

    while(1){
	int u = -1;
	double minv = INFTY;
	rep(i, n){
	    if ( !V[i] && D[i] < minv){
		minv = D[i];
		u = i;
	    }
	}
	if ( u == -1 ) break;
	V[u] = true;

	rep(v, n){
	    if ( V[v] ) continue;
	    D[v] = min(D[v], D[u] + G[u][v]);
	}
    }
    
    return D[n-1];

}

void compute(){
    double x, y;
    int r1, r2, n; cin >> r1 >> r2 >> n;
    vector<Point> R1, R2;
    vector<vector<Point> > I;

    rep(i, r1){
	cin >> x >> y; R1.push_back(Point(x, y));
    }
    rep(i, r2){
	cin >> x >> y; R2.push_back(Point(x, y));
    }

    I.push_back(R1);
    rep(i, n){
	int m; cin >> m;
	vector<Point> pg;
	rep(j, m){
	    cin >> x >> y;  pg.push_back(Point(x, y));
	}
	pg.push_back(pg[0]);
	I.push_back(pg);
	
    }
    I.push_back(R2);

    int N = n + 2;
    double G[MAX][MAX];
    rep(i, MAX) rep(j, MAX) G[i][j] = (1<<21);

    assert( (int)(I.size()) == N );

    //    cout << I.size() << endl;
    for ( int i = 0; i < I.size()-1; i++ ){
	for ( int j = i+1; j < I.size(); j++ ){
	    G[i][j] = G[j][i] = getCost(I[i], I[j]);
	}
    }

    //    for ( int i = 0; i < N-1; i++ ){
    //	for ( int j = i+1; j < N; j++ ) cout << i << "-" << j << " " << G[i][j] << endl;
    //    }

    printf("%.3lf\n", dijkstra(N, G));
    

    
}

int main(){
    int tcase; cin >> tcase;
    rep(i, tcase) compute();
}
