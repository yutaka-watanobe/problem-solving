#include<iostream>
#include<vector>
#include<cfloat>
#include<cassert>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++)
#define EPS 0.01
#define equals(a, b) (fabs((a) - (b)) <= EPS )
#define dle(a, b) (equals(a, b) || a < b )

#define MAX 100

class Point{
    public:
    double x, y;
    Point ( double x = 0, double y = 0): x(x), y(y){}
    Point operator + ( Point p ){ return Point(x + p.x, y + p.y); }
    Point operator - ( Point p ){ return Point(x - p.x, y - p.y); }
    Point operator * ( double a ){ return Point(x*a, y*a); }
    bool operator < ( const Point &p ) const {
	return x != p.x ? x < p.x : y < p.y;
    }
    bool operator == ( const Point &p ) const {
	return fabs(x-p.x) <= EPS && fabs(y-p.y) <= EPS;
    }
    double abs() { return sqrt(norm());}
    double norm() { return x*x + y*y; }
};
typedef Point Vector;
typedef vector<Point> Polygon;

double norm( Vector a ){ return a.x*a.x + a.y*a.y; }
double abs( Vector a ) { return sqrt(norm(a)); }
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

bool isInside(Polygon gon, Point p ){
    for ( int i = 0; i < gon.size(); i++ ){
	if ( ccw(gon[i], gon[(i+1)%gon.size()], p) == CLOCKWISE ) return false;
    }
    return true;
}

class Triangle{
    public:
    vector<Point> P;
    Triangle(){ P.resize(3);}
    void normalize(){
	vector<Point> tmp(3);
	if ( equals(norm(P[0]-P[1]), norm(P[0]-P[2])) ){
	    tmp[0] = P[1]; tmp[1] = P[2]; tmp[2] = P[0];
	} else if ( equals(norm(P[1]-P[0]), norm(P[1]-P[2])) ){
	    tmp[0] = P[0]; tmp[1] = P[2]; tmp[2] = P[1];
	} else if ( equals(norm(P[2]-P[0]), norm(P[2]-P[1])) ){
	    tmp[0] = P[0]; tmp[1] = P[1]; tmp[2] = P[2];
	}
	P = tmp;
	if ( ccw(P[0], P[1], P[2]) != COUNTER_CLOCKWISE ) swap(P[0], P[1]);
    }

    double getArea(){
	double a = abs(P[0]-P[1]); 
	double b = abs(P[0]-P[2]); 
	double c = abs(P[2]-P[1]); 
	double s= (a + b + c)/2.0;
	return sqrt(s*(s-a)*(s-b)*(s-c));
    }
};

class Graph{
public:
    int n;
    vector<vector<int> > adj;
    Graph(int n = 0):n(n){
	adj.resize(n);
	rep(i, n) adj[i].clear();
    }
    void connect(int i, int j){ adj[i].push_back(j); }
    void transpose(){
	vector<vector<int> > nadj;
	nadj.resize(n);
	rep(i, n) nadj[i].clear();
	rep(i, n) rep(j, adj[i].size())	nadj[adj[i][j]].push_back(i);
	rep(i, n) adj[i] = nadj[i];
    }
};

int n;
double d;
Triangle T[MAX];

Graph g;
int visited[MAX], finish[MAX], t;
vector<int> com;

bool overlapPolygon(Polygon p1, Polygon p2){
    rep(i, p1.size()) if ( isInside(p2, p1[i]) ) return true;
    rep(i, p2.size()) if ( isInside(p1, p2[i]) ) return true;
    rep(i, p1.size()) rep(j, p2.size()){
      if ( isIntersect(p1[i], p1[(i+1)%p1.size()], p2[j], p2[(j+1)%p2.size()])) return true;
    }
    return false;
}

bool overlap( int t1, int t2){
    Triangle s = T[t1];
    vector<Point> rect, tri;
    Point c = Point((s.P[0].x+s.P[1].x)/2, (s.P[0].y+s.P[1].y)/2);
    Vector v = s.P[2] - c;
    double a = v.abs();
    v.x = d*v.x/a;
    v.y = d*v.y/a;
    Point l = s.P[0] + v;
    Point r = s.P[1] + v;
    rect.push_back(s.P[1]);
    rect.push_back(r);
    rect.push_back(l);
    rect.push_back(s.P[0]);
    tri = T[t2].P;
    return overlapPolygon(rect, tri);
}

void dfs(int &u){
    visited[u] = t++;
    rep(i, g.adj[u].size()){
	int v = g.adj[u][i];
	if ( visited[v] == -1 ) dfs(v);
    }
    finish[u] = t++;
}

void dfsT(int &u){
    com.push_back(u);
    visited[u] = 1;
    rep(i, g.adj[u].size()){
	int v = g.adj[u][i];
	if ( visited[v] == 0 ) dfsT(v);
    }
}

void makeGraph(){
    g = Graph(n);
    rep(i, n) rep(j, n)
	if ( i != j && overlap(i, j) )
	    g.connect(i, j);
}

int scc(){
    int id[MAX];
    bool indeg[MAX];

    rep(i, n) visited[i] = finish[i] = -1;
    t = 0;
    rep(i, n) if ( visited[i] == -1 ) dfs(i);

    g.transpose();
    
    vector<pair<int, int> > order;
    rep(i, n) order.push_back(make_pair(finish[i], i));
    sort(order.begin(), order.end());
    
    rep(i, n) visited[i] = 0;
    
    int ncom = 0;
    
    for ( int i = n-1; i >= 0; i-- ){
	int u = order[i].second;
	com.clear();
	if ( visited[u] == 0 ) {
	    dfsT(u);
	    rep(c, com.size()) id[com[c]] = ncom;
	    ncom++;
	}
    }
    
    int cnt = 0;
    g.transpose();

    rep(i, ncom) indeg[i] = false;
    
    rep(u, n) rep(i, g.adj[u].size()){
	int v = g.adj[u][i];
	if ( id[v] != id[u] ) indeg[id[v]] = true;
    }
    rep(i, ncom) if (!indeg[i]) cnt++;
    
    return cnt;
}

main(){
    while( cin >> n >> d && n ){
	rep(i, n){
	    Triangle t;
	    rep(j, 3) cin >> t.P[j].x >> t.P[j].y;
	    t.normalize();
	    T[i] = t;
	}
	double a = T[0].getArea();

	for ( int i = 0; i < n-1; i++ ){
	    for ( int j = i+1; j < n; j++ ){
		rep(a, 3) rep(b, 3){
		    Point p1 = T[i].P[a];
		    Point p2 = T[i].P[(a+1)%3];
		    Point p3 = T[j].P[b];
		    Point p4 = T[j].P[(b+1)%3];
		}
	    }
	}

	makeGraph();
	cout << scc() << endl;
    }
}

