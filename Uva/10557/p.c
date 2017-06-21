// @JUDGE_ID:  17051CA  10557  C++
// @begin_of_source_code
#include<stdio.h>
#include<climits>
#include<iostream>
#include<queue>
#define MAX 101
#define LIMIT 10001

class XYZZY{
 public:
  int M[MAX][MAX];
  int C[MAX];
  int L[MAX];
  int n;

  bool bfs(){
    
    queue<int> q;
    
    q.push( 0 );
    int u, v;
    L[0] = 100;

    while ( !q.empty() ){
      u = q.front(); q.pop();
	
      if ( u == n-1 ) return true;

      for ( int v = 0; v < n; v++ ){
	if ( M[u][v] && L[v] < L[u] + C[v] && L[u] + C[v] < LIMIT && L[u] + C[v] > 0){
	  L[v] = L[u] + C[v];
	  q.push( v );
	}
      }
    }
    return false;
  }

  void work(){

    for ( int i = 0; i < n; i++ ) {
      L[i] = INT_MIN;
    }
    L[0] = 100;
    if ( bfs() ) printf("winnable\n");
    else printf("hopeless\n");
  }

  bool read(){
    scanf("%d", &n); 
    if ( n == -1 ) return false;
    /* init */
    for ( int i = 0; i < n; i++ ){
      for  ( int j = 0; j < n; j++ ){
	M[i][j] = 0;
      }
    }
    int m, t;
    for ( int i = 0; i < n; i++ ) {
      scanf("%d %d", &C[i], &m );
      for ( int j = 0; j < m; j++ ){
	scanf("%d", &t ); t--;
	M[i][t] = 1;
      }
    }
    return true;
  }

};

main(){
  XYZZY X;
  while ( X.read() ){
    X.work();
  }
}
// @end_of_source_code
