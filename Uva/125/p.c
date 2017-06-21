// @JUDGE_ID:  17051CA  125  C++
// @begin_of_source_code
/* Extention of Warshall's algorithm */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h> 
#include<vector>
#include<slist>
#define MAX 32

class graph {
 public:
  vector<vector<int> > m;
  vector<slist<int> > adj;
  vector<slist<int>::iterator> pos;
  
  graph(){}
  graph(int n){ resize(n); }

  void resize(int n){
    m.resize(n), adj.resize(n), pos.resize(n); 
    for(int i=0; i<n; i++){
      m[i].resize(n);
      fill(m[i].begin(), m[i].end(), 0);
      adj[i].clear();
    }
  }
  
  int size(){ return m.size(); }

  void insert(int i, int j, int e){
    m[i][j] = e;
    adj[i].push_front(j);
  }
  
  int next(int i){ 
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++; 
  }

  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  void clear(){ m.clear(), adj.clear(), pos.clear(); }

};

int m, n;
graph g, t;

int T[MAX][MAX];
int target;

void warshall(graph g){
  for(int y=0; y<g.size(); y++){
    for(int x=0; x<g.size(); x++){
      if(g.m[x][y]) T[x][y] = 1;
    }
  }

  for(int y=0; y<g.size(); y++){
    for(int x=0; x<g.size(); x++){
      if(T[x][y]){
	for(int i=0; i<g.size(); i++){
	  if ( T[y][i] ){
	    if ( x == i ) T[x][i] = -1;
	    else if ( T[x][y] == -1 || T[y][i] == -1 ) T[x][i] = -1;
	    else T[x][i] += T[x][y] * T[y][i];
	  }
	}
      }
    }
  }

  for(int y=0; y<g.size(); y++){
    for(int x=0; x<g.size(); x++){
      for(int i=0; i<g.size(); i++){
	if (  T[x][y] != 0 && T[y][i] != 0 && (T[x][y] == -1 || T[y][i] == -1) ){
	  T[x][i] = -1;
	}
      }
    }
  }
  
}

int read(){
  cin >> m;
  if ( cin.eof() ) return 0;

  vector<pair<int, int> > p;

  p.resize(m);
  
  int a, b;
  n = 0;
  for ( int i = 0; i < m; i++ ){
    cin >> a >> b;
    p[i].first = a;
    p[i].second = b;
    n = max( n, max( a, b ) );
  }

  g = graph( n + 1 );
  for ( int i = 0; i < p.size(); i++ ) g.insert( p[i].first, p[i].second, 1);
  return 1;
}


void work(){
  for ( int i = 0; i < MAX; i++ ){
    fill ( T[i], T[i] + MAX ,  0 );
  }

  warshall(g);
 
  for ( int i = 0; i < g.size(); i++ ){
    for ( int j = 0; j < g.size(); j++ ){
      if ( j ) cout << " ";
      cout << T[i][j];
    }
    cout << endl;
  }

}

main(){
  for ( int i = 0; read(); i++ ){
    cout << "matrix for city " << i << endl;
    work();
  }
}
// @end_of_source_code
