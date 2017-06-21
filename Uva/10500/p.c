// @JUDGE_ID:  17051CA  10500  C++
// @begin_of_source_code
/* Simulation - Grid */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MAX 15

#define UNKNOWN 0
#define SPACE 1
#define BLOCK 2

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int M[MAX][MAX];
int V[MAX][MAX];
int U[MAX][MAX];

int n, m;
int x_ini, y_ini;
int cost;

int read(){
  cin >> n >> m;
  if ( n == 0 && m == 0 ) return 0;
  cin >> x_ini >> y_ini;
  char ch;

  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < m; j++ ){
      cin >> ch;
      if ( ch == '0' ) M[i][j] = SPACE;
      else if ( ch == 'X' ) M[i][j] = BLOCK;
    }
  }

  x_ini--; y_ini--;

  for ( int i = 0; i < n; i++ ){
    fill ( V[i], V[i] + m, UNKNOWN );
    fill ( U[i], U[i] + m, 0 );
  }
  
  if ( M[x_ini][y_ini] == BLOCK ) M[x_ini][y_ini] = SPACE;
  return 1;
}
  
void dfs( int x, int y ){
  U[x][y] = 1;
  int ni, nj;
  cost++;

  for ( int d = 0; d < 4; d++ ){
    ni = x + dx[d];
    nj = y + dy[d];
    if ( 0 <= ni && 0 <= nj && ni < n && nj <m ){
      V[ni][nj] = M[ni][nj];
    }
  }

  for ( int d = 0; d < 4; d++ ){
    ni = x + dx[d];
    nj = y + dy[d];
    if ( 0 <= ni && 0 <= nj && ni < n && nj <m ){
      if ( V[ni][nj] == SPACE && !U[ni][nj] ){
	dfs ( ni, nj );
	return;
      }
    }
  }

}

void work(){
  
  V[x_ini][y_ini] = SPACE;
  cost = 0;

  dfs( x_ini, y_ini );
  cost--;

  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < m; j++ ) cout << "|---";
    cout << "|" << endl;
    for ( int j = 0; j < m; j++ ){
      cout << "|";
      if ( V[i][j] == SPACE ) cout << " 0 ";
      else if ( V[i][j] == BLOCK ) cout << " X ";
      else cout << " ? ";
    }
    cout << "|";
    cout << endl;
  }
  for ( int j = 0; j < m; j++ ) cout << "|---";
  cout << "|" << endl;
  cout << endl;
  cout << "NUMBER OF MOVEMENTS: " << cost << endl;
}

main(){
  while ( read() ){
    cout << endl;
    work();
  }
}
// @end_of_source_code
