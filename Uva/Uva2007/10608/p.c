// @JUDGE_ID:  17051CA  10608  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<stl.h> 
#include<vector>

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

class Friends{
 public:
  graph g;
  bool used[30001];
  int n;
  int counter;

  void read(){
    int m, source, target;
    cin >> n >> m;
    g.clear();
    g = graph(n);
    for ( int i = 0; i < m; i++ ){
      cin >> source >> target;
      source--; target--;
      g.insert( source, target );
      g.insert( target, source );
    }
  }

  void dfs(int u){
    used[u] = true;
    counter++;

    int v;

    while ( (v = g.next(u) ) != -1 ){
      if ( !used[v] ) dfs(v);
    }
  }

  void work(){
    g.reset();
    for ( int i = 0; i < n; i++ ) used[i] = false;

    int maxValue = 0;
    
    for ( int i = 0; i < n; i++ ){
      if ( !used[i] ){
	counter = 0;
	dfs(i);
	if ( counter > maxValue ) maxValue = counter;
      }
    }

    cout << maxValue << endl;
  }
};


main(){
  Friends F;
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    F.read();
    F.work();
  }
}



// @end_of_source_code


