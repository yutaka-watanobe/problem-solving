/************
 * MST Prim *
 ************/

#include<stdio.h>
#include<stl.h> 
#include<vector>
#include<slist>
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
    m[i][j]  = e;
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

/**
 * MST Prim's algorithm
 * m: mst
 * Solved Problem: 10034, 10147, 10397, 534
 */
void prim(graph &g, vector<edge> &m, double &dist){

  vector<int> pi(g.size(), -1);
  vector<double> d(g.size(), INT_MAX);
  vector<int> visited(g.size(), 0);

  int u, v;
  int s = 0;

  d[s] = 0;
  
  g.reset();

  while ( 1 ){
    double min = INT_MAX;
    for ( int i = 0; i < g.size(); i++ ){
      if ( visited[i] == 0 && d[i] < min ) {
	min = d[i];
	u = i;
      }
    }

    if( min == INT_MAX ) break;
    visited[u] = 1;

    while ( ( v = g.next(u) ) != -1 ){
      if ( visited[v] == 0 && g.m[u][v] < d[v] ){
	d[v] = g.m[u][v];
	pi[v] = u;
      }
    }
  }

  m.clear();
  dist = 0;
  for ( int i = 0; i < pi.size(); i++ ){
    if ( pi[i] != -1 ){
      dist += g.m[pi[i]][i];
      m.push_back( edge(i, pi[i]) );
    }
  }

}

main(){
 graph g;
  vector<edge> m;

  while(1){
    int n, l;
    cin >> n >> l;
    if(cin.eof()) break;

    g.resize(n);
    for(int i=0; i<l; i++){
      int u, v, e;

      cin >> u >> v >> e;
      g.insert(u, v, e);
    }
    
    prim(g, m);
    cout << "prim: ";
    for(int i=0; i<m.size(); i++){
      cout << m[i].first << "->" << m[i].second << " ";
    }
    cout << endl;
  }
}  
