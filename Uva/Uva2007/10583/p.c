// @JUDGE_ID:  17051CA  10583  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<stl.h> 
#include<vector>
#define MAX 50001

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

  void clear(){ adj.clear(), pos.clear(); }
};

class UbiquitousR{
 public:
  graph g;
  int n;
  bool used[ MAX ];

  void dfs( int u ){
    used[u] = true;
    int v;
    while ( (v = g.next(u) ) != -1 ){
      if ( !used[v] ) dfs( v );
    }
  }

  void work(){
    int cnt = 0;
    g.reset();
    for ( int i = 0; i < n; i++ ) used[i] = false;
    for ( int i = 0; i < n; i++ ){
      if ( !used[i] ){
	cnt++;
	dfs(i);
      }
    }
    printf("%d\n", cnt);
  }

  bool read(){
    int m, s, t;
    scanf("%d %d", &n, &m );
    if ( n == 0 && m == 0 ) return false;
    g = graph( n );
    for ( int i = 0; i < m; i++ ){
      scanf("%d %d", &s, &t );
      s--; t--;
      g.insert( s, t ); g.insert( t, s );
    }
    return true;
  }
};

main(){
  UbiquitousR UR;
  for ( int i = 1; UR.read(); i++ ){
    printf("Case %d: ", i );
    UR.work();
  }
}



// @end_of_source_code


