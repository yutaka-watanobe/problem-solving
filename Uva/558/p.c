// @JUDGE_ID:  17051CA  558  C++
// @begin_of_source_code
/* Graph */
/* Negative Cycle Ditection */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<vector>
#include<slist>

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
  
  vector<int> & operator[](int i){ return m[i]; }

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

/**
 * Bellman Ford Algorithm
 */ 
bool bellman(graph &g, vector<int> &pi, vector<int> &d, int s){
  d.resize(g.size(), INT_MAX);
  pi.resize(g.size(), -1);
  
  d[s] = 0;

  int v;

  for ( int i = 0; i < g.size() -1; i++ ){
    g.reset();
    bool revalidated = false;
    for ( int u = 0; u < g.size(); u++ ){
      while ( (v = g.next(u) ) != -1 ){
	/* relax ( u, v, w ) */
	if ( d[v] > d[u] + g.m[u][v] ){
	  d[v] = d[u] + g.m[u][v];
	  pi[v] = u;
	  revalidated = true;
	}
      }
    }
    if ( !revalidated ) break;
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

graph g;
int n;

void read(){
  int s, t, w, m;
  cin >> n >> m;

  g = graph( n );

  for ( int i = 0; i < m; i++ ){
    cin >> s >> t >> w;
    g.insert( s, t, w );
  }
}

void work(){
  vector<int> pi, d;
  bool no_negative = bellman(g, pi, d, 0 );

  if ( !no_negative ) cout << "possible" << endl;
  else cout << "not possible" << endl;
}

main(){
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    read();
    work();
  }
}
// @end_of_source_code
