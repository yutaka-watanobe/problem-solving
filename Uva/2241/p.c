// @JUDGE_ID:  17051CA  2241  C++
// @begin_of_source_code
/* Graph - All Pair Shortest Path ( Warshall Floyd ) */
#include<stdio.h>
#include<stl.h>
#include<slist>
#include<vector>

class graph{
 public:
  vector<vector<int> > m;
  vector<slist<int> > adj;
  vector<slist<int>::iterator> pos;

  graph(){}
  graph( int n ) { resize( n );}

  void resize( int n ){
    m.resize(n), adj.resize( n ), pos.resize(n);
    for ( int i = 0; i < n; i++ ){
      m[i].resize(n);
      fill(m[i].begin(), m[i].end(), 0);
      adj[i].clear();
    }
  }

  int size() { return m.size(); }

  void insert( int i , int j, int e ){
    m[i][j] = e;
    adj[i].push_front(j );
  }

  int next(int i){
    if(pos[i] == adj[i].end() ) return -1;
    return *pos[i]++;
  }

  void reset( int i ){ pos[i] = adj[i].begin();}
  void reset(){ for ( int i = 0; i < size(); i++ ) reset(i);}

  void clear(){ m.clear(), adj.clear(), pos.clear();}
};

void floyd( graph &g, vector<vector<int> > &d ){
  int n = g.size();
  
  d = g.m;

  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < n; j++ ){
      if ( i!=j && d[i][j] == 0 ) d[i][j] = INT_MAX;
    }
  }

  for ( int k = 0; k < n; k++ ){
    for ( int i = 0; i < n; i++ ){
      if ( d[i][k] == INT_MAX ) continue;
      for ( int j = 0; j < n; j++ ){
	if ( d[k][j] == INT_MAX ) continue;
	if ( d[i][j] == INT_MAX || d[i][k] + d[k][j] < d[i][j] ){
	  d[i][j] = d[i][k] + d[k][j];
	}
      }
    }
  }
}

int n;
graph g;

bool read(){
  cin >> n;
  if ( n == 0  ) return false;
  g.clear();
  g = graph( n );
  int k, source, time;
  for ( int i = 0; i < n; i++ ){
    cin >> k;
    for ( int j = 0; j < k; j++ ){
      cin >> source >> time;
      g.insert( i, source - 1, time );
    }
  }
  return true;
}

void work(){
  vector<vector<int> > d;
  floyd( g, d );

  bool connected = true;

  int shortest_time = INT_MAX;
  int shortest_start = 0;

  for ( int i = 0; i < n; i++ ){

    int max_dist = 0;
    for ( int j = 0; j < n; j++ ){
      max_dist = max( max_dist, d[i][j] );
    }

    if ( shortest_time > max_dist ){
      shortest_time = max_dist;
      shortest_start = i;
    }
  }

  if ( shortest_time == INT_MAX ) cout << "disjoint" << endl;
  else {
    cout << shortest_start+1 << " " << shortest_time << endl;
  }
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
