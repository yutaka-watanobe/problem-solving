// @JUDGE_ID:  17051CA  10685  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<map>

#define MAX 5001

class graph{
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

class Nature{
 public:
  int ncreature, nrelation;
  map<string, int> S_I;
  graph g;
  bool visited[MAX];
  int counter;
  int maxValue;

  void dfs( int u ){
    counter++;
    visited[u] = true;
    
    int v;
    while ( ( v = g.next(u) ) != -1 ){
      if ( !visited[v] ){
	dfs( v );
      }
    }
  }

  void work(){
    for ( int i = 0; i < ncreature; i++ ) visited[i] = false;
    maxValue = 0;

    g.reset();

    for ( int i = 0; i < ncreature; i++ ){
      if ( !visited[i] ){
	counter = 0;
	dfs( i );
	if ( maxValue < counter ) maxValue = counter;
      }
    }
    printf("%d\n", maxValue );
  }

  bool read(){
    string name, source, target;
    cin >> ncreature >> nrelation;
    if ( ncreature == 0 && nrelation == 0 ) return false;
 
    g = graph( ncreature );

    for ( int i = 0; i < ncreature; i++ ){
      cin >> name;
      S_I[name] = i;
    }

    for ( int i = 0; i < nrelation; i++ ){
      cin >> source >> target;
      int s = S_I[source];
      int t = S_I[target];
      g.insert( s, t ); g.insert( t, s );
    }
    return true;
  }
};

int main(){
  Nature N;
  while ( N.read() ){
    N.work();
  }
  return 0;
}
// @end_of_source_code
