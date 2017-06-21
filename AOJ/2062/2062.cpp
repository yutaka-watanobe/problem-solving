#include<iostream>
#include<stdio.h>
#include<complex>
#include<cfloat>
#include<cassert>

#include<vector>
#include<queue>
#include<algorithm>

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

//bool eq(Point a, Point b){
//    return abs(real(a)-real(b))< EPS && abs(imag(a)-imag(b)) < EPS;
//}

double getDistance(Vector a, Vector b){
    return abs(a - b); 
}

double dot(Vector a, Vector b){
    return real(conj(a)*b);
}

double cross(Vector a, Vector b){
    return imag(conj(a)*b);
}

bool isOnSegment( Point a, Point b, Point c){
  //    if ( eq(a,c) || eq(b,c) ) return true;
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
    /*
    if (isOnSegment(p1, p2, p3) || isOnSegment(p1, p2, p4) ||
	isOnSegment(p3, p4, p1) || isOnSegment(p3, p4, p2) ) return true;
    return ( cross(p2 - p1, p4 - p1) * cross(p2 - p1, p3 - p1) <= 0 &&
	     cross(p4 - p3, p1 - p3) * cross(p4 - p3, p2 - p3) <= 0 );
    */
    // this is much more faster!!!!!
    return ( ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
	     ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0 );

}

bool isIntersect(Segment s1, Segment s2){
    return isIntersect(s1.source, s1.target, s2.source, s2.target);
}

Point getCrossPoint(Segment s1, Segment s2){
  //    assert( isIntersect(s1, s2) );
    Vector base = s2.target - s2.source;
    double d1 = abs(cross(base, s1.source - s2.source));
    double d2 = abs(cross(base, s1.target - s2.source));
    double t = d1/(d1 + d2);
    return s1.source + (s1.target - s1.source)*t;
}

#define MAX 2000
#define NMAX 80000
#define LIMIT FLT_MAX

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

int nnode;
Point SP[NMAX];

int getIndex( Point p ){
    SP[nnode++] = p;
    return nnode-1;
}

void makeGraph(Graph &g, Segment S[MAX], int N, Point s ){
    Segment base, target;
    Node L[NMAX];
    int beg, p = 0;
    bool startSet = false;
    nnode = 0;
    for ( int b = 0; b < N; b++ ){
	base = S[b];
	beg = p;

	if ( !startSet && isOnSegment(base.source, base.target, s) ){
	    L[p++] = Node(s, getIndex(s));
	    startSet = true;
	}

	L[p++] = Node(base.source, getIndex(base.source));
	L[p++] = Node(base.target, getIndex(base.target));

	for ( int t = 0; t < N; t++ ){
	    if ( t == b ) continue;
	    target = S[t];
	    if ( !isIntersect(base, target) ) continue;
	    Point cp = getCrossPoint(base, target);
	    L[p++] = Node(cp, getIndex(cp));
	}

	sort(L + beg, L + p );

	for ( int i = beg; i < p-1; i++ ){
	    g.connect(L[i].id, L[i+1].id, getDistance(L[i].p, L[i+1].p));
	}
    }

    sort( L, L + p );

    for ( int i = 0; i < p-1; i++ ){
      //	if ( eq(L[i].p, L[i+1].p) ) 
      if ( L[i].p ==  L[i+1].p ) 
	    g.connect( L[i].id, L[i+1].id, 0.0);
      //	if ( eq(L[i].p, s) ) g.start = L[i].id;
      if ( L[i].p == s ) g.start = L[i].id;
    }

}

double dijkstra(Graph g){
    bool visited[NMAX];
    double D[NMAX];
    priority_queue<QNode> PQ;
    
    for ( int i = 0; i < nnode; i++ ) {
	visited[i] = false;
	D[i] = LIMIT;
    }

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

    double mdist = 0.0;

    for ( int i = 0; i < nnode; i++ ){
	mdist = max(mdist, D[i] );
	for ( int k = 0; k < g.adjList[i].size(); k++ ){
	    int j = g.adjList[i][k].target;
	    double d = getDistance(SP[i], SP[j]);
	    mdist = max(mdist, (double)(min(D[i], D[j]) + (d - abs(D[i]-D[j]))/2.0));
	}
    }
    return mdist;
}

int main(){
    int N;
    Segment S[MAX];

    while( cin >> N && N ){
	Point p1, p2;
	for ( int i = 0; i < N; i++ ){
	    cin >> p1.real(); cin >> p1.imag();
	    cin >> p2.real(); cin >> p2.imag();
	    S[i] = Segment(p1, p2);
	}
	cin >> p1.real(); cin >> p1.imag();
	Graph g;
	makeGraph(g, S, N, p1);
	printf("%.5lf\n", dijkstra(g));
    }

    return 0;
}

