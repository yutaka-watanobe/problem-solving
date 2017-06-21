// @JUDGE_ID:  17051CA  2543  C++
// @begin_of_source_code
/* Eular Cycle & Eular Path */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stl.h>

void split ( vector<int> &d, const string &s, char c=' ' ) {
  string t = "";
  d.clear();

  for ( int i = 0; i < s.size(); i++ ){    
    if ( s[i] == c ){
      if ( t != "" ){ d.push_back( atoi(t.c_str()) ); t = ""; }
    }
    else t += s[i];
  }
  if ( t.size() ) d.push_back(atoi(t.c_str()));
}

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

class DoorMan{
 public:
  int start, N;
  int ndoor;
  vector<int> visited;
  graph g;

  bool validate(){

    for ( int i = 0; i < N; i++ ) {
      if ( g.adj[i].size() > 0 && !visited[i] ) return false;
    }

    if ( start == 0 ){
      /* Eular Cycle */
      for ( int i = 0; i < N; i++ ){
	if ( g.adj[i].size() % 2 != 0 ) return false;
      }
      return true;
    } else {
      /* Eular Path */
      if ( g.adj[start].size() % 2 != 1 ||
	   g.adj[0].size() % 2 != 1 ) return false;
      for ( int i = 0; i < N; i++ ){
	if ( i != 0 && i != start && g.adj[i].size() % 2 != 0 ) return false;
      }
      return true;
    }
    assert( false );
  }

  void work(){
    bfs( 0 );
    if ( validate() )  cout << "YES " << ndoor << endl;
    else cout << "NO" << endl;
  }

  void bfs( int s ){
    queue<int> q;
    int u, v;
    
    q.push( s );
    
    visited[ s ] = true;
    g.reset();
    
    while ( !q.empty() ){
      u = q.front(), q.pop();
      while( ( v = g.next(u) ) != -1 ){
	if( !visited[ v ] ){
	  visited[ v ] = true;
	  q.push( v );
	}
      }
    }
  }

  void init(){
    ndoor = 0;
    g.clear();
    g = graph ( N );
    visited.clear();
    visited.resize( N, 0 );
  }

  bool read(){
    string line;
    cin >> line;
    if ( line == "ENDOFINPUT" ) return false;
    assert( line == "START" );
    cin >> start >> N;
    init();
    getline( cin, line );
    for ( int source = 0; source < N; source++ ){
      getline( cin, line );
      vector<int> targets;
      split( targets, line );

      for ( int j = 0; j < targets.size(); j++ ){
	int target = targets[j];
	g.insert( source, target );
	g.insert( target, source );
	ndoor++;
      }
    }
    cin >> line; /* END */
    assert( line == "END" );
    return true;
  }
};

main(){
  DoorMan man;
  while ( man.read() ){
    man.work();
  }
}

// @end_of_source_code


