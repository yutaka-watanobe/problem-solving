// @JUDGE_ID:  17051CA  10449  C++
// @begin_of_source_code

/* From 2004/03/25 */
/* Shortest Path with negative edge */
/* use Floyd or Bellman */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<slist>

using namespace std;

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

/*
 * All-Pairs Shortest Path
 *
 *    d[i][j]:  shortest path from i to j
 *    pi[i][j]: the previout node of j, of d[i][j]
 */
void floyd(graph &g, vector<vector<int> > &pi, vector<vector<int> > &d){
  int n = g.size(), inf = INT_MIN;

  d = g.m;
  /* pi.assign(g.size(), vector<int>(g.size(), -1)); */

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      /* pi[i][j] = i; */
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
	  /* pi[i][j] = pi[k][j]; */
	}
      }
    }
  }
}

graph g;
vector<int> D;

int n;

int getCost( int i, int j ){
  int s = D[i];
  int d = D[j];
  return ( d - s )*( d - s )*( d - s );
}

int read(){
  if ( !( cin >> n ) ) return 0;

  D.clear();
  D.resize( n );
  g = graph( n );

  for ( int i = 0; i < n; i++ ){
    cin >> D[i];
  }

  int m, s, t;
  cin >> m;
  for ( int i = 0; i < m; i++ ){
    cin >> s >> t;
    s--; t--;
    if ( s < n && t < n ) g.insert( s, t, getCost( s, t ) );
  }

  return 1;
}

void work(){
  vector<vector<int> > pi, d;
  floyd( g, pi, d );

  int q, target;
  int cost;
  cin >> q;

  for ( int i = 0; i < q; i++ ){
    cin >> target; target--;
    if ( target >= n ) cost = INT_MIN;
    else cost = d[0][target];
    for ( int k = 0; k < n; k++ ){
      if ( d[k][k] < 0 && d[0][k] != INT_MIN && d[k][target] != INT_MIN ){
	cost = INT_MIN;
	break;
      }
    }

    if ( cost < 3 ) cout << "?" << endl;
    else cout << cost << endl;
  }
}

main(){
  for ( int i = 1; read(); i++ ){
    cout << "Set #" << i << endl;
    work();
  }
}



// @end_of_source_code
