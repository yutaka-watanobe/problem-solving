/*******************************************
 * Graph structure for Multi-Connected edge *
 ********************************************/

#include<stdio.h>
#include<stl.h> 
#include<vector>
#include<slist>

typedef pair<int, int> edge;

/**
 * class: graph
 * usage: #include <slist>
 */
class graph {
 public:
  vector<vector<edge> > adj;
  vector<vector<edge>::iterator> pos;
  
  /**
   * Constructor
   * @param the number of nodes
   */
  graph(){}
  graph( int n ){ resize(n); }

  /** 
   * @param the number of node
   */ 
  void resize( int n ){
    adj.resize(n), pos.resize(n); 
    for ( int i = 0; i < n; i++ ){
      adj[i].clear();
    }
  }
  
  /**
   * @return the number of node
   */
  int size(){ return adj.size(); }

  /**
   * insert e between i and j;
   * @param i, j, e(weight)
   * if it is non-weighted graph, e should be 1.
   * if it is undirected graph, Do insert(i, j, e) and insert(j, i, e).
   */
  void insert( int i, int j, int e ){
    adj[i].push_back( make_pair(j, e ) );
  }
  
  /**
   * refere to adjacency list of node i, and move one.
   */
  edge next( int i ){ 
    if( pos[i] == adj[i].end() ) return edge( -1, -1 );
    return *pos[i]++; 
  }
  
  /**
   * begin again of adjacency list reference of node i.
   */
  void reset(int i){ pos[i] = adj[i].begin(); }

  /**
   * begin again of adjacency list reference of all node.
   * Before use graph, it must be called !!!.
   */
  void reset(){ for ( int i = 0; i < size(); i++ ) reset(i); }

  /** clear all nodes */
  void clear(){ adj.clear(), pos.clear(); }
};

/**
 * MST Prim's algorithm
 * m: mst
 * Solved Problem: 10034, 10147, 10397, 534
 */
void prim(graph &g, int &dist){

  vector<edge> pi(g.size(), edge(-1, -1) );
  vector<int> d(g.size(), INT_MAX);
  vector<int> visited(g.size(), 0);
  
  int u;
  edge v;

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

    while ( ( v = g.next(u) ) != edge(-1,-1) ){
      if ( visited[v.first] == 0 && v.second < d[v.first] ){
	d[v.first] = v.second;
	pi[v.first] = edge( u, v.second );
      }
    }
  }

  dist = 0;
  for ( int i = 0; i < pi.size(); i++ ){
    if ( pi[i].first != -1 ){
      dist += pi[i].second;
    }
  }

}

graph g;
int n;

void work(){
  int dist;

  prim( g, dist );
  
  cout << dist << endl;
}

bool read(){
  int m;
  cin >> n;
  if ( n == 0 ) return false;
  cin >> m;
  g.clear();
  g = graph( n );

  int source, target, cost;
  for ( int i = 0; i < m; i++ ){
    cin >> source >> target >> cost;
    source--; target--;
    g.insert( source, target, cost );
    g.insert( target, source, cost );
  }

  return true;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code


