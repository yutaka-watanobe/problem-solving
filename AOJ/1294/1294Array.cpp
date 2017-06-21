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



//static const int NMAX =  640;
static const int NMAX =  400;
static const int PMAX = 10;
static const int SMAX = (1<<10);

int n, nnode;
Node P[NMAX];

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
    P[n++] = Node(getCrossPointLines(s1, s2));
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

void dijkstra( int start ){
    priority_queue<QState> PQ;
    bool V[PMAX][NMAX][SMAX];
    unsigned short T[PMAX][NMAX][SMAX];
    double D[PMAX][NMAX][SMAX];

    for ( int i = 0; i < nnode; i++ ){
	for ( int j = 0; j < n; j++ ){
	    for ( int k = 0; k < (1<<nnode); k++ ){
		V[i][j][k] = false;
		T[i][j][k] = 100;
		D[i][j][k] = FLT_MAX;
	    }
	}
    }

    for ( int i = 0; i < P[start].adjList.size(); i++ ){
	int v = P[start].adjList[i].t;
	int value = (1<<start);
	if ( v < nnode ) value |= (1<<v);
	VState vs = VState(value, start, v);
	T[v][start][value] = 0;
	D[v][start][value] = P[start].adjList[i].d;
	PQ.push(QState(vs, 0, P[start].adjList[i].d) );
    }

    QState u;
    while( !PQ.empty() ){
	//	cout << PQ.size() << endl;
	u = PQ.top(); PQ.pop();
	//cout << u.nturn << " " << u.dist <<endl;

	if ( u.vstate.state == (1<<nnode)-1 ) {
	    if ( mint > u.nturn ){
		mint = u.nturn;
		mind = u.dist;
	    } else if ( mint == u.nturn ){
		mind = min ( mind, u.dist );
	    }
	    return;
	}
	V[u.vstate.cur][u.vstate
	//	if ( visited[u.vstate] ) continue;
	//	visited[u.vstate] = true;
	
	int p0 = u.vstate.pre;
	int p1 = u.vstate.cur;
	int p2;
	for ( int i = 0; i < P[u.vstate.cur].adjList.size(); i++ ){
	    int p2 = P[u.vstate.cur].adjList[i].t;
	    double ndist = P[u.vstate.cur].adjList[i].d;
	    int cost = 1;
	    if ( ccw( P[p0].pos, P[p1].pos, P[p2].pos ) == ONLINE_FRONT ||
		 P[p2].pos == P[p1].pos ) cost = 0;
	    VState nextvs;
	    nextvs.pre = u.vstate.cur;
	    nextvs.cur = p2;
	    nextvs.state = u.vstate.state;
	    if ( p2 < nnode ) nextvs.state = (u.vstate.state | (1<<p2) );

	    if ( u.nturn + cost > 5 ) continue;
	    if ( visited[nextvs] ) continue;

	     visited[nextvs] = true;

	    if ( D[nextvs].first ){
		if( D[nextvs].first < u.nturn+cost ) continue;
		if ( D[nextvs].first == u.nturn+cost ){
		    if ( D[nextvs].second < u.dist + ndist ) continue;
		}
		}

	    D[nextvs].first = u.nturn + cost;
	    D[nextvs].second = u.dist + ndist;

	    PQ.push(QState(nextvs, u.nturn+cost, u.dist + ndist));

	}


    }

*/
}

void compute(){
    mint = 100;
    mind = FLT_MAX;
    //    for ( int i = 0; i < nnode; i++ ) dijkstra(i);
    //    cout << mint << " " << mind << endl;
        cout << n << endl;
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
