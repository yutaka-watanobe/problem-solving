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
	//return equals(a, b);
	return abs(real(a)-real(b))< EPS && abs(imag(a)-imag(b)) < EPS;
    }
}

class Segment{
    public:
    Point source, target;
    Segment(Point s = Point(), Point t = Point()): source(s), target(t){}
};

bool eq(Point a, Point b){
    return abs(real(a)-real(b))< EPS && abs(imag(a)-imag(b)) < EPS;
}

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
    if ( eq(a,c) || eq(b,c) ) return true;
    return (abs(a-c) + abs(c-b) < abs(a-b) + EPS );
}

bool isIntersect(Point p1, Point p2, Point p3, Point p4){
    //    if ( p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 ) return true;
    if (isOnSegment(p1, p2, p3) || isOnSegment(p1, p2, p4) ||
	isOnSegment(p3, p4, p1) || isOnSegment(p3, p4, p2) ) return true;
    return ( cross(p2 - p1, p4 - p1) * cross(p2 - p1, p3 - p1) <= 0 &&
	     cross(p4 - p3, p1 - p3) * cross(p4 - p3, p2 - p3) <= 0 );
}

bool isIntersect(Segment s1, Segment s2){
    return isIntersect(s1.source, s1.target, s2.source, s2.target);
}

bool isParallel(Point p1, Point p2, Point p3, Point p4){
    return equals(cross(p1-p2, p3-p4), 0.0);
}

bool isParallel(Segment s1, Segment s2){
    return isParallel(s1.source, s1.target, s2.source, s2.target);
}

Point getCrossPoint(Segment s1, Segment s2){
    assert( isIntersect(s1, s2) );
    Vector base = s2.target - s2.source;
    double d1 = abs(cross(base, s1.source - s2.source));
    double d2 = abs(cross(base, s1.target - s2.source));
    double t = d1/(d1 + d2);
    return s1.source + (s1.target - s1.source)*t;
}



