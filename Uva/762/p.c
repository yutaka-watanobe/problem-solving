// @JUDGE_ID:  17051CA  762  C++
// @begin_of_source_code
/* BFS */
/* too slow! ?  */
#include<stdio.h>
#include<iostream>
#include<stl.h> 
#include<vector>
#include<string>
#include<queue>
#include<map>

#define MAX 677

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

class WeShipCheap{
 public:
  graph g;
  map<int, string> I_S;
  map<string, int> S_I;
  set<string> S;

  void printPath(vector<int> pi, int s, int t ){
    vector<int> path;

    int p = t;
    while ( 1 ){
      path.push_back( p );
      if ( p == s ) break;
      p = pi[p];
    }
    reverse( path.begin(), path.end() );

    for ( int i = 0; i < path.size()-1; i++ ){
      cout << I_S[ path[i] ] << " " << I_S[ path[i+1] ] << endl;
    }
  }

  void work(){
    string source, target;
    int s, t;
    cin >> source >> target;
    s = S_I[source];
    t = S_I[target];

    if ( find(S.begin(), S.end(), source ) == S.end() ||
	 find(S.begin(), S.end(), target ) == S.end() ){
      cout << "No route" << endl;
      return;
    }

  /*    if ( s == t ){ */
/*        cout << source << " " << source << endl; */
/*        return; */
/*        //      cout << "No route" << endl; */
/*      } */


    vector<int> pi;
    if ( bfs(g, pi, s, t ) ) printPath(pi, s, t);
    else printf("No route\n");
  }

  bool bfs(graph &g, vector<int> &pi, int s, int t){
    queue<int> q;
    int u, v;
    
    vector<int> used;

    pi.resize(g.size(), -1);
    used.resize( g.size(), 0 );
    q.push(s);
    used[s] = 1;

    g.reset();
    
    while ( !q.empty() ){
      u = q.front(), q.pop();
      if ( u==t ) return true;
      while( ( v = g.next(u) ) != -1 ){
	if( !used[v] == 1 ){
	  pi[v] = u;
	  used[v] = 1;
	  q.push( v );
	}
      }
    }
    return false;
  }
  
  bool read(){
    int m;
    cin >> m;
    if ( cin.eof() ) return false;
    
    I_S = map<int, string>();
    S_I = map<string, int>();
    S.clear();

    string source, target;
    int s, t;

    g = graph( MAX );
    
    int current = 0;

    for ( int i = 0; i < m; i++ ){
      cin >> source >> target;

      if ( find( S.begin(), S.end(), source ) != S.end() ){
	s = S_I[ source ];
      } else {
	s = current++;
	S.insert( source );
	S_I[source] = s;
	I_S[s] = source;
      }

      if ( find( S.begin(), S.end(), target ) != S.end() ){
	t = S_I[ target ];
      } else {
	t = current++;
	S.insert( target );
	S_I[target] = t;
	I_S[t] = target;
      }

      g.insert( s, t );  g.insert( t, s );

    }
    return true;
  }
};

main(){
  WeShipCheap WSC;
  for ( int i = 0; WSC.read(); i++ ){
    if ( i ) printf("\n");
    WSC.work();
  }
}


// @end_of_source_code
