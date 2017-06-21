include<stdio.h>
#include<stl.h> 
#include<vector>
#include<slist>

typedef pair<int, int> edge;

class graph {
 public:
  vector<vector<edge> > adj;
  vector<vector<edge>::iterator> pos;
  
  graph(){}
  graph( int n ){ resize(n); }

  void resize( int n ){
    adj.resize(n), pos.resize(n); 
    for ( int i = 0; i < n; i++ ){
      adj[i].clear();
    }
  }
  
  int size(){ return adj.size(); }

  void insert( int i, int j, int e ){
    adj[i].push_back( make_pair(j, e ) );
  }
  
  edge next( int i ){ 
    if( pos[i] == adj[i].end() ) return edge( -1, -1 );
    return *pos[i]++; 
  }
  
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for ( int i = 0; i < size(); i++ ) reset(i); }

  void clear(){ adj.clear(), pos.clear(); }
};

void dijkstra( graph &g, vector<int> &pi, vector<int> &cost, int s ){
  cost.resize( g.size(), INT_MAX );
  pi.resize( g.size(), -1 );
  vector<int> visited( g.size(), 0 );
  
  cost[s] = 0;
  g.reset();

  while ( 1 ){
    int min = INT_MAX;
    int x;
    for ( int i = 0; i < g.size(); i++ ){
      if ( visited[i] == 0 && min > cost[i] ){
	min = cost[i];
	x = i;
      }
    }

    if( min == INT_MAX ) break;

    visited[x] = 1;

    edge e;
    int v, d;
    while ( ( e = g.next(x) ) != edge(-1, -1) ){
      v = e.first;
      d = e.second;
      if( !visited[v] && cost[x] + d < cost[v] ){ 
	cost[v] = cost[x] + d;
	pi[v] = x;
      }
    }
  }

}

class MiceAndMaze{
 public:
  int N, E, T;
  graph g;

  void work(){
    vector<int> pi, d;
    dijkstra( g, pi, d, E );

    int sum = 0;
    for ( int i = 0; i < N; i++ ){
      if ( d[ i ] <= T ) sum++;
    }
    
    cout << sum << endl;
  }

  void read(){
    cin >> N;
    g.clear();
    g = graph( N );
    cin >> E >> T;
    E--;
    int m;
    cin >> m;
    int source, target, timeunit;
    for ( int i = 0; i < m; i++ ){
      cin >> source >> target >> timeunit;
      source--; target--;
      g.insert( target, source, timeunit );
    }
  }


};

main(){
  MiceAndMaze MAM;
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    if ( i ) cout << endl;
    MAM.read();
    MAM.work();
  }
}
