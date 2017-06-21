// @JUDGE_ID:  17051CA  10462  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<stl.h> 
#include<vector>

class edge{
 public:
  int id;
  int target, weight;
  edge(){}
  edge(int id, int target, int weight):
    id(id), target(target), weight(weight){}
};

class graph {
 public:
  vector<vector<edge> > adj;
  vector<vector<edge>::iterator> pos;
  
  graph(){}
  graph(int n){ resize(n); }

  void resize(int n){
    adj.resize(n), pos.resize(n); 
    for ( int i = 0; i < n; i++ ){
      adj[i].clear();
    }
  }
  
  int size(){ return adj.size(); }

  void insert( int id, int i, int j, int e ){
    adj[i].push_back( edge(id, j, e) );
  }
  
  edge next( int i ){ 
    if ( pos[i] == adj[i].end() ) return edge(-1, -1, -1);
    return *pos[i]++; 
  }
  
  void reset( int i ){ pos[i] = adj[i].begin(); }
  void reset(){ for ( int i = 0; i < size(); i++ ) reset(i); }

  void clear(){ adj.clear(), pos.clear(); }
};

class Blackout{
 public:
  graph g;
  vector<int> mst;

  void read(){
    int n, m, source, target, w;
    cin >> n >> m;
    g.clear();
    g = graph( n );
    int id = 0;
    for ( int i = 0; i < m; i++ ){
      cin >> source >> target >> w;
      g.insert( id, source - 1, target - 1, w );
      g.insert( id, target - 1, source - 1, w );
      id++;
    }
  }

  void work(){
    int d;
    int minCost, secondCost;
    int visited;

    prim(g, mst, minCost, -1, visited);

    //    cout << minCost << endl;

    if ( visited != g.size() ){
      cout << "No way" << endl;
      return;
    }

    secondCost = INT_MAX;
    vector<int> tmp;
    for ( int i = 0; i < mst.size(); i++ ){
      prim(g, tmp, d, mst[i], visited);
      if ( secondCost > d && visited == g.size()) secondCost = d;
    }

    if ( secondCost == INT_MAX ){
      cout << "No second way" << endl;
      return;
    }

    cout << secondCost << endl;
  }

  void prim(graph &g, vector<int> &m, int &dist, int extra, int &used){
    
    vector<edge> pi(g.size(), edge(-1,-1,-1) );
    vector<int> d(g.size(), INT_MAX);
    vector<int> visited(g.size(), 0);
    
    used = 0;
    
    int u;
    int s = 0;
    
    d[s] = 0;

    g.reset();
    m.clear();
    dist = 0;
    
    while ( 1 ){
      int min = INT_MAX;
      for ( int i = 0; i < g.size(); i++ ){
	if ( visited[i] == 0 && d[i] < min ) {
	  min = d[i];
	  u = i;
	}
      }
      
      if( min == INT_MAX ) break;
      visited[u] = 1;
      used++;

      edge v;
      
      while (1){
	v = g.next(u);
	if ( v.target == -1) break;

	if ( extra == v.id ) continue;

	if ( visited[v.target] == 0 && v.weight < d[v.target] ){
	  d[v.target] = v.weight;
	  pi[v.target] = v;
	}
      }
    }
    
    for ( int i = 0; i < g.size(); i++ ){
      if ( pi[i].target == -1 ) continue;
      m.push_back(pi[i].id);
      dist += pi[i].weight;
    }

  }
};

main(){
  Blackout B;
  int tcase;
  cin >> tcase;
  for ( int i = 1; i <= tcase; i++ ){
    cout << "Case #" << i << " : ";
    B.read();
    B.work();
  }
}  

// @end_of_source_code


