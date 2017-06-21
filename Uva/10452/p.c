// @JUDGE_ID:  17051CA  10452  C++
// @begin_of_source_code
/* MAZE DFS */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#define MAX 9
int dx[3] = {0, -1, 0};
int dy[3] = {1, 0, -1};

int N, M;
char G[MAX][MAX];
bool U[MAX][MAX];

int sx, sy;
vector<int> P;

void read(){
  string line;
  char ch;
  cin >> N >> M;
  for ( int i = 0; i < N; i++ ){
    cin >> line;
    for ( int j = 0; j < M; j++ ){
      ch = line[j];
      if ( ch == '@' ){ sx = i; sy = j; }
      G[i][j] = ch;
      U[i][j] = false;
    }
  }
}

bool check( int x, int y ){
  char ch = G[x][y];
  return ( ch == 'I' || ch == 'E' || ch == 'H' || ch == 'O' || 
	   ch == 'V' || ch == 'A' || ch == '#' || ch == '@' );
}

bool dfs( int x, int y ){
  if ( G[x][y] == '#' ) return true;;

  int nx, ny;

  for ( int r = 0; r < 3; r++ ){
    nx = x + dx[r];
    ny = y + dy[r];
    if ( 0 <= nx && 0 <= ny && nx < N && ny < M && check( nx, ny ) ){
      if ( !U[nx][ny] ){
	U[nx][ny] = true;
	P.push_back( r );
	if ( dfs( nx, ny ) ) return true;;
	P.pop_back();
      }
    }
  }

  return false;
}

void work(){
  P.clear();
  dfs( sx, sy );

  for ( int i = 0; i < P.size(); i++ ){
    if ( i ) cout << " ";
    if ( P[i] == 0 ) cout << "right";
    else if ( P[i] == 1 ) cout << "forth";
    else if ( P[i] == 2 ) cout << "left";
  }
  cout << endl;
}

main(){
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    read();
    work();
  }
}

// @end_of_source_code
