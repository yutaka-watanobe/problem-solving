#include<cstdio>
#include<iostream>
#include<complex>
#include<cfloat>
#include<cassert>
#include<algorithm>
#include<queue>

using namespace std;

#define EPS (1e-8)
#define equals(a, b) (abs((a) - (b)) < EPS )
#define rep(i, n) for ( int i = 0; i < (int)n; i++ )
typedef complex<double> Point;
typedef complex<double> Vector;
typedef unsigned short ushort;

// verified by 833
static const double LX = FLT_MIN;
static const double UX = FLT_MAX;

namespace std {
    bool operator < (const Point &a, const Point &b) {
	return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }

    bool operator == ( const Point &a, const Point &b ) {
	return abs(real(a)-real(b))< EPS && abs(imag(a)-imag(b)) < EPS;
    }
}

class Segment{
    public:
    Point source, target;
    Segment(Point s = Point(), Point t = Point()): source(s), target(t){}
};

class Edge{ 
    public:
    int t; double d; 
    Edge( int tt=0, double dd=0):t(tt), d(dd){}
};

class Node{
    public:
    Point pos;
    Edge adj[261];
    int size;
    Node(){}
    Node( Point p ): pos(p){ size = 0;}
    void push_back(Edge e){ adj[size++] = e; }
};

double dot(Vector a, Vector b){
    return real(conj(a)*b);
}

double cross(Vector a, Vector b){
    return imag(conj(a)*b);
}

bool isParallel( Segment s1, Segment s2 ){
    return equals( cross(s1.target - s1.source, s2.target - s2.source), 0.0 );
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
    return isIntersect(s1.source, s1.target, s2.source, s2.target);
}

Point getCrossPointLines( Segment s1, Segment s2){
    Vector a = s1.target - s1.source;
    Vector base = s2.target - s2.source;
    return s1.source + a * cross(base, s2.source - s1.source)/cross(base, a);
}

double getDistance(Vector a, Vector b){
    return abs(a - b); 
}

#define MAX 311 // 420
#define SMAX 1024

int n, nnode;
Node P[MAX];

ushort CCW1[MAX][10][MAX], CCW2[10][MAX][10];

bool noPoint( int p0, int p1 ){
    for ( int i = 0; i < nnode; i++ ){
	if ( i == p0 || i == p1 ) continue;
	if ( ccw( P[p0].pos, P[p1].pos, P[i].pos ) == ON_SEGMENT ) return false;
    }
    return true;
}

void setEdge( int p0, int p1, int p2 ){
    int ccwv = ccw( P[p0].pos, P[p1].pos, P[p2].pos ); 
    if ( ccwv == ONLINE_FRONT ) {
	if ( noPoint(p1, p2) ){
	    P[p1].push_back(Edge(p2, getDistance(P[p1].pos, P[p2].pos)));
	    P[p2].push_back(Edge(p1, getDistance(P[p1].pos, P[p2].pos)));
	}
    } else if ( ccwv == ONLINE_BACK ){
	if ( noPoint(p0, p2) ){
	    P[p0].push_back(Edge(p2, getDistance(P[p0].pos, P[p2].pos)));
	    P[p2].push_back(Edge(p0, getDistance(P[p0].pos, P[p2].pos)));
	}
    } 
}

void addNode( int i , int j, int k, int l ){
    Segment s1 = Segment(P[i].pos, P[j].pos);
    Segment s2 = Segment(P[k].pos, P[l].pos);
    if ( isParallel(s1, s2) ) return;
    Point x = getCrossPointLines(s1, s2);
    for ( int p = 0; p < nnode; p++ ) if ( x == P[p].pos ) return;

    if ( ccw( P[i].pos, P[j].pos, x ) == ON_SEGMENT ||
	 ccw( P[k].pos, P[l].pos, x ) == ON_SEGMENT  ) return;

    P[n++] = Node(x);
    setEdge( i, j, n-1 );
    setEdge( k, l, n-1 );
}

ushort getNTurnComp( int p0, int p1, int p2 ){
    if ( ccw( P[p0].pos, P[p1].pos, P[p2].pos ) == ONLINE_FRONT ||
	 P[p2].pos == P[p1].pos ) return 0;
    else return 1;
}

