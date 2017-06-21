// @JUDGE_ID:  17051CA  10672  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#include<cmath>
#define MAX 10001

class graph {
 public:
  vector<vector<int> > adj;
  vector<vector<int>::iterator> pos;
  
  graph(){}
  graph( int n ){ resize(n); }

  void resize( int n ){
    adj.resize(n), pos.resize(n); 
    for( int i = 0; i < n; i++ ){
      adj[i].clear();
    }
  }
  
  int size(){ return adj.size(); }

  void insert( int i, int j ){
    adj[i].push_back(j);
  }
  
  int next( int i ){ 
    if( pos[i] == adj[i].end() ) return -1;
    return *pos[i]++; 
  }
  
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for( int i = 0; i < size(); i++) reset(i); }
};

class Marbles{
 public:
  int n;
  int C[MAX];
  bool U[MAX];
  int IN[MAX];
  int cnt;
  graph g;
  int root;

  void dfs(int u, int from){
    U[u] = true;
    int v;

    while ( (v = g.next(u) ) != -1 ){
      if ( !U[v] ){
	//	U[v] = true;
	dfs( v, u );
      }
    }

    if ( from == -1 ) return;

    int sub = C[u] - 1;
    C[u] -= sub;
    C[from] += sub;
    cnt += abs(sub);

  }

  void work(){
    cnt = 0;
    for ( int i = 0; i < n; i++ ) U[i] = false;
    g.reset();
    dfs(root, -1);
    printf("%d\n", cnt);
  }

  bool read(){
    scanf("%d", &n);
    if ( n == 0 ) return false;

    g = graph(n);
    for ( int i = 0; i < n; i++ ) IN[i] = 0;

    int v, c, d, t;
    for ( int i = 0; i < n; i++ ){
      scanf("%d %d %d", &v, &c, &d);
      for (int j = 0; j < d; j++ ){
	scanf("%d", &t );
	g.insert( v-1, t-1 );
	IN[t-1]++;
      }
      C[v-1] = c;
    }

    for ( int i = 0; i < n; i++ ) {
      if ( IN[i] == 0 ) root = i;
    }
    return true;
  }
};

main(){
  Marbles M;
  while ( M.read() ) M.work();
}


// @end_of_source_code
