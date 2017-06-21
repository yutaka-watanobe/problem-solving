/**************************
 * Bellman Ford Algorithm *
 **************************/
#include "graph.h"

graph g;
int n;
bool bellman(graph &g, vector<int> &pi, vector<int> &d, int s);

/**
 * Bellman Ford Algorithm
 * If there are No negative cycle form source, return True !
 * Solved 558 ( only negative cycle ditection ! )
 * Need Test !!
 */ 
bool bellman(graph &g, vector<int> &pi, vector<int> &d, int s){
  d.resize(g.size(), INT_MAX);
  pi.resize(g.size(), -1);
  
  d[s] = 0;

  int v;

  for ( int i = 0; i < g.size() -1; i++ ){
    g.reset();
    for ( int u = 0; u < g.size(); u++ ){
      while ( (v = g.next(u) ) != -1 ){
	/* relax ( u, v, w ) */
	if ( d[v] > d[u] + g.m[u][v] ){
	  d[v] = d[u] + g.m[u][v];
	  pi[v] = u;
	}
      }
    }
  }

  g.reset();
  for ( int u = 0; u < g.size(); u++ ){
    while ( (v = g.next(u) ) != -1 ){
      if ( d[v] > d[u] + g.m[u][v] ){
	return false;
      }
    }
  }
  return true;
}

void read(){
  int i, j, e;
  cin >> n;
  g = graph(n);
  while(1){
    cin >> i >> j >> e;
    if( cin.eof() ) break;
    g.insert(i, j, e); 
  }
}

main(){
  read(); /* read graph */
  vector<int> pi, cost;
  g.reset();
  bool cycle;
  cycle = bellman(g, pi, cost, 0);
  cout << "pi:    "; for(int i=0; i<n; i++) printf("%3d", pi[i]);
  cout << endl;
  cout << "cost : "; for(int i=0; i<n; i++) printf("%5d", cost[i]);
  cout << endl;
  if ( !cycle ) cout << "has negative cycle" << endl;
  else  cout << "has No negative cycle" << endl;
}
