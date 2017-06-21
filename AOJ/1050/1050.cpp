#include<iostream>
#include<cfloat>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

#define EPS (1e-10)
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
    Point operator / ( double a ){ return Point(x/a, y/a); }

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
    Segment(Point s = Point(), Point t = Point()): p1(s), p2(t){}
};

typedef Segment Line;

typedef vector<Point> Polygon;

double norm( Vector a ){ return a.x*a.x + a.y*a.y; }
double abs( Vector a ){ return sqrt(norm(a)); }
Point polar( double a, double r ){ return Point(cos(r)*a, sin(r)*a);}
double getDistance( Vector a, Vector b ){ return abs(a - b); }
double dot( Vector a, Vector b ){ return a.x*b.x + a.y*b.y; }
double cross( Vector a, Vector b ){ return a.x*b.y - a.y*b.x; }

double arg(Vector p){
    return atan2(p.y, p.x);
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

Point getCrossPointLines( Line s1, Line s2){
    Vector a = s1.p2 - s1.p1;
    Vector base = s2.p2 - s2.p1;
    return s1.p1 + a * cross(base, s2.p1 - s1.p1)/cross(base, a);
}

Polygon cutPolygon( Polygon P, Line l ){
    Polygon u;
    for ( int i = 0; i < P.size(); i++ ){
	Point a = P[i], b = P[(i+1)%P.size()];
	if ( ccw(l.p1, l.p2, a) != CLOCKWISE ) u.push_back(a);
	if ( ccw(l.p1, l.p2, a) * ccw(l.p1, l.p2, b) == -1 ){
	    u.push_back(getCrossPointLines(Segment(a, b), l));
	}
    }
    return u;
}

class Edge{
    public:
    int target;
    double cost;
    Edge( int t=0, double c=0):target(t), cost(c){}
};

class Node{
    public:
    Point pos;
    vector<Edge> adjList;
    Node(){}
    Node(Point p):pos(p){}
};

class State{
    public:
    int pos;
    double cost;
    State(int p=0, double c=0): pos(p), cost(c){}
    bool operator < ( const State &s ) const{
	return cost > s.cost;
    }
};

#define X_MAX 4.0
#define Y_MAX 4.0
#define X_MIN 0.0
#define Y_MIN 0.0
#define MMAX 100

Point M[MMAX];
int nmon;
const double INFTY = 10000.0;

vector<Node> G; // graph;

Line getCutLine( Point p1, Point p2 ){
    Vector v = p2 - p1;
    v = polar(abs(v), arg(v)+PI/2.0);
    double dx = (p2.x + p1.x)/2.0;
    double dy = (p2.y + p1.y)/2.0;
    return Line(Point(dx, dy), Point(v.x+dx, v.y+dy));
}

void print(Polygon P){
    cout << "print polygon" << endl;
    for ( int i = 0; i < P.size(); i++ ){
	cout << P[i].x << "," << P[i].y << endl;
    }
}

bool isRoad( Segment s ){
    if ( equals(s.p1.x, s.p2.x) ){
	if ( equals(s.p1.x, X_MIN) || equals(s.p1.x, X_MAX) ) return false;
    }
    if ( equals(s.p1.y, s.p2.y) ){
	if ( equals(s.p1.y, Y_MIN) || equals(s.p1.y, Y_MAX) ) return false;
    }
    return true;
}

vector<Polygon> getVoronoi( Point PV[MMAX], int n){
    vector<Polygon> V;
    for ( int i = 0; i < n; i++ ){
	Polygon P;
	P.push_back(Point(X_MIN, Y_MIN));
	P.push_back(Point(X_MAX, Y_MIN));
	P.push_back(Point(X_MAX, Y_MAX));
	P.push_back(Point(X_MIN, Y_MAX));
	for ( int j = 0; j < n; j++ ){
	    if ( i == j ) continue;
	    P = cutPolygon(P, getCutLine(PV[i], PV[j]));
	}
	V.push_back(P);
    }
    return V;
}

double dijkstra(){
    priority_queue<State> PQ;
    vector<double> D;
    vector<int> P;
    D.resize(G.size());
    P.resize(G.size());
    for ( int i = 0; i < D.size(); i++ ) D[i] = INFTY;

    for ( int i = 0; i < G.size(); i++ ){
	if ( equals(G[i].pos.x, X_MIN) ){
	    PQ.push(State(i, 0.0));
	    D[i] = 0.0;
	    P[i] = -1;
	}
    }
    State u, v;
    while( !PQ.empty() ){
	u = PQ.top(); PQ.pop();
	if ( equals(G[u.pos].pos.x, X_MAX) ) {
	  int cur = u.pos;
	  while( cur != -1 ) cur = P[cur];
	  return D[u.pos];
	}

	for ( int i = 0; i < G[u.pos].adjList.size(); i++ ){
	    int t = G[u.pos].adjList[i].target;
	    double d = G[u.pos].adjList[i].cost;
	    if ( D[u.pos] + d < D[t] ){
		D[t] = D[u.pos] + d;
		P[t] = u.pos;
		PQ.push(State(t, D[t]));
	    }
	}
    }
    
    return INFTY;
}

void compute(){
    vector<Segment> S;

    vector<Polygon> V = getVoronoi(M, nmon);
    for ( int i = 0; i < V.size(); i++ ){
	Polygon P = V[i];
	for ( int j = 0; j < P.size(); j++ ){
	    Segment s = Segment(P[j], P[(j+1)%P.size()]);
	    if ( isRoad(s) ) S.push_back(s);
	}
    }
    G.clear();
    for( int i = 0; i < S.size(); i++ ){
	Segment s = S[i];
	double d = abs(s.p2 - s.p1);
	Node n1 = Node(s.p1);
	n1.adjList.push_back(Edge(G.size()+1,d));
	Node n2 = Node(s.p2);
	n2.adjList.push_back(Edge(G.size(),d));
	G.push_back(n1);
	G.push_back(n2);
    }
    for ( int i = 0; i < G.size()-1; i++ ){
	for ( int j = i+1; j < G.size(); j++ ){
	    if ( G[i].pos == G[j].pos ){
		G[i].adjList.push_back(Edge(j, 0.0));
		G[j].adjList.push_back(Edge(i, 0.0));
	    }
	}
    }
    double cost = dijkstra();
    if ( equals( cost, INFTY ) ) cout << "impossible" << endl;
    else printf("%.5lf\n", cost);

}

int main(){
    double x, y;
    while ( cin >> nmon ){
	if ( nmon == 0 ) break;
	for ( int i = 0; i < nmon; i++ ){
	    cin >> x >> y;
	    M[i] = Point(x, y);
	}
	compute();
    }
    return 0;
}
