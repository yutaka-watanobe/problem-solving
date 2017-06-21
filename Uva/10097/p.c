// @JUDGE_ID:  17051CA  10097  C++
// @begin_of_source_code
/* Graph - BFS */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#include<queue>
#define MAX 101

int N, N1, N2, N3;

int M[MAX][MAX];
int U[MAX][MAX];

class Token{
 public:
  int t1, t2;
  int cost;

  Token(){}
  Token(int t1, int t2): t1(t1), t2(t2){
    cost = 0;
  }
};

int read(){
  int k;
  cin >> N;
  if ( N == 0 ) return 0;
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      cin >> k;
      if ( k != 0 ) M[i][j] = k - 1;
      else M[i][j] = -1;
    }
  }
  cin >> N1 >> N2 >> N3;
  N1--; N2--; N3--;

  return 1;
}

int bfs( int s1, int s2, int target ){
  Token u, v;
  queue<Token> q;

  u = Token( s1, s2 );
  for ( int i = 0; i < N; i++ ) fill ( U[i], U[i] + N, 0 );    

  q.push( u );

  int n1, n2, t;

  while ( !q.empty() ){
    u = q.front(); q.pop();
    n1 = u.t1; n2 = u.t2;
    U[n1][n2] = U[n2][n1] = 1;

    if ( n1 == N3 || n2 == N3 ){
      return u.cost;
    }

    /* move t1 */
    t = M[n1][n2];
    if ( t != -1 && !U[n2][t]){
      v = u;
      U[n2][t] = U[t][n2] = 1;
      v.cost = u.cost + 1;
      v.t1 = t;
      q.push( v );
    }

    /* move t2 */
    t = M[n2][n1];
    if ( t != -1 && !U[n1][t]){
      v = u;
      U[n1][t] = U[t][n1] = 1;
      v.cost = u.cost + 1;
      v.t2 = t;
      q.push( v );
    }
  }
  return -1;
}

void work(){
  int cost;
  cost = bfs(N1, N2, N3);

  if ( cost == -1 ) cout << "Destination is Not Reachable !" << endl;
  else cout << "Minimum Number of Moves = " << cost << endl;
}

main(){
  for ( int i = 1; read(); i++ ){
    cout << "Game #" << i << endl;
    work();
    cout << endl;
  }
}
// @end_of_source_code
