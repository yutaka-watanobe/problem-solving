// @JUDGE_ID:  17051CA  10681  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

#define MAX 105
#define DMAX 205

class graph{
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

class point{
 public:
  int pos; int dist;
  point(){}
  point(int pos, int dist ): pos(pos), dist(dist){}
};

class TeobaldosTrip{
 public:
  int C, L, S, E, D;
  graph g;
  bool dist[MAX][DMAX];

  bool bfs( int start, int end ){
    queue<point> q;
    for ( int i = 0; i < C; i++ ){
      for ( int d = 0; d <= D; d++ ){
	dist[i][d] = false;
      }
    }

    q.push( point( start, 0 ) );
    dist[start][0] = true;

    g.reset();
    
    point u, v;
    int ndist, p;

    while ( !q.empty() ){
      u = q.front(); q.pop();

      if ( u.pos == end && u.dist == D ) return true;

      g.reset( u.pos );
      while (  (p = g.next(u.pos) ) != -1 ){
	ndist = u.dist + 1;

	if ( !dist[p][ndist] && ndist <= D){
	  dist[p][ndist] = true;
	  q.push( point( p, ndist) );
	}

      }
    }

    return false;
  }

  void work(){
    if ( bfs( S, E ) ) printf("Yes, Teobaldo can travel.\n");
    else printf("No, Teobaldo can not travel.\n");
  }

  bool read(){
    int A, B;
    scanf("%d %d", &C, &L);
    if ( C == 0 && L == 0 ) return false;
    
    g = graph( C );
    
    for ( int i = 0; i < L; i++ ){
      scanf("%d %d", &A, &B); A--; B--;
      g.insert( A, B ); g.insert( B, A );
    }

    scanf("%d %d %d", &S, &E, &D); S--; E--;
    return true;
  }
};

int main(){
  TeobaldosTrip TT;
  while ( TT.read() ) TT.work();
  return 0;
}
// @end_of_source_code




