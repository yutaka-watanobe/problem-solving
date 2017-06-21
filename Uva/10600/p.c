// @JUDGE_ID:  17051CA  10600  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<stl.h> 
#include<vector>

typedef pair<int, int> edge;

class graph {
 public:
  vector<vector<int> > m;
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

  void insert( int i, int j, int e ){
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

class Blackout{
 public:
  graph g;
  vector<edge> mst;

  void read(){
    int n, m, source, target, w;
    cin >> n >> m;
    g.clear();
    g = graph( n );
    for ( int i = 0; i < m; i++ ){
      cin >> source >> target >> w;
      g.insert( source - 1, target - 1, w );
      g.insert( target - 1, source - 1, w );
    }
  }

  void work(){
    int d;
    int minCost, secondCost;
    int visited;

    edge null = pair<int, int>(-1, -1);
    prim(g, mst, minCost, null, visited);

    secondCost = INT_MAX;
    vector<edge> tmp;
    for ( int i = 0; i < mst.size(); i++ ){
      prim(g, tmp, d, mst[i], visited);
      if ( secondCost > d && visited == g.size()) secondCost = d;
    }


    cout << minCost << " " << secondCost << endl;
    




  }

  void prim(graph &g, vector<edge> &m, int &dist, edge extra, int &used){
    
    vector<int> pi(g.size(), -1);
    vector<int> d(g.size(), INT_MAX);
    vector<int> visited(g.size(), 0);
    
    used = 0;
    
    int u, v;
    int s = 0;
    
    d[s] = 0;

    g.reset();
    
    while ( 1 ){
      int min = INT_MAX;
      for ( int i = 0; i < g.size(); i++ ){
	if ( visited[i] == 0 && d[i] < min ) {
	  min = d[i];
	  u = i;
	}
      }
      
      if( min == INT_MAX ) break;
      visited[u] = 1;
      used++;
      
      while ( ( v = g.next(u) ) != -1 ){
	if ( extra.first == u && extra.second == v ||
	     extra.first == v && extra.second == u ) continue;
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
};

main(){
  Blackout B;
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    B.read();
    B.work();
  }
}  
// @end_of_source_code


