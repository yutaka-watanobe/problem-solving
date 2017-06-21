// @JUDGE_ID:  17051CA  614  C++
// @begin_of_source_code
/* Maze traversal */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#define MAX 13
#define WEST 0
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define FAIL -1

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int Maze[ MAX ][ MAX ]; /* maze */
int U[ MAX ][ MAX ]; /* visited flag */
int D[ MAX ][ MAX ]; /* distance */
int sx, sy, ex, ey;
int row, column;

bool read(){
  cin >> row >> column >> sx >> sy >> ex >> ey;
  if ( row == 0 && column == 0 &&
       sx == 0 && sy == 0 && ex == 0 && ey == 0 ) return false;
  for ( int i = 0; i < row; i++ ){
    for ( int j = 0; j < column; j++ ){
      cin >> Maze[i][j];
    }
  }
  sx--; sy--; ex--; ey--;
  return 1;
}

void init(){
  for ( int i = 0; i < row; i++ ){
    for ( int j = 0; j < column; j++ ){
      U[i][j] = false;
      D[i][j] = INT_MAX;
    }
  }
}

bool can_visit( int x, int y, int nx, int ny, int direction ){
  if ( !(0 <= nx && 0 <= ny && nx < row && ny < column ) ) return false;
  
  if ( direction == EAST ){
    if ( Maze[x][y] == 1 || Maze[x][y] == 3 ) return false;
  } else if ( direction == SOUTH ){
    if ( Maze[x][y] == 2 || Maze[x][y] == 3 ) return false;
  } else if ( direction == NORTH ){
    if( Maze[x-1][y] == 2 || Maze[x-1][y] == 3 ) return false;
  } else if ( direction == WEST ){
    if ( Maze[x][y-1] == 1 || Maze[x][y-1] == 3 ) return false;
  }

  return true;
}

bool dfs( int x, int y, int d ){
  D[x][y] = d;
  if ( x == ex && y == ey ){
    return true;
  }

  int nx, ny;
  
  for ( int r = 0; r < 4; r++ ){
    nx = x + dx[r];
    ny = y + dy[r];
    if ( can_visit( x, y, nx, ny, r ) && !U[nx][ny] && D[nx][ny] == INT_MAX){
      U[nx][ny] = true;
      if ( dfs ( nx, ny, d + 1 ) ) return true;
    }
  }

  D[ x ][ y ] = FAIL;
  return false;
}


void work(){
  init();
  dfs( sx, sy, 1 );

  /* print result */
  cout << "+";
  for ( int j = 0; j < column; j++ ) cout << "---+";
  cout << endl;
  for ( int i = 0; i < row; i++ ){
    cout << "|";
    for ( int j = 0; j < column; j++ ){
      if ( D[i][j] == FAIL ) cout << "???";
      else if ( D[i][j] != INT_MAX ) printf("%3d", D[i][j] );
      else cout << "   ";
      if ( j < column - 1 ){
	if ( Maze[i][j] == 1 || Maze[i][j] == 3 ) cout << "|";
	else cout << " ";
      }
    }
    cout << "|" << endl;

    if ( i < row - 1 ){
      cout << "+";
      for ( int j = 0; j < column; j++ ){
	if ( Maze[i][j] == 2 || Maze[i][j] == 3 ) cout << "---";
	else cout << "   ";
      cout << "+";
      }
      cout << endl;
    }

  }
  cout << "+";
  for ( int j = 0; j < column; j++ ) cout << "---+";
  cout << endl;
  
}

main(){
  for ( int i = 1; read(); i++ ){
    cout << "Maze " << i << endl;
    cout << endl;
    work();
    cout << endl;
    cout << endl;
  }
}
// @end_of_source_code
