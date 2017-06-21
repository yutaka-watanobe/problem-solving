// @JUDGE_ID:  17051CA  2367  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<vector>
#include<slist>
#include<string>

void split( vector<int> &d, const string &s, char c=' ' ){
  string t = "";
  d.clear();

  for ( int i = 0; i <s.size(); i++ ){
    if ( s[i] == c ){
      if ( t!="" ) { d.push_back( atoi( t.c_str()) ); t = "";}
    }
    else t += s[i];
  }
  if ( t.size() ) d.push_back( atoi(t.c_str() ) );
}

class graph{
 public:
  vector<vector<int> > m;
  vector<vector<int> > adj;
  vector<vector<int>::iterator> pos;

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
    adj[i].push_back(j);
  }

  int next( int i ){
    if ( pos[i] == adj[i].end() ) return -1;
    return *pos[i]++;
  }

  void reset( int i ){ pos[i] = adj[i].begin();}
  void reset(){ for(int i = 0; i < size(); i++ ) reset( i );}

  void clear(){ m.clear(), adj.clear(), pos.clear();}
};

class FireStation{
 public:
  int firelocation, pos;
  int time;
  vector<int> pi;

  FireStation(){}
  FireStation( int firelocation, int pos, vector<int> pi, int time): 
    firelocation(firelocation), pos(pos), pi(pi), time(time){
    
  }
  
  bool operator < ( const FireStation &f ) const {
    return time < f.time;
  }

  void printPath(){
    int p;
    vector<int> path;

    path.push_back( pos + 1 );
    p = pi[ pos ];
    while ( 1 ){
      if ( p == - 1 ) break;
      path.push_back( p + 1);
      p = pi[p];
    }

    for ( int i = 0; i < path.size(); i++ ){
      if ( i ) cout << "\t";
      printf("%d", path[i] );
    }
  }
};

void dijkstra( graph &g, vector<int> &pi, vector<int> &cost, int source ){
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
      if (  cost[x] + g.m[x][v] < cost[v] ){
	cost[v] = cost[x] + g.m[x][v];
	pi[v] = x;
      }
    }
  }
}

vector<FireStation> F;
int n;
graph g;
vector<int> pi, d;

void work(){
  int firelocation;
  cin >> firelocation;
  firelocation--;

  pi.clear();
  d.clear();

  dijkstra( g, pi, d, firelocation );

  string line;
  vector<int> com;
  getline( cin, line );
  split( com, line );

  F.clear();
  for ( int i = 0; i < com.size(); i++ ){
    int pos = com[i] - 1;
    F.push_back( FireStation( firelocation, pos, pi, d[pos] ) );
  }
  
  sort( F.begin(), F.end() );

  cout << "Org\tDest\tTime\tPath" << endl;

  for ( int i = 0; i < F.size(); i++ ){
    FireStation f = F[i];
    printf("%d\t", f.pos + 1 );
    printf("%d\t", firelocation + 1);
    printf("%d\t", f.time );
    f.printPath();
    cout << endl;
  }

}

void read(){
  cin >> n;

  g.clear();
  g = graph ( n );

  int e;
  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < n; j++ ){
      cin >> e;
      if ( i != j && e != -1 ) g.insert( j, i, e );
    }
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
