// @JUDGE_ID:  17051CA  10459  C++
// @begin_of_source_code
/* Graph */
#include<stdio.h>
#include<iostream>
#include<vector>
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
  int size( int i  ) { return adj[i].size(); }

  void insert(int i, int j){
    adj[i].push_front(j);
  }

  int next(int i){ 
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++; 
  }
  
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  /* less used methods */
  void erase(int i, int j){
    for(slist<int>::iterator it=adj[i].begin(); it!=adj[i].end(); it++){
      if(*it==j){
	adj[i].erase(it);
	break;
      }
    }
  }

  void clear(){ adj.clear(), pos.clear(); }
};

int N;
graph g;
vector<int> B; /* best root list */
vector<int> W; /* worst root list */
vector<int> D; /* degree */
int len;

int read(){
  if ( !( cin >> N ) ) return 0;

  g = graph ( N );

  D.clear();
  D.resize( N );  
  int m, k;
  for ( int i = 0; i < N; i++ ){
    cin >> m;
    for ( int j = 0; j < m; j++ ){
      cin >> k; k--;
      g.insert( i, k );
      D[ i ]++; 
    }
  }

  return 1;
}

void makeBestRoot(){
  B.clear();
  vector<short> U;
  vector<short> V;
  U.resize( N, 0 );
  V.resize( N, -1 );
  int v;
  int cnt = N;
  int k;

  for ( k = 0; ; k++ ){
    if ( cnt <= 2){
      for ( int i = 0; i < N; i++ ){
	if ( U[ i ] == 0 ) B.push_back( i );
      }
      break;
    } else {
      for ( int i = 0; i < N; i++ ){
	if ( D[i] == 1 && !U[ i ] && V[ i ] != k){ 
	  U[ i ] = 1;
	  V[ i ] = k;
	  g.reset( i );
	  while ( (v = g.next(i) ) != -1 ){
	    D[ v ]--;
	    V[ v ] = k;
	  }
	  cnt--;
	}
      }
    }
  }
  
  /* assert( B.size() <= 2 ); */
  sort( B.begin(), B.end() );
  cout << "Best Roots  :";
  for ( int i = 0; i < B.size(); i++ ){
    cout << " " << B[i] + 1;
  }
  cout << endl;
}


void bfs( int s ){
  queue<int> q;
  int u, v;
  vector<int> d;
  d.resize(g.size(), 0);
  
  int max_d = 0;

  q.push(s);
  d[s] = 1;
  g.reset();
  
  while( !q.empty() ){
    u = q.front(), q.pop();
    
    while((v=g.next(u))!=-1){
      if(!d[v]){
	d[v] = d[u]+1;
	q.push(v);
      }
    }

    if ( q.empty() ){
      max_d = d[u];
      break;
    }
  }

  for ( int i = 0; i < N; i++ ){
    if ( d[i] == max_d ) W.push_back( i );
  }
}

void makeWorstRoot(){
  W.clear();
  for ( int i = 0; i < B.size(); i++ ){
    bfs ( B[i] );
  }
  
  sort( W.begin(), W.end() );
  cout << "Worst Roots :";
  for ( int i = 0; i < W.size(); i++ ){
    cout << " " << W[i] + 1;
  }
  cout << endl;
}

void work(){
  makeBestRoot();
  makeWorstRoot();
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
