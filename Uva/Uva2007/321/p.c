// @JUDGE_ID:  17051CA  321  C++
// @begin_of_source_code
/* 状態 Graph */
/* BFS で状態をつくりながら最小パスを求めた */
/* 一般に状態グラフを作ってBFSをかますような感じ */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h> 
#include<vector>
#include<slist>
#include<queue>
#define OFF 0
#define ON 1
#define MOVE 2

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
  
  vector<int> & operator[](int i){ return m[i]; }

  int next(int i){ 
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++; 
  }
  
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  void clear(){ m.clear(), adj.clear(), pos.clear(); }

  graph & operator=(const graph &g){
    m = g.m;
    adj = g.adj;
    pos.resize(m.size());
    for(int i=0; i<m.size(); i++)
      pos[i] = adj[i].begin();
  }
};

int pow[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

class Villa{
 public:
  vector<pair<int, int> > P;
  int pos;
  int state;
  int sw[10];

  Villa(){
    pos = 0;
    fill ( sw, sw+10, OFF );
    sw[0] = ON;
    state = 1;
    
  }

  void toggle(int i){
    if ( sw[i] == ON ){
      sw[i] = OFF;
      state -= pow[i];
      P.push_back(pair<int, int>(OFF, i));
    }else if ( sw[i] == OFF ){
      sw[i] = ON;
      state += pow[i];
      P.push_back(pair<int, int>(ON, i));
    }
  }

};

int r, d, s;
graph D, S;

bool bfs(Villa &goal){
  queue<Villa> q;
  Villa U, V;
  int v;
  int visited[10][1024];
  for ( int i = 0; i < 10; i++ ){
    fill( visited[i], visited[i]+1024, 0 );
  }

  Villa room = Villa();

  q.push( room );

  while( !q.empty() ){
    U = q.front(), q.pop();
    
    if( U.pos == r-1 && U.state == pow[r-1] ){
      goal = U;
      return true;
    }
    
    for ( int v = 0; v < D.size(); v++ ){
      if( D.m[U.pos][v] ){
	if ( !visited[v][U.state] && U.sw[v] == ON){
	  V = U;
	  V.pos = v;
	  visited[v][V.state] = 1;
	  V.P.push_back(pair<int, int>(MOVE, v));
	  q.push( V );
	}
      }
    }

    for ( int v = 0; v < S.size(); v++ ){
      if ( S.m[U.pos][v] && U.pos != v){
	V = U;
	V.toggle(v);
	if ( !visited[V.pos][V.state] ){
	  visited[V.pos][V.state] = 1;
	  q.push( V );
	}
      }
    }
    
  }

  return false;
}

void work(){
  Villa g;
  if (bfs(g) ){
    cout << "The problem can be solved in " << g.P.size() << " steps:" << endl;
    for ( int i = 0; i < g.P.size(); i++ ){
      if ( g.P[i].first == MOVE ){
	cout << "- Move to room " << g.P[i].second + 1 << "." << endl;
      }else if ( g.P[i].first == ON ){
	cout << "- Switch on light in room " << g.P[i].second+1 << "." << endl;
      }else if ( g.P[i].first == OFF ){
	cout << "- Switch off light in room " << g.P[i].second+1 << "." << endl;
      }
    }
  }else{
    cout << "The problem cannot be solved." << endl;
  }
}

int read(){
  cin >> r >> d >> s;
  if ( r == 0 && d == 0 && s == 0 ) return 0;
  
  D = graph( r );
  S = graph( r );

  int a, b;
  for ( int i = 0; i < d; i++ ){
    cin >> a >> b;
    a--; b--;
    D.insert(a, b, 1);
    D.insert(b, a, 1);
  }

  for ( int i = 0; i < s; i++ ){
    cin >> a >> b;
    a--; b--;
    S.insert( a, b, 1 );
  }

  return 1;
}

main(){
  for ( int i = 1; read(); i++ ) {
    cout << "Villa #" << i << endl;
    work();
    cout << endl;
  }
}
// @end_of_source_code
