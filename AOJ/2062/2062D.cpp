#include<iostream>
#include<stdio.h>
#include<complex>
#include<cfloat>
#include<cassert>

#include<map>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define EPS (1e-5)
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
	return equals(a, b);
	//return abs(real(a)-real(b))< EPS && abs(imag(a)-imag(b)) < EPS;
    }
}

class Segment{
    public:
    Point source, target;
    Segment(Point s = Point(), Point t = Point()): source(s), target(t){}
};

double getDistance(Vector a, Vector b){
    return abs(a - b); 
}

double dot(Vector a, Vector b){
    return real(conj(a)*b);
}

double cross(Vector a, Vector b){
    return imag(conj(a)*b);
}

bool isIntersect(Point p1, Point p2, Point p3, Point p4){
    return ( cross(p2 - p1, p4 - p1) * cross(p2 - p1, p3 - p1) <= 0 &&
	     cross(p4 - p3, p1 - p3) * cross(p4 - p3, p2 - p3) <= 0 );
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

bool isOnSegment( Point a, Point b, Point c){
    return (abs(a-c) + abs(c-b) < abs(a-b) + EPS );
}

#define MAX 1000
#define NMAX 40000

class Edge{
    public:
    int target;
    double dist;
    Edge(){}
    Edge(int target, double dist): target(target), dist(float(dist)){}
};

class Graph{
    public:
    vector<Edge> adjList[NMAX];
    int start;
    int nedge;
    Graph(){
	for ( int i = 0; i < NMAX; i++ ) adjList[i].clear();
	nedge = 0;
    }
    
    void connect( int i, int j, double d ){
	adjList[i].push_back(Edge(j, d));
	adjList[j].push_back(Edge(i, d));
	//		cout << i << "-" << j << endl;
	nedge += 2;
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

int nnode;

map<Point, int> PS; // point set

int getIndex( Point p ){
    //    if ( PS.find(p) == PS.end() ){
    if ( PS.count(p) == 0 ){
	PS[p] = nnode++;
	//	printf("%.30lf %.30lf\n", p.real(), p.imag());
    } 
    return PS[p];
}

void makeGraph(Graph &g, Segment S[MAX], int N, Point s ){
    Segment base, target;
    vector<Point> v;
    PS = map<Point, int>();
    nnode = 0;

    for ( int b = 0; b < N; b++ ){
	base = S[b];
	v.clear();
	if ( isOnSegment(base.source, base.target, s) ){
	    g.start = getIndex(s);
	    v.push_back(s);
	}
	v.push_back(base.source);
	v.push_back(base.target);
	for ( int t = 0; t < N; t++ ){
	    if ( t == b ) continue;
	    target = S[t];
	    if ( !isIntersect(base, target) ) continue;
	    Point cp = getCrossPoint(base, target);
	    v.push_back(cp);
	}
	sort(v.begin(), v.end());
	for ( int i = 0; i < v.size()-1; i++ ){
	    g.connect(getIndex(v[i]), getIndex(v[i+1]), getDistance(v[i], v[i+1]));
	    //	    cout << g.nedge << endl;
	}
    }
}

void dijkstra(Graph g ){

    for ( int i = 0; i < nnode; i++ ){
	if ( g.adjList[i].size() == 0 ){
	    cout << i << endl;
	}
    }


    bool visited[NMAX];
    bool isLeaf[NMAX];
    double D[NMAX];

    for ( int i = 0; i < nnode; i++ ) {
	visited[i] = false;
	isLeaf[i] = true;
	//D[i] = FLT_MAX;
	D[i] = 2000000.0;
    }
        cout << "nnode = " << nnode << endl;
    //    cout << "start = " << g.start << endl;
    priority_queue<QNode> PQ;

    for ( int i = 0; i < g.adjList[g.start].size(); i++ ){
	Edge v = g.adjList[g.start][i];
	PQ.push(QNode(v.target, v.dist) );
	D[v.target] = v.dist;
	isLeaf[g.start] = false;
    }

    //   PQ.push(QNode(g.start, 0.0));
    //    visited[g.start] = true;
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
		//pi[v.index] = u.index;
		isLeaf[u.index] = false;
		PQ.push(QNode(v.target, D[v.target]));
	    }
	}
    }

    double mdist = 0.0;
    for ( int i = 0; i < nnode; i++ ){
	mdist = max(mdist, D[i] );
    }

    printf("%.5lf\n", mdist);
    
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
	
	dijkstra(g);
    }

    return 0;
}
