#include<iostream>
#include<complex>
#include<cfloat>
#include<cassert>

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

Point getCrossPointLine( Segment s1, Segment s2){
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

#define MAX 100
#define SMAX 500
#define NMAX 60000

class Edge{
    public:
    int target;
    double dist;
    Edge(){}
    Edge(int target, double dist): target(target), dist(double(dist)){}
};

class Graph{
    public:
    vector<Edge> adjList[NMAX];
    int start;
    int size;

    Graph(){
	for ( int i = 0; i < NMAX; i++ ) adjList[i].clear();
    }
    
    void connect( int i, int j, double d ){
	adjList[i].push_back(Edge(j, d));
	adjList[j].push_back(Edge(i, d));
    }
};

class QNode{
    public:
    int index;
    double cost;
    QNode(){}
    QNode( int index, double cost ): index(index), cost(cost){}
    
    bool operator < ( const QNode &q ) const { return cost > q.cost; }
};

class Node{
    public:
    Point p;
    int id;
    Node(){}
    Node( Point p, int id): p(p), id(id){}
    bool operator < ( const Node &n) const {
	return p < n.p;
    }
};

void dijkstra(Graph g, int startID, int endID){
    bool visited[NMAX];
    double D[NMAX];
    priority_queue<QNode> PQ;

    int nnode = g.size;

    for ( int i = 0; i < nnode; i++ ) {
	visited[i] = false;
	D[i] = FLT_MAX;
    }

    g.start = startID;

    for ( int i = 0; i < g.adjList[g.start].size(); i++ ){
	Edge v = g.adjList[g.start][i];
	PQ.push(QNode(v.target, v.dist) );
	D[v.target] = v.dist;
    }

    visited[g.start] = true;
    D[g.start] = 0.0;

    QNode u;


    while( !PQ.empty() ){
	u = PQ.top(); PQ.pop();
	
	if ( u.index == endID ) {
	    printf("%.5lf\n", D[endID]);
	    return;
	}

	if ( visited[u.index] ) continue;
	visited[u.index] = true;
	for ( int i = 0; i < g.adjList[u.index].size(); i++ ){
	    Edge v = g.adjList[u.index][i];
	    if ( visited[v.target] ) continue;
	    if ( D[u.index] + v.dist < D[v.target] ){
		D[v.target] = D[u.index] + v.dist;
		PQ.push(QNode(v.target, D[v.target]));
	    }
	}
    }

    cout << "Impossible" << endl;
}

int startID, endID;


void move( Segment &s, Point p ){
    s.source.real() += p.real();
    s.source.imag() += p.imag();
    s.target.real() += p.real();
    s.target.imag() += p.imag();
}

void makeGraph(Graph &g, Point start, Point end, Segment S[SMAX], int size ){
    Segment base, target;
    Node L[NMAX];
    int beg, p = 0;
    bool startSet = false;
    bool endSet = false;

    for ( int b = 0; b < size; b++ ){
	base = S[b];
	beg = p;

	if ( !startSet && abs(ccw(base.source, base.target, start))!= 1 ){
	    L[p] = Node(start, p);
	    p++;
	    startSet = true;
	}

	if ( !endSet && abs(ccw(base.source, base.target, end))!= 1 ){
	    L[p] = Node(end, p);
	    p++;
	    endSet = true;
	}

	for ( int t = 0; t < size; t++ ){
	    if ( t == b ) continue;
	    target = S[t];
	    if ( isParallel(base, target) ) continue;
	    Point cp = getCrossPointLine(base, target);
	    L[p] = Node(cp, p);
	    p++;
	}

	sort(L + beg, L + p );

	for ( int i = beg; i < p-1; i++ ){
	    if ( L[i].p == L[i+1].p ) continue;
	    g.connect(L[i].id, L[i+1].id, getDistance(L[i].p, L[i+1].p));
	}
    }

    g.size = p;

    sort( L, L + p );

    for ( int i = 0; i < p-1; i++ ){
      if ( L[i].p ==  L[i+1].p ) 
	  g.connect( L[i].id, L[i+1].id, 0.0);
    }

    for (  int i = 0; i < p ; i++ ){
	if ( L[i].p == start ) startID = L[i].id;
	if ( L[i].p == end ) endID = L[i].id;
    }
}

void makeGraphF(Graph &g, Point start, Point end, Segment F[MAX], int N ){
    int size = 0;
    Segment S[SMAX];
    
    for ( int i = 0; i < N; i++ ){
	Segment s = F[i];

	Vector n = normal(s.target - s.source);
	Segment ns = Segment(Point(0, 0), Point(n.real(), n.imag()));

	S[size++] = ns; move(S[size-1], s.source);
	S[size++] = ns; move(S[size-1], s.target);

	/*
	if ( isOnSegment(s, project(s, start) ) ){
	    S[size++] = ns; move(S[size-1], start);
	}
	if ( isOnSegment(s, project(s, end) ) ){
	    S[size++] = ns; move(S[size-1], end);
	}
	*/
	if ( ccw(s.source, s.target, project(s, start) ) == ON_SEGMENT ){
	    S[size++] = ns; move(S[size-1], start);
	}
	if ( ccw(s.source, s.target, project(s, end) ) == ON_SEGMENT ){
	    S[size++] = ns; move(S[size-1], end);
	}
    }

    makeGraph(g, start, end, S, size);
}

int main(){
    double sx, sy, tx, ty;

    int tcase = 1;
    Segment F[MAX];
    int N;
    while ( cin >> N && N ){
	Point start, end;
	cin >> start.real() >> start.imag() >> end.real() >> end.imag();
	for ( int i = 0; i < N; i++ ){
	    cin >> sx >> sy >> tx >> ty;
	    F[i] = Segment(Point(sx, sy), Point(tx, ty));
	}
	Graph g;
	startID = -1; 
	endID = -1;
	makeGraphF(g, start, end, F, N);
	cout << "Case " << tcase++ << ": ";
	if ( startID == -1 || endID == -1 ){
	    cout << "Impossible" << endl;
	} else {
	    dijkstra(g, startID, endID);
	}
    }
    return 0;
}
