#include<iostream>
#include<cfloat>
#include<cassert>
#include<cmath>
#include<vector>

using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++ )
#define EPS (1e-8)

class Point{
    public:
    double x, y;
    
    Point ( double x = 0, double y = 0): x(x), y(y){}
    
    Point operator + ( Point p ){ return Point(x + p.x, y + p.y); }
    Point operator - ( Point p ){ return Point(x - p.x, y - p.y); }
    Point operator * ( double a ){ return Point(x*a, y*a); }
};
typedef Point Vector;
typedef vector<Point> Polygon;

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

bool isIntersect(Point p1, Point p2, Point p3, Point p4){
    return ( ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
	     ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0 );
}

bool isInside(Polygon pol, Point p){
    rep(i, 4){
	if ( ccw(pol[i], pol[(i+1)%4], p ) == COUNTER_CLOCKWISE ) return false;
    }
    return true;
}

bool isIntersectSQ(Polygon p1, Polygon p2 ){
    rep(i, 3) rep(j, 3){
	if ( isIntersect(p1[i], p1[i+1], p2[j], p2[j+1] ) ) return true;
    }
    rep(i, 4) if(isInside(p1, p2[i])) return true;
    rep(i, 4) if(isInside(p2, p1[i])) return true;
    return false;
}

Polygon P[100];
int n, G[100][100];
bool V[100];

void dfs( int u ){
    V[u] = true;
    rep(v, n) if ( G[u][v] && !V[v] ) dfs(v);
}

int compute(){
    rep(i, n) rep(j, n ) G[i][j] = 0;
    rep(i, n) rep(j, n ) if ( isIntersectSQ(P[i], P[j]) ) G[i][j] = 1;
    rep(i, n) V[i] = false;
    int ncomponent = 0;
    rep(i, n){
	if ( V[i] ) continue;
	ncomponent++;
	dfs(i);
    }
    return ncomponent;
}

int main(){
    int N;
    double x, y;
    while( cin >> N && N ){
      assert( 1 <= N && N <= 100 );
	rep(i, N){
	    cin >> n;
	    assert( 1 <= n && n <= 100 );
	    rep(j, n){
		Polygon pol;
		rep(k, 4){
		    cin >> x >> y;
		    pol.push_back(Point(x, y));
		}
		P[j] = pol;
	    }
	    cout << compute() << endl;
	}
    }
    return 0;
}
