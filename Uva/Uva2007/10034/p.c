// @JUDGE_ID:  17051CA  10034  C++
// @begin_of_source_code
/* MST !! */

#include<stdio.h>
#include<iostream>
#include<string>
#include<slist>
#include<vector>
#include<stl.h>
typedef pair<int, int> edge;

class graph {
 public:
  vector<vector<double> > m;
  vector<vector<int> > adj;
  vector<vector<int>::iterator> pos;
  
  graph(){}
  graph(int n){ resize(n); }

  void resize(int n){
    m.resize(n), adj.resize(n), pos.resize(n); 
    for ( int i = 0; i < n; i++ ){
      m[i].resize(n);
      fill( m[i].begin(), m[i].end(), 0 );
      adj[i].clear();
    }
  }
  
  int size(){ return m.size(); }

  void insert( int i, int j, double e ){
    m[i][j] = e;
    adj[i].push_back( j );
  }
  
  int next( int i ){ 
    if ( pos[i] == adj[i].end() ) return -1;
    return *pos[i]++; 
  }
  
  void reset( int i ){ pos[i] = adj[i].begin(); }
  void reset(){ for ( int i = 0; i < size(); i++ ) reset(i); }

  void clear(){ m.clear(), adj.clear(), pos.clear(); }
};

graph g;
int n; 
vector<pair<double, double> > node;
void prim(graph &g, vector<edge> &m, double &dist);

double getDist(int i, int j){
  double x1, y1, x2, y2;
  x1 = node[i].first;
  y1 = node[i].second;
  x2 = node[j].first;
  y2 = node[j].second;
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void work(){
  cin >> n;
  g = graph(n);

  node.clear();

  for(int i=0; i<n; i++){
    double a, b;
    cin >> a >> b;
    node.push_back(pair<double, double>(a, b));
  }

  pair<double, double> p1, p2;
  double d, x1, y1, x2, y2;
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      d = getDist(i, j);
      g.insert(i, j, d);
      g.insert(j, i, d);
    }
  }
  double dist;
  vector<edge> m;
  prim(g, m, dist);
  printf("%.2lf\n", dist);
}

main(){
  int testCase;
  cin >> testCase;
  for(int i=0; i<testCase; i++){
    if(i) cout << endl;
    work();
  }
}

/**
 * MST Prim's algorithm
 * m: mst
 */
void prim(graph &g, vector<edge> &m, double &dist){

  vector<int> pi(g.size(), -1);
  vector<double> d(g.size(), INT_MAX);
  vector<int> visited(g.size(), 0);

  int u, v;
  int s = 0;

  d[s] = 0;
  
  g.reset();

  while(1){
    double min = INT_MAX;
    for (int i=0; i<g.size(); i++){
      if (visited[i]==0 && d[i]<min) {
	min = d[i];
	u = i;
      }
    }

    if( min == INT_MAX ) break;
    visited[u] = 1;

    while((v=g.next(u))!=-1){
      if (visited[v]==0 && g.m[u][v]<d[v]){
	d[v] = g.m[u][v];
	pi[v] = u;
      }
    }
  }

  m.clear();
  dist = 0;
  for(int i=0; i<pi.size(); i++){
    if(pi[i]!=-1){
      dist += getDist(i, pi[i]);
      m.push_back(edge(i, pi[i]));
    }
  }

}
// @end_of_source_code
