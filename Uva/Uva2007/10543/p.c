// @JUDGE_ID:  17051CA  10543  C++
// @begin_of_source_code
/* BFS */
/* use pair of position and cost */ 
#include<stdio.h>
#include<stl.h> 
#include<vector>
#include<slist>
#include<queue>

class graph {
 public:
  vector<slist<int> > adj;
  vector<slist<int>::iterator> pos;
  
  graph(){}
  graph(int n){ resize(n); }

  void resize(int n){
    adj.resize(n), pos.resize(n); 
    for(int i=0; i<n; i++){
      adj[i].clear();
    }
  }

  int size(){ return adj.size(); }

  void insert(int i, int j){
    adj[i].push_front(j);
  }
  
  int next(int i){ 
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++; 
  }
  
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  void clear(){ adj.clear(), pos.clear(); }
};

int n, k;

int bfs(graph &g ){
  vector<vector<bool> > U;

  U.resize( n );

  for ( int i = 0; i < n; i++ ){
    U[i].resize( 21, false );
  }

  queue<pair<int, int> > q;

  pair<int, int> p;
  int u, v, d;

  int s = 0;
  int e = n - 1;

  q.push( make_pair( s, 1 ) );
  
  U[s][1] = true;

  while(!q.empty()){
    p = q.front(), q.pop();
    u = p.first;
    d = p.second;

    if ( u == e && d >= k && d <= 20 ) return d;
    
    g.reset(u);
      
    while((v=g.next(u))!=-1){
      if ( !U[v][ d + 1 ] && v != u){
	U[v][d+1] = true;
	if ( d+1 <= 20 ) q.push( make_pair( v, d+1 ) );
      }
    }
  }

  return -1;
}

graph g;

int read(){
  int m;
  cin >> n >> m >> k; 
  if ( n == 0 && m == 0 && k == 0 ) return 0;

  g = graph ( n );

  int u, v;
  for ( int i = 0; i < m; i++ ){
    cin >> u >> v;
    g.insert( u, v );
  }

  return 1;
}

void work(){
  int cost = bfs( g);

  if ( cost == -1 ) cout << "LOSER" << endl;
  else {
    cout << cost << endl;
  }

}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
