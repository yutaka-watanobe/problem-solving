#include<iostream>
#include<cfloat>
#include<cassert>
#include<cmath>
#include<vector>

using namespace std;

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
    bool x1, x2;
    Segment(Point s = Point(), Point t = Point()): p1(s), p2(t){}
};

static const int CIRCLE_NON = 0;
static const int CIRCLE_OUT = 1;
static const int CIRCLE_IN = 2;
static const int CIRCLE_CROSS = 3;

double norm( Vector a ){ return a.x*a.x + a.y*a.y; }
double abs( Vector a ){ return sqrt(norm(a)); }
double dot( Vector a, Vector b ){ return a.x*b.x + a.y*b.y; }
double cross( Vector a, Vector b ){ return a.x*b.y - a.y*b.x; }

// verified by uoa2062
bool isOnSegment( Point a, Point b, Point c){
    if ( a == c || b == c ) return true;
    return (abs(a-c) + abs(c-b) < abs(a-b) + EPS );
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

#define MAX 1000
int N;
Segment S[MAX];
bool visited[MAX];
vector<int> path;

int getNumber(vector<int> con){
    int nc = con.size(); // number of components
    int nmid = 0;
    int t2 = 0; // touch by two
    for ( int i = 0; i < con.size()-1; i++ ){
	for ( int j = i+1; j < con.size(); j++ ){
	    Segment s1 = S[con[i]], s2 = S[con[j]];
	    if ( isIntersect(s1, s2) ){
		if ( !(s1.p1 == s2.p1) && !(s1.p1 == s2.p2) &&
		     !(s1.p2 == s2.p1) && !(s1.p2 == s2.p2) ) nmid++;
	    }
	}
    }
    for ( int i = 0; i < con.size(); i++ ){
	int l = 0, r = 0;
	S[con[i]].x1 = S[con[i]].x2 = false;
	for ( int j = 0; j < con.size(); j++ ){
	    if ( i == j ) continue;
	    if ( isOnSegment(S[con[j]].p1, S[con[j]].p2, S[con[i]].p1) ) { l = 1; S[con[i]].x1 = true; }
	    if ( isOnSegment(S[con[j]].p1, S[con[j]].p2, S[con[i]].p2) ) { r = 1; S[con[i]].x2 = true; }
	}
	if ( l && r ) t2++;
    }
    
    if ( nc == 4 && nmid == 0 ) return 0;
    if ( nc == 1  ) return 1;
    if ( nc == 4 && nmid == 1 ){
	if ( t2 == 1 ) return 3;
	else if ( t2 == 3 ) return 9;
	else assert(false);
    }
    if ( nc == 3 && nmid == 1 ) return 4;
    if ( nc == 5 && nmid == 1 ) return 6;
    if ( nc == 3 && nmid == 0 ) return 7;
    if ( nc == 5 && nmid == 2 ) return 8;

    vector<Segment> h;
    for ( int i = 0; i < con.size(); i++ ){
	if ( S[con[i]].x1 && !S[con[i]].x2 ) h.push_back(Segment(Point(S[con[i]].p2), Point(S[con[i]].p1)));
	if ( !S[con[i]].x1 && S[con[i]].x2 ) h.push_back(Segment(Point(S[con[i]].p1), Point(S[con[i]].p2)));

    }

    assert( h.size() == 2 );
    if ( ccw(h[0].p1, h[1].p1, h[1].p2) == CLOCKWISE ) return 2;
    else return 5;
}

void dfs(int u){
    visited[u] = true;
    path.push_back(u);
    for ( int v = 0; v < N; v++ ){
	if ( u == v || visited[v]) continue;
	if ( isIntersect(S[u], S[v]) ) dfs(v);
    }
}

void compute(){
    int cnt[10];
    for ( int i = 0; i < 10; i++ ) cnt[i] = 0;
    for ( int i = 0; i < N; i++ ) visited[i] = false;
    for ( int u = 0; u < N; u++ ){
	if ( !visited[u] ){
	    path.clear();
	    dfs(u);
	    cnt[getNumber(path)]++;
	}
    }
    for ( int i = 0; i < 10; i++ ){
	if ( i ) cout << " ";
	cout << cnt[i];
    } cout << endl;
}

int main(){
    int x1, y1, x2, y2;
    while( cin >> N ){
	if ( N == 0 ) break;
	for ( int i = 0; i < N; i++ ){
	    cin >> x1 >> y1 >> x2 >> y2;
	    S[i] = Segment(Point(x1, y1), Point(x2, y2));
	}
	compute();
    }

    return 0;
}
