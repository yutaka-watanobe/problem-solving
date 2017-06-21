#include<iostream>
#include<complex>
#include<cfloat>
#include<cassert>
#include<map>
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
    vector<Edge> adjList;
    Node(){}
    Node( Point p ): pos(p){}
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

#define MAX 640

int n, nnode;
Node P[MAX];

void setEdge( int p0, int p1, int p2 ){
    int ccwv = ccw( P[p0].pos, P[p1].pos, P[p2].pos ); 
    if ( ccwv == ONLINE_FRONT ) {
	P[p1].adjList.push_back(Edge(p2, getDistance(P[p1].pos, P[p2].pos)));
	P[p2].adjList.push_back(Edge(p1, getDistance(P[p1].pos, P[p2].pos)));
    } else if ( ccwv == ONLINE_BACK ){
	P[p0].adjList.push_back(Edge(p2, getDistance(P[p0].pos, P[p2].pos)));
	P[p2].adjList.push_back(Edge(p0, getDistance(P[p0].pos, P[p2].pos)));
    } else if ( ccwv == ON_SEGMENT ){
	P[p1].adjList.push_back(Edge(p2, getDistance(P[p1].pos, P[p2].pos)));
	P[p2].adjList.push_back(Edge(p1, getDistance(P[p1].pos, P[p2].pos)));
	P[p0].adjList.push_back(Edge(p2, getDistance(P[p0].pos, P[p2].pos)));
	P[p2].adjList.push_back(Edge(p0, getDistance(P[p0].pos, P[p2].pos)));
    }
}

void addNode( int i , int j, int k, int l ){
    Segment s1 = Segment(P[i].pos, P[j].pos);
    Segment s2 = Segment(P[k].pos, P[l].pos);
    if ( isParallel(s1, s2) ) return;
    Point x = getCrossPointLines(s1, s2);
    for ( int p = 0; p < nnode; p++ ){
      if ( x == P[p].pos ) return;
    }

    P[n++] = Node(x);
    setEdge( i, j, n-1 );
    setEdge( k, l, n-1 );
}

void makeGraph(){
    for ( int i = 0; i < nnode-1; i++ ){
	for ( int j = i+1; j < nnode; j++ ){
	    P[i].adjList.push_back(Edge(j, getDistance(P[i].pos, P[j].pos)));
	    P[j].adjList.push_back(Edge(i, getDistance(P[i].pos, P[j].pos)));
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
	if ( cur != s.cur ) return cur < s.cur;
	if ( pre != s.pre ) return pre < s.pre;
	return state < s.state;
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
	if ( nturn != q.nturn ) return nturn > q.nturn;
	return dist > q.dist;
    }
};


int mint;
double mind;

int getNTurn( int p0, int p1, int p2 ){
    if ( ccw( P[p0].pos, P[p1].pos, P[p2].pos ) == ONLINE_FRONT ||
	 P[p2].pos == P[p1].pos ) return 0;
    else return 1;
}

void dijkstra( int start ){
    priority_queue<QState> PQ;
    map<VState, bool> V;
    map<VState, bool> C;
    map<VState, pair<int, double> > D;

    for ( int i = 0; i < P[start].adjList.size(); i++ ){
	int v = P[start].adjList[i].t;
	if ( v < nnode ){
	    int value = ((1<<start) | (1<<v));
	    VState vs = VState(value, v, start);
	    V[vs] = true;
	    D[vs] = make_pair(0, P[start].adjList[i].d);
	    PQ.push(QState(vs, 0, D[vs].second));
	} else {
	    for ( int j = 0; j < P[v].adjList.size(); j++ ){
		int vv = P[v].adjList[j].t;
		if ( vv == v ) continue;
		assert( vv < nnode );
		int value = ((1<<start) | (1<<vv));
		VState vs = VState(value, vv, v);
		V[vs] = true;
		D[vs] = make_pair(getNTurn(start, v, vv), P[start].adjList[i].d + P[v].adjList[j].d);
		PQ.push(QState(vs, D[vs].first, D[vs].second));
	    }
	}
    }

    QState u;
    while( !PQ.empty() ){
	//	cout << PQ.size() << endl;
	u = PQ.top(); PQ.pop();
	//		cout << u.vstate.state << endl;
	//		cout << u.nturn << " " << u.dist <<endl;
	if ( u.vstate.state == (1<<nnode)-1 ) {
	    if ( mint > u.nturn ){
		mint = u.nturn;
		mind = u.dist;
	    } else if ( mint == u.nturn ){
		mind = min ( mind, u.dist );
	    }
	    return;
	}
	if ( C[u.vstate] ) continue;
	C[u.vstate] = true;
	
	int p0 = u.vstate.pre;
	int p1 = u.vstate.cur;
	int p2, p3;
	for ( int i = 0; i < P[p1].adjList.size(); i++ ){
	    int p2 = P[p1].adjList[i].t;
	    double ndist = P[p1].adjList[i].d;

	    if ( p2 < nnode ){
		VState vs = VState( u.vstate.state | (1 << p2), p2, p1 );
		int nt = u.nturn + getNTurn(p0, p1, p2);
		double nd = u.dist + ndist;
		if ( V[vs] ){
		    if ( (D[vs].first > nt) || (D[vs].first == nt && D[vs].second > nd ) ){
			D[vs] = make_pair(nt, nd);
			PQ.push(QState(vs, nt, nd));
		    }
		} else {
		    V[vs] = true;
		    D[vs] = make_pair(nt, nd);
		    PQ.push(QState(vs, nt, nd));
		}
	    } else {
		for ( int j = 0; j < P[p2].adjList.size(); j++ ){
		    p3 = P[p2].adjList[j].t;
		    //		    assert( p3 < nnode );
		    double ndist2 = P[p2].adjList[j].d;
		    VState vs = VState( u.vstate.state | (1<<p3), p3, p2);
		    int nt = u.nturn + getNTurn(p0, p1, p2) + getNTurn(p1, p2, p3);
		    double nd = u.dist + ndist + ndist2;
		    if ( V[vs] ){
			if ( (D[vs].first > nt)  || (D[vs].first == nt && D[vs].second > nd )){
			    D[vs] = make_pair(nt, nd);
			    PQ.push(QState(vs, nt, nd));
			}
		    } else {
			V[vs] = true;
			D[vs] = make_pair(nt, nd);
			PQ.push(QState(vs, nt, nd));
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
    for ( int i = 0; i < nnode; i++ ) dijkstra(i);
    cout << mint << " " << mind << endl;
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