void makeGraph(){
    for ( int i = 0; i < nnode-1; i++ ){
	for ( int j = i+1; j < nnode; j++ ){
	    if ( noPoint(i, j) ){
		P[i].push_back(Edge(j, getDistance(P[i].pos, P[j].pos)));
		P[j].push_back(Edge(i, getDistance(P[i].pos, P[j].pos)));
	    }
	}
    }
    n = nnode;
    for ( int i = 0; i < nnode-3; i++ ){
	for ( int j = i+1; j < nnode-2; j++ ){
	    for ( int k = j+1; k < nnode-1; k++ ){
		for ( int l = k+1; l < nnode; l++ ){
		    addNode( i, j, k, l );
		    addNode( i, k, j, l );
		    addNode( i, l, j, k );
		}
	    }
	}
    }

    rep(i, n) rep(j, nnode) rep(k, n) CCW1[i][j][k] = getNTurnComp(i, j, k);
    rep(i, nnode) rep(j, n) rep(k, nnode) CCW2[i][j][k] = getNTurnComp(i, j, k);
}

class QState{
    public:
    ushort state, cur, pre, nturn;
    float dist;
    QState(ushort s=0, ushort c=0, ushort p=0 , ushort t=0, double d=0):state(s), cur(c), pre(p), nturn(t), dist(d){}

    bool operator < ( const QState &q ) const{
	return dist > q.dist;
    }
};

static const int S[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

QState getState( priority_queue<QState> PQ[5] ){
    for ( int i = 0; i <= 4; i++ ){
	if ( PQ[i].size() ) { QState s = PQ[i].top(); PQ[i].pop(); return s; }
    }
}

void dijkstra(){
    priority_queue<QState> PQ[5];
    bool C[10][MAX][SMAX];
    rep(i, nnode) rep(j, n) rep(k, (1<<nnode)) C[i][j][k]= false;

    rep(s, nnode) rep(i, P[s].size) {
	int v = P[s].adj[i].t;
	if ( v < nnode ){
	    PQ[0].push(QState(S[s]|S[v], v, s, 0, P[s].adj[i].d));
	} else {
	    rep(j, P[v].size){
		int vv = P[v].adj[j].t;
		if ( vv == s ) continue;
		int nt = CCW2[s][v][vv]; 
		PQ[nt].push(QState(S[s]|S[vv], vv, v, nt, P[s].adj[i].d + P[v].adj[j].d));
	    }
	}
    }

    QState u;
    while(1){
	u = getState(PQ);
	if ( u.state == S[nnode]-1 ) {
	    printf("%d %.5lf\n", u.nturn, u.dist);
	    return;
	}
	if ( C[u.cur][u.pre][u.state] ) continue;
	C[u.cur][u.pre][u.state] = true;

	int p0 = u.pre;
	int p1 = u.cur;
	int p2, p3;

	rep(i, P[p1].size){
	    int p2 = P[p1].adj[i].t;
	    double ndist = P[p1].adj[i].d;
	    if ( p2 < nnode ){
		ushort state = (u.state|S[p2]);
		ushort nt = u.nturn + CCW1[p0][p1][p2];
		if ( nt >= 5 ) continue;
		double nd = u.dist + ndist;
		if ( !C[p2][p1][state] ) PQ[nt].push(QState(state, p2, p1, nt, nd));
	    } else {
		rep(j, P[p2].size ){
		    p3 = P[p2].adj[j].t;
		    if ( p3 == p1 ) continue;
		    ushort state = (u.state|S[p3]);
		    ushort nt = u.nturn + CCW1[p0][p1][p2] + 1;
		    if ( nt >= 5 ) continue;
		    double nd = u.dist + ndist + P[p2].adj[j].d;
		    if ( !C[p3][p2][state] ) PQ[nt].push(QState(state, p3, p2, nt, nd));
		}
	    }
	}
    }
}

main(){
    while( cin >> nnode && nnode ){
	Point p;
	rep(i, nnode){
	    Point p;
	    cin >> p.real() >> p.imag(); P[i] = Node(p);
	}
	makeGraph();
	dijkstra();
    }
}

// 解説の通り Dijkstra で解いてみました。
// 与えられた点を通る２つの直線の組み合わせについて、交点を求め,
// その交点と入力された点の集合について TSP を解くような感じです。
// 状態は S[現在の点(入力された点のみ)][前にいた点][通った点の状態(入力された点のみ)] になります。
// ただし、無駄な交点を作ってしまうとTLEになります。


// コードは, Dijkstra の部分のみです。
