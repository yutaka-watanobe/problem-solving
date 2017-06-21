#include<cstdio>
#include<iostream>
#include<complex>
#include<cfloat>
#include<cassert>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

#define EPS (1e-8)
#define equals(a, b) (abs((a) - (b)) < EPS )

typedef complex<double> Point;
typedef complex<double> Vector;


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
    Edge adjList[261];
    int s;
    Node(){}
    Node( Point p ): pos(p){ s = 0;}

    int size(){ return s; }
    void push_back(Edge e){
	adjList[s++] = e;
    }
};

double dot(Vector a, Vector b){
    return real(conj(a)*b);
}

double cross(Vector a, Vector b){
    return imag(conj(a)*b);
}

Point project( Segment s, Point p ){
    Vector base = s.target - s.source;
    double t = dot(p - s.source, base)/norm(base);
    return s.source + t*(base);
}

Point reflect( Segment s, Point p ){
    return p + 2.0*(project(s, p) - p);
}

// verified by uoa2062
bool isOnSegment( Point a, Point b, Point c){
    if ( a == c || b == c ) return true;
    return (abs(a-c) + abs(c-b) < abs(a-b) + EPS );
}
bool isOnSegment( Segment s, Point c ){
    return isOnSegment( s.source, s.target, c);
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

Point getCrossPoint(Segment s1, Segment s2){
    assert( isIntersect(s1, s2) );
    Vector base = s2.target - s2.source;
    double d1 = abs(cross(base, s1.source - s2.source));
    double d2 = abs(cross(base, s1.target - s2.source));
    double t = d1/(d1 + d2);
    return s1.source + (s1.target - s1.source)*t;
}

Point getCrossPointLines( Segment s1, Segment s2){
    Vector a = s1.target - s1.source;
    Vector base = s2.target - s2.source;
    return s1.source + a * cross(base, s2.source - s1.source)/cross(base, a);
}

double getDistance(Vector a, Vector b){
    return abs(a - b); 
}

double getDistance(Segment s, Point p){
    if ( dot(s.target - s.source, p - s.source) < 0.0 ) return abs(p - s.source);
    if ( dot(s.source - s.target, p - s.target) < 0.0 ) return abs(p - s.target);
    return abs(cross(s.target - s.source, p - s.source)/abs(s.target - s.source));
}

double getDistance(Segment s1, Segment s2){
    if ( isIntersect(s1, s2) ) return 0.0;
    return min( min(getDistance(s1, s2.source), getDistance(s1, s2.target)),
		min(getDistance(s2, s1.source), getDistance(s2, s1.target)));
}


Vector normal( Vector a ){
    return a * Point(0, 1);
}

//#define MAX 640
#define MAX 1270

int n, nnode;
Node P[MAX];

unsigned short CCW1[MAX][10][MAX];
unsigned short CCW2[10][MAX][10];


bool noPoint( int p0, int p1 ){
    for ( int i = 0; i < nnode; i++ ){
	if ( i == p0 || p1 == 0 ) continue;
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
    /*
    else if ( ccwv == ON_SEGMENT ){
	if ( noPoint(p1, p2) ){
	    P[p1].push_back(Edge(p2, getDistance(P[p1].pos, P[p2].pos)));
	    P[p2].push_back(Edge(p1, getDistance(P[p1].pos, P[p2].pos)));
	}
	if ( noPoint(p0, p2) ){
	    P[p0].push_back(Edge(p2, getDistance(P[p0].pos, P[p2].pos)));
	    P[p2].push_back(Edge(p0, getDistance(P[p0].pos, P[p2].pos)));
	}
	}*/
}

void addNode( int i , int j, int k, int l ){
    Segment s1 = Segment(P[i].pos, P[j].pos);
    Segment s2 = Segment(P[k].pos, P[l].pos);
    if ( isParallel(s1, s2) ) return;
    Point x = getCrossPointLines(s1, s2);
    for ( int p = 0; p < nnode; p++ ){
      if ( x == P[p].pos ) return;
    }


    if ( ccw( P[i].pos, P[j].pos, x ) == ON_SEGMENT ||
	 ccw( P[k].pos, P[l].pos, x ) == ON_SEGMENT  ) return;

    P[n++] = Node(x);

    setEdge( i, j, n-1 );
    setEdge( k, l, n-1 );
}

int getNTurnComp( int p0, int p1, int p2 ){
    if ( ccw( P[p0].pos, P[p1].pos, P[p2].pos ) == ONLINE_FRONT ||
	 P[p2].pos == P[p1].pos ) return 0;
    else return 1;
}

int getNTurn( int p0, int p1, int p2 ){
    if ( p1 < nnode ) return CCW1[p0][p1][p2];
    else return CCW2[p0][p1][p2];
}

void makeGraph(){
    for ( int i = 0; i < nnode-1; i++ ){
	for ( int j = i+1; j < nnode; j++ ){
	    P[i].push_back(Edge(j, getDistance(P[i].pos, P[j].pos)));
	    P[j].push_back(Edge(i, getDistance(P[i].pos, P[j].pos)));
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

    //ccw1
    for ( int i = 0; i < n; i++ ){
	for ( int j = 0; j < nnode; j++ ){
	    for ( int k = 0; k < n; k++ ){
		CCW1[i][j][k] = getNTurnComp(i, j, k);
	    }
	}
    }
    for ( int i = 0; i < nnode; i++ ){
	for ( int j = 0; j < n; j++ ){
	    for ( int k = 0; k < nnode; k++ ){
		CCW2[i][j][k] = getNTurnComp(i, j, k);
	    }
	}
    }

    /*
    for ( int i = 0; i < n; i++ ){
	cout << i << " " << P[i].pos.real() << ", " << P[i].pos.imag() << "   adj: ";
	for ( int j = 0; j < P[i].adjList.size(); j++ ){
	    cout << P[i].adjList[j].t << " ";
	}
	cout << endl;

    }
    cout << "----------" << endl;
    */
}
class VState{
    public:
    int state, cur, pre;
    VState(int s=0, int c=0, int p=0): state(s), cur(c), pre(p){}

    bool operator < ( const VState &s ) const{

	if ( state != s.state ) return state < s.state;
	if ( cur != s.cur ) return cur < s.cur;
	// cur == s.cur
	
	double dx1 = P[cur].pos.real() - P[pre].pos.real();
	double dy1 = P[cur].pos.imag() - P[pre].pos.imag();
	double dx2 = P[cur].pos.real() - P[s.pre].pos.real();
	double dy2 = P[cur].pos.imag() - P[s.pre].pos.imag();

	return dy1*dx2 < dy2*dx1;
	return pre < s.pre;


	
	//if ( state != s.state ) return state < s.state;
	//if ( cur != s.cur ) return cur < s.cur;
	//return pre < s.pre;
	//return cur < s.cur;


	//if ( cur != s.cur ) return cur < s.cur;
	//if ( pre != s.pre ) return pre < s.pre;
	//return state < s.state;
    }
};

class QState{
    public:
    VState vstate;
    int nturn;
    double dist;
    QState(){}
    QState( VState vs, int t, double d):vstate(vs), nturn(t), dist(d){}

    bool operator < ( const QState &q ) const{
	//if ( nturn != q.nturn ) return nturn > q.nturn;
	return dist > q.dist;
    }
};


int mint;
double mind;
int smax, qmax;
static const int S[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

QState getState( priority_queue<QState> PQ[5] ){
    /*
    for ( int i = 0; i <= 4; i++ ){
	if ( PQ[i].size() ) {
	    QState s = PQ[i].top(); PQ[i].pop();
	    return s;
	}
	}*/
    if ( PQ[0].size() ) { QState s = PQ[0].top(); PQ[0].pop(); return s; }
    if ( PQ[1].size() ) { QState s = PQ[1].top(); PQ[1].pop(); return s; }
    if ( PQ[2].size() ) { QState s = PQ[2].top(); PQ[2].pop(); return s; }
    if ( PQ[3].size() ) { QState s = PQ[3].top(); PQ[3].pop(); return s; }
    if ( PQ[4].size() ) { QState s = PQ[4].top(); PQ[4].pop(); return s; }
    assert( false );
}

//void dijkstra( int start ){
void dijkstra(){
    priority_queue<QState> PQ[5];
    //    map<VState, bool> V;
    set<VState> V[5];
    map<VState, bool> C;
    map<VState, double> D[5];

    for ( int start = 0; start < nnode; start++ ){
	for ( int i = 0; i < P[start].size(); i++ ){
	    int v = P[start].adjList[i].t;
	    if ( v < nnode ){
		//int value = ((1<<start) | (1<<v));
		int value = ( S[start] | S[v] );
		VState vs = VState(value, v, start);
		//V[vs] = true;
		V[0].insert(vs);
		D[0][vs] = P[start].adjList[i].d;
		PQ[0].push(QState(vs, 0, D[0][vs]));
	    } else {
		for ( int j = 0; j < P[v].size(); j++ ){
		    int vv = P[v].adjList[j].t;
		    if ( vv == start ) continue;
		    assert( vv < nnode );
		    //int value = ((1<<start) | (1<<vv));
		    int value = ( S[start] | S[vv] );
		    VState vs = VState(value, vv, v);
		    //		V[vs] = true;
		    int nt = getNTurn(start, v, vv);
		    V[nt].insert(vs);
		    D[nt][vs] = P[start].adjList[i].d + P[v].adjList[j].d;
		    PQ[nt].push(QState(vs, nt, D[nt][vs]));
		}
	    }
	}
    }

    QState u;
    int cnt = 0;
    int maxsize = 0;
    while(1){
	//smax = max( smax, (int)(V.size()) );
	//qmax = max( qmax, (int)(PQ.size()));
	//	cout << PQ.size() << endl;
	//	if ( PQ[0].size() + PQ[1].size() + PQ[2].size() + PQ[3].size() + PQ[4].size() == 0 ) break;
	u = getState(PQ);
	//		cout << u.vstate.state << endl;
	//		cout << u.nturn << " " << u.dist <<endl;
	//	if ( u.vstate.state == (1<<nnode)-1 ) {
	if ( u.vstate.state == S[nnode]-1 ) {
	    if ( mint > u.nturn ){
		mint = u.nturn;
		mind = u.dist;
	    } else if ( mint == u.nturn ){
		mind = min ( mind, u.dist );
	    }
	    //	    cout << cnt << "  " << maxsize << "   ";
	    return;
	}
	if ( C[u.vstate] ) continue;
	C[u.vstate] = true;
	int p0 = u.vstate.pre;
	int p1 = u.vstate.cur;
	int p2, p3;

	/*
	int target = -1;
	for ( int i = 0; i < nnode; i++ ){
	    if ( (u.vstate.state | S[i]) == S[nnode]-1 ){
		target = i;
	    }
	    }*/

	for ( int i = 0; i < P[p1].size(); i++ ){
	    int p2 = P[p1].adjList[i].t;
	    //	    if ( target != -1 && p2 != target ) continue;

	    double ndist = P[p1].adjList[i].d;

	    if ( p2 < nnode ){
		//VState vs = VState( u.vstate.state | (1 << p2), p2, p1 );
		VState vs = VState( u.vstate.state | S[p2], p2, p1 );
		int nt = u.nturn + getNTurn(p0, p1, p2);
		if ( nt >= 5 ) continue;
		double nd = u.dist + ndist;
		//if ( V[vs] ){
		//		if ( V[nt].count(vs) ){
		if ( V[nt].find(vs) != V[nt].end() ){
		    if ( D[nt][vs] > nd  ){
			D[nt][vs] = nd;
			PQ[nt].push(QState(vs, nt, nd));
		    }
		} else {
		    //V[vs] = true;
		    V[nt].insert(vs);
		    D[nt][vs] = nd;
		    PQ[nt].push(QState(vs, nt, nd));
		}
	    } else {
		maxsize = max( maxsize, P[p2].size() );
		for ( int j = 0; j < P[p2].size(); j++ ){


		    p3 = P[p2].adjList[j].t;
		    if ( p3 == p1 ) continue;
		    //		    assert( p3 < nnode );
		    double ndist2 = P[p2].adjList[j].d;
		    //VState vs = VState( u.vstate.state | (1<<p3), p3, p2);
		    VState vs = VState( u.vstate.state | S[p3], p3, p2);
		    int ntt = getNTurn(p1, p2, p3);
		    //		    if ( ntt == 0 ) continue;
		    int nt = u.nturn + getNTurn(p0, p1, p2) + ntt;
		    if ( nt >= 5 ) continue;
		    cnt++;
		    double nd = u.dist + ndist + ndist2;
		    //if ( V[vs] ){
		    //if ( V[nt].count(vs) ){
		    if ( V[nt].find(vs) != V[nt].end() ){
			if (  D[nt][vs] > nd ){
			    D[nt][vs] = nd;
			    PQ[nt].push(QState(vs, nt, nd));
			}
		    } else {
			//V[vs] = true;
			V[nt].insert(vs);
			D[nt][vs] = nd;
			PQ[nt].push(QState(vs, nt, nd));
		    }
		}
	    }
	}
    }
}

void compute(){
    //    cout << "n = " << n << endl;
    mint = 100;
    mind = FLT_MAX;
    smax = qmax = 0;
    //    for ( int i = 0; i < nnode; i++ ) dijkstra(i);
    dijkstra();
    //    cout << "n = " << n << " smax = " << smax << " qmax = " << qmax << endl;
    //    cout << mint << " " << mind << endl;
    printf("%d %.5lf\n", mint, mind);
}

main(){
    while( cin >> nnode && nnode ){
	Point p;
	for ( int i = 0; i < nnode; i++ ){
	    Point p;
	    cin >> p.real() >> p.imag(); P[i] = Node(p);
	}
	makeGraph();
	compute();
    }
}