#define MAX 2000
#define NMAX 80000

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
    int nedge;
    Graph(){
	for ( int i = 0; i < NMAX; i++ ) adjList[i].clear();
	nedge = 0;
    }
    
    void connect( int i, int j, double d ){

	adjList[i].push_back(Edge(j, d));
	adjList[j].push_back(Edge(i, d));
	//	cout << i << "-" << j << endl;
	nedge += 2;
    }

    bool isConnected( int s, int t ){
	for ( int i = 0; i < adjList[s].size(); i++ ){
	    if ( adjList[s][i].target == t ) return true;
	}
	return false;
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

map<Point, int> PS; // point set
vector<Point> PV; // point vec

Point SP[NMAX];


int getIndex( Point p ){
    //PS[p] = nnode++;
    SP[nnode++] = p;
    return nnode-1;


    vector<Point>::iterator pos;
    if ( (pos = find(PV.begin(), PV.end(), p)) != PV.end() ){
	return PS[*pos];
    } else { // not found
	PV.insert( lower_bound(PV.begin(), PV.end(), p), p);
	PS[p] = nnode++;
	SP[nnode-1] = p;
	return nnode-1;
    }


    for ( int i = 0; i < nnode; i++ ){
	Point s = SP[i];
	if ( abs(s.real()-p.real()) < EPS && abs(s.imag()-p.imag()) < EPS ) {
	    return i;
	}
    }
    nnode++;
    SP[nnode-1] = p;
    return nnode-1;

    /*
    if ( PS.count(p) == 0 ){
	PS[p] = nnode++;
	SP[nnode-1] = p;
	//	printf("%.30f %.30f\n", p.real(), p.imag());
    } 
    return PS[p];
    */
    /*
    map<Point, int>::iterator it;
    for ( it = PS.begin(); it != PS.end(); it++ ){
	Point s = (*it).first;
	if ( abs(s.real()-p.real()) < EPS && abs(s.imag()-p.imag()) < EPS ) {
	    return (*it).second;
	}
    }
    PS[p] = nnode++;
    SP[nnode-1] = p;
    return nnode-1;
    */
}

void makeGraph(Graph &g, Segment S[MAX], int N, Point s ){
    Segment base, target;
    vector<Point> v;

    Point l[NMAX];
    vector<Node> all;
    int iT[NMAX];
    int np = 0;
    
    PS = map<Point, int>();
    PV.clear();
    nnode = 0;
    bool startSet = false;
    for ( int b = 0; b < N; b++ ){
	base = S[b];
	//v.clear();
	np = 0;
	if ( !startSet && isOnSegment(base.source, base.target, s) ){
	    //g.start = getIndex(s);
	    //v.push_back(s);
	    l[np++] = s;
	    startSet = true;
	}
	//v.push_back(base.source);
	//v.push_back(base.target);
	l[np++] = base.source;
	l[np++] = base.target;
	for ( int t = 0; t < N; t++ ){
	    if ( t == b ) continue;
	    target = S[t];
	    if ( !isIntersect(base, target) ) continue;
	    Point cp = getCrossPoint(base, target);
	    //v.push_back(cp);
	    l[np++] = cp;
	}
	//sort(v.begin(), v.end());
	sort(l, l + np);
	//	for ( int i = 0; i < v.size()-1; i++ ){

	for ( int i = 0; i < np; i++ ) {
	    iT[i] = getIndex(l[i]);
	    all.push_back(Node(l[i], iT[i]));
	}

	for ( int i = 0; i < np-1; i++ ){
	    /*
	    int a = getIndex(v[i]);
	    int b = getIndex(v[i+1]);
	    if ( a==b ) continue;
	    g.connect(a, b, getDistance(v[i], v[i+1]));
	    */

	    int a = iT[i];
	    int b = iT[i+1];
	    assert( a != b );
	    if ( a==b ) continue;
	    g.connect(a, b, getDistance(l[i], l[i+1]));

	    //	    cout << "con " << a << "-" << b << "  " << v[i].real() << "," << v[i].imag() << "-" << v[i+1].real() << "," << v[i+1].imag() << endl;
	    //	    cout << g.nedge << endl;
	}
    }


    sort( all.begin(), all.end() );

    for ( int i = 0; i < all.size(); i++ ){
	//	cout << all[i].p.real() << " " << all[i].p.imag() <<  "  " << all[i].id << endl;
	if ( i == all.size()-1) continue;

	if (eq(all[i].p, all[i+1].p) ){
	    int a = all[i].id;
	    int b = all[i+1].id;
	    assert( a != b );
	    if ( a != b )  {

		g.connect(a, b, 0.0);
	    }
	}
	
	if ( eq(all[i].p, s) ){
	    g.start = all[i].id;
	}
    }

}

static const double LIMIT = 2000000.0;

void dijkstra(Graph g ){
    bool visited[NMAX];
    bool isLeaf[NMAX];
    double D[NMAX];

    for ( int i = 0; i < nnode; i++ ) {
	visited[i] = false;
	isLeaf[i] = true;
	//D[i] = FLT_MAX;
	D[i] = LIMIT;
    }

    //                cout << "nnode = " << nnode << endl;
    //                cout << "start = " << g.start << endl;
    priority_queue<QNode> PQ;
    for ( int i = 0; i < g.adjList[g.start].size(); i++ ){
	Edge v = g.adjList[g.start][i];
	PQ.push(QNode(v.target, v.dist) );
	D[v.target] = v.dist;
	isLeaf[g.start] = false;
    }

    //   PQ.push(QNode(g.start, 0.0));
    visited[g.start] = true;
    D[g.start] = 0.0;

    QNode u;
    int mq = 0;
    while( !PQ.empty() ){
	mq = max(mq, (int)(PQ.size()) );
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
    //    cout << "max queue = " << mq << endl;
    double mdist = 0.0;

    for ( int i = 0; i < nnode; i++ ){
	//if ( D[i] == LIMIT ) continue;
	mdist = max(mdist, D[i] );
    }

    for ( int i = 0; i < nnode; i++ ){
	for ( int k = 0; k < g.adjList[i].size(); k++ ){
	    int j = g.adjList[i][k].target;
	    //if ( !isLeaf[i] || !isLeaf[j] ) continue;
	    //  if ( D[i] == LIMIT || D[j] == LIMIT ) continue;
	    double a = getDistance(SP[i], SP[j]);
	    mdist = max(mdist, (double)(min(D[i], D[j]) + (a - abs(D[i]-D[j]))/2.0));
	}
    }
    printf("%.5lf\n", mdist);
    
}

int main(){
    int N;
    Segment I[MAX];
    Segment S[MAX];

    while( cin >> N && N ){
	//	cout << "N = " << N << endl;
	Point p1, p2;
	for ( int i = 0; i < N; i++ ){
	    cin >> p1.real(); cin >> p1.imag();
	    cin >> p2.real(); cin >> p2.imag();
	    I[i] = Segment(p1, p2);
	}
	cin >> p1.real(); cin >> p1.imag();
	Graph g;
	
	makeGraph(g, I, N, p1);
	dijkstra(g);
    }

    return 0;
}

