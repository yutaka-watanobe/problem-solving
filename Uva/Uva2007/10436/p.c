// @JUDGE_ID:  17051CA  10436  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h> 
#include<vector>
#include<slist>
#include<cmath>
#define MAX 25

class graph {
 public:
  vector<vector<int> > m;
  vector<vector<int> > adj;
  vector<vector<int>::iterator> pos;
  
  graph(){}
  graph( int n ){ resize(n); }

  void resize( int n ){
    m.resize(n), adj.resize(n), pos.resize(n); 
    for ( int i = 0; i < n; i++ ){
      m[i].resize(n);
      fill( m[i].begin(), m[i].end(), 0 );
      adj[i].clear();
    }
  }

  int size(){ return m.size(); }

  void insert( int i, int j, int e ){
    m[i][j] = e;
    adj[i].push_back(j);
  }

  int next( int i ){ 
    if( pos[i]==adj[i].end() ) return -1;
    return *pos[i]++; 
  }
  
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  void clear(){ m.clear(), adj.clear(), pos.clear(); }
};

class CheapestWay{
 public:
  int n;
  graph g;
  int station[ MAX ];
  map<string, int> S_I;
  map<int, string> I_S;

  void dijkstra( graph &g, vector<int> &pi, vector<int> &cost, int s ){
    cost.resize( g.size(), INT_MAX );
    pi.resize( g.size(), -1 );
    vector<int> visited( g.size(), 0 );
    
    cost[s] = station[s];
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
      
      int v;
      while ( ( v = g.next(x) ) != -1 ){
	if( !visited[v] && cost[x] + g.m[x][v] + station[v] < cost[v] ){ 
	  cost[v] = cost[x] + g.m[x][v] + station[v];
	  pi[v] = x;
	}
      }
      
    }
  }

  void compute( int source, int target, int npassenger ){
    vector<int> pi, d;
    dijkstra(g, pi, d, source );

    double cost = d[ target ] * 1.0;

    vector<string> path;
    int pos = target;
    while(1){
      if ( pos == -1 ) break;
      path.push_back( I_S[ pos ] );
      pos = pi[ pos ];
    }

    for ( int i = path.size() -1 ; i >= 0; i-- ){
      cout << path[i];
      if ( i != 0 ) printf(" ");
    }
    if ( path.size() ==1 ) cout << " " << path[0] ;
    printf("\n");
    cost += (cost/10.0);
    printf("Each passenger has to pay : %.2lf taka\n", cost/npassenger);
  }

  void work(){
    int nquery;
    string source, target;
    int npassenger;

    cin >> nquery;

    for ( int q = 1; q <= nquery; q++ ){
      printf("Query #%d\n", q );
      cin >> source >> target >> npassenger;
      compute( S_I[source], S_I[target], npassenger );
    }
  }

  void read(){
    int m;
    string source, target;
    cin >> n;
    g = graph ( n );
    S_I = map<string, int>();
    I_S = map<int, string>();

    string name;
    int cost;

    for ( int i = 0; i < n; i++ ){
      cin >> name >> cost;
      S_I[ name ] = i;
      I_S[ i ] = name;
      station[i] = cost;
    }
    
    cin >> m;
    for ( int i = 0 ;i < m; i++ ){
      cin >> source >> target >> cost;
      g.insert( S_I[source], S_I[target], cost * 2 );
      g.insert( S_I[target], S_I[source], cost * 2 );
    }
  }
};

main(){
  CheapestWay CW;
  int tcase;
  cin >> tcase;
  for ( int i = 1; i <= tcase; i++ ){
    printf("Map #%d\n", i );
    CW.read();
    CW.work();
    if ( i != tcase )printf("\n");
  }
  
}

// @end_of_source_code


