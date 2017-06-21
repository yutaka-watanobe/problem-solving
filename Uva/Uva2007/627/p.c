// @JUDGE_ID:  17051CA  627  C++
// @begin_of_source_code
/* Simplest BFS */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h> 
#include<vector>
#include<queue>

void split( vector<int> &d, const string &s, char c ){
  d.clear();
  string t = "";
  for ( int i = 0; i < s.size(); i++ ){
    if ( s[i] == c ){
      if ( t != "" ){ d.push_back( atoi( t.c_str() ) ); t = "";}
    }
    else t += s[i];
  }
  if ( t.size() ) d.push_back( atoi(t.c_str() ) );
}

/*********
 * Graph *
 *********/

/** 
 * class: graph 
 * It must be non-weighted graph !!.
 */
class graph {
 public:
  vector<vector<int> > adj;
  vector<vector<int>::iterator> pos;
  
  /** constructor */
  graph(){}
  graph(int n){ resize(n); }

  /**  @param the number of node */ 
  void resize( int n ){
    adj.resize(n), pos.resize(n); 
    for( int i = 0; i < n; i++ ){
      adj[i].clear();
    }
  }
  
  /** @return the number of node */
  int size(){ return adj.size(); }

  /** insert  */
  void insert( int i, int j ){
    adj[i].push_back(j);
  }
  
  /** refere to adjacency list of node i, and move one. */
  int next( int i ){ 
    if( pos[i] == adj[i].end() ) return -1;
    return *pos[i]++; 
  }
  
  /** reset */
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for( int i = 0; i < size(); i++) reset(i); }

  /* less used methods */
  void erase( int i, int j){
    for( vector<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++){
      if( *it==j ){
	adj[i].erase(it);
	break;
      }
    }
  }

  /** clear all nodes */
  void clear(){ adj.clear(), pos.clear(); }
};

void bfs(graph &g, vector<int> &pi, vector<int> &d, int source, int target ){

  queue<int> q;
  int u, v;

  pi.clear();
  d.clear();
  pi.resize(g.size(), -1);
  d.resize(g.size(), 0);

  q.push(source);
  d[ source ] = 1;

  g.reset();

  while(!q.empty()){
    u = q.front(), q.pop();

    if ( u == target ) {
      int p = target;
      vector<int> path;
      while ( 1 ){
	if ( p == -1 ) break;
	path.push_back( p + 1 );
	p = pi[ p ];
      }
      reverse( path.begin(), path.end() );
      for ( int i = 0; i < path.size(); i++ ){
	cout << path[i] << " ";
      }
      cout << endl;
      return ;
    }

    while( ( v = g.next(u) ) != -1 ){
      if( !d[v] ){
	d[v] = d[u] + 1;
	pi[v] = u;
	q.push( v );
      }
    }
  }

  cout << "connection impossible" << endl;
}

graph g;
int n;

int read(){
  string line;

  if ( !( cin >> n ) ) return false;

  getline( cin, line );

  g.clear();
  g = graph( n );

  int source, target;
  vector<int> tlist;

  for ( int i = 0; i < n; i++ ){
    cin >> source;
    getline( cin, line );
    split( tlist, line.substr( 1 ), ',' );

    for ( int t = 0; t < tlist.size(); t++ ){
      target = tlist[t];
      g.insert( source - 1, target - 1 );
    }
  }

  return true;
}

void work(){
  
  int m;
  int source, target;
  vector<int> pi, d;
  cin >> m;
  for ( int i = 0; i < m; i++ ){
    cin >> source >> target;
    bfs( g, pi, d, source - 1, target - 1);
  }

  string line;
  getline( cin, line );
}

main(){
  while ( read() ){
    cout << "-----" << endl;
    work();
  }
}
// @end_of_source_code
