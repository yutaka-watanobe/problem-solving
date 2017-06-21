// @JUDGE_ID:  17051CA  2367  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<vector>
#include<set>
#include<slist>
#include<string>

void split( set<int> &d, const string &s, char c=' ' ){
  string t = "";
  d.clear();

  for ( int i = 0; i <s.size(); i++ ){
    if ( s[i] == c ){
      if ( t!="" ) { d.insert( atoi( t.c_str()) ); t = "";}
    }
    else t += s[i];
  }
  if ( t.size() ) d.insert( atoi(t.c_str() ) );
}

class graph{
 public:
  vector<vector<int> > m;
  vector<slist<int> > adj;
  vector<slist<int>::iterator> pos;

  graph(){}
  graph( int n ) { resize( n );}

  void resize( int  n ){
    m.resize( n ), adj.resize(n), pos.resize(n);
    for ( int i  = 0; i < n; i++ ){
      m[i].resize(n);
      fill(m[i].begin(), m[i].end(), 0 );
      adj[i].clear();
    }
  }

  int size() { return m.size(); }

  void insert( int i, int j, int e ){
    m[i][j] = e;
    adj[i].push_front(j);
  }

  int next( int i ){
    if ( pos[i] == adj[i].end() ) return -1;
    return *pos[i]++;
  }

  void reset( int i ){ pos[i] = adj[i].begin();}
  void reset(){ for(int i = 0; i < size(); i++ ) reset( i );}

  void clear(){ m.clear(), adj.clear(), pos.clear();}
};

int n;
graph g;

class FireStation{
 public:
  int source, target;
  int time;
  vector<int> cost;
  vector<int> pi;

  FireStation(){}

  FireStation( int target, int source): target(target), source(source){

  }
  
  void dijkstra(){
    cost.resize( g.size(), INT_MAX );
    pi.resize( g.size(), -1 );
    vector<int> visited(g.size(), 0 );
   
    cost[ source ] = 0;
    g.reset();

    while( 1 ){
      int min = INT_MAX;
      int x;
      for ( int i  = 0; i < g.size(); i++ ){
	if ( visited[i] == 0 && min > cost[i] ){
	  min = cost[i];
	  x = i;
	}
      }
      
      if ( min == INT_MAX ) break;

      visited[x] = 1;
      
      int v;
      while ( (v = g.next(x) ) != -1 ){
	if ( !visited[v] && cost[x] + g.m[x][v] < cost[v] ){
	  cost[v] = cost[x] + g.m[x][v];
	  pi[v] = x;
	}
	
      }
    }
    time = cost[target];
  }
  
  bool operator < ( const FireStation &f ) const {
    return f.time > time;
  }

  void printPath(){
    int p;
    vector<int> path;

    p = pi[ target ];
    path.push_back( target + 1 );
    while ( 1 ){
      if ( p == - 1 ) break;
      path.push_back( p+ 1);
      p = pi[p];
    }
    reverse( path.begin(), path.end() );
    for ( int i = 0; i < path.size(); i++ ){
      printf("%d\t", path[i] );
    }
  }
};

vector<FireStation> F;

bool read(){

  cin >> n;

  vector<int> com;
  g.clear();
  g = graph ( n );

  int e;

  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < n; j++ ){
      cin >> e;
      if ( e != -1 ) g.insert( i, j, e );
    }
  }

  string line;
  getline ( cin, line );
  return 1;
}

void work(){
  int firelocation;
  cin >> firelocation;
  string line;
  set<int> com;
  getline( cin, line );
  split( com, line );



  F.clear();
  
  set<int>::iterator pos;
  pos = com.begin();

  for ( ; pos != com.end(); pos++ ){
    F.push_back (FireStation( firelocation -1 , *pos - 1 )); /* zero base */
  }
    
  for ( int i = 0; i < F.size(); i++ ){
    F[i].dijkstra();
  }

  sort( F.begin(), F.end() );

  printf("%s\t%s\t%s\t%s\n", "Org", "Dest", "Time", "Path" );

  for ( int i = 0; i < F.size(); i++ ){
    FireStation f = F[i];
    printf("%d\t", f.source + 1 );
    printf("%d\t", firelocation);
    printf("%d\t", f.time );
    f.printPath();
    cout << endl;
  }

}

main(){
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
