// @JUDGE_ID:  17051CA  10075  C++
// @begin_of_source_code
/* Graph - APSP */
/* Geometory Shpere cordinate */
#include<stdio.h>
#include<string>
#include<iostream>
#include<stl.h> 
#include<cmath>
#include<vector>
#include<slist>

class Point{
 public:
  double x, y;
  Point(){}
  Point( double x, double y ): x(x), y(y){}
};

class graph {
 public:
  vector<vector<int> > m;
  vector<slist<int> > adj;
  vector<slist<int>::iterator> pos;
  
  graph(){}
  graph(int n){ resize(n); }
  void resize(int n){
    m.resize(n), adj.resize(n), pos.resize(n); 
    for(int i=0; i<n; i++){
      m[i].resize(n);
      fill(m[i].begin(), m[i].end(), 0);
      adj[i].clear();
    }
  }

  int size(){ return m.size(); }

  void insert(int i, int j, int e){
    m[i][j] = e;
    adj[i].push_front(j);
  }
  
  int next(int i){ 
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++; 
  }
  
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  void clear(){ m.clear(), adj.clear(), pos.clear(); }

  graph & operator=(const graph &g){
    m = g.m;
    adj = g.adj;
    pos.resize(m.size());
    for(int i=0; i<m.size(); i++)
      pos[i] = adj[i].begin();
  }
};

/*
 * All-Pairs Shortest Path
 *
 *    d[i][j]:  shortest path from i to j
 *    pi[i][j]: the previout node of j, of d[i][j]
 */
void floyd(graph &g,  vector<vector<int> > &d){
  vector<vector<int> >  pi;
  int n = g.size(), inf = INT_MIN;

  d = g.m;
  pi.assign(g.size(), vector<int>(g.size(), -1));

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      pi[i][j] = i;
      if(i!=j && d[i][j]==0) d[i][j] = inf;
    }
  }
  for(int k=0; k<n; k++){
    for(int i=0; i<n; i++){
      if(d[i][k]==inf) continue;
      for(int j=0; j<n; j++){
	if(d[k][j]==inf) continue;
	
	if(d[i][j]==inf || d[i][k]+d[k][j] < d[i][j]){
	  d[i][j] = d[i][k]+d[k][j];
	  pi[i][j] = pi[k][j];
	}
      }
    }
  }
}

graph g;
int N, M, Q;
map<string, int> name_index;
vector<Point> P;
double PI = 3.141592653589793;

int getDistance( Point p1, Point p2 ){
  double r = 6378.0;

  double x1 = r*cos( p1.x )*cos( p1.y );
  double y1 = r*cos( p1.x )*sin( p1.y );
  double z1 = r*sin( p1.x );

  double x2 = r*cos( p2.x )*cos( p2.y );
  double y2 = r*cos( p2.x )*sin( p2.y );
  double z2 = r*sin( p2.x );

  double c = sqrt( (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2 ) );
  double cosTheta = ( 2*r*r - c*c ) / (2*r*r);
  double t = acos( cosTheta );

  return  (int)( r * t + 0.5 );
}

int read(){
  cin >> N >> M >> Q;
  if ( N == 0 && M == 0 && Q == 0 ) return 0;
  P.clear();
  g = graph ( N );
  P.resize( N );
  string name;
  double lt, ln;
  
  for ( int i = 0; i < N; i++ ){
    cin >> name >> lt >> ln;
    name_index[ name ] = i;
    lt = lt*PI/180.0;
    ln = ln*PI/180.0;
    P[i] = Point( lt, ln );
  }

  string s1, s2;
  for ( int i = 0; i < M; i++ ){
    cin >> s1 >> s2;
    int s = name_index[s1];
    int t = name_index[s2];
    g.insert( s, t, getDistance( P[s], P[t] ) );
  }
  
  return 1;
}

void work(){
  string s1, s2;
  int source, target;
  vector<vector<int> > d;

  floyd( g, d );

  for ( int i = 0; i < Q; i++ ){
    cin >> s1 >> s2;
    source = name_index[s1];
    target = name_index[s2];
    if (d[source][target] == INT_MAX || d[source][target] < 0) cout << "no route exists" << endl;
    else cout << d[source][target] << " km" << endl;
  }

}

main(){
  for ( int i = 1; read(); i++ ){
    if ( i > 1 ) cout << endl;
    cout << "Case #" << i << endl;
    work();
  }
}

// @end_of_source_code
