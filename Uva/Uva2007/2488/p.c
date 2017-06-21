// @JUDGE_ID:  17051CA  2488  C++
// @begin_of_source_code
/* Maze Traversal */
#include<stdio.h>
#include<iostream>
#include<queue>
#include<string>
#include<stl.h>
#define MAX 102
#define ESCAPE -1
#define SPACE 0
#define DOOR 1
#define WALL 2

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int G[ 2*MAX + 1 + 2 ][ 2*MAX + 1 + 2]; /* banpei */
int D[ 2*MAX + 1 + 2 ][ 2*MAX + 1 + 2]; /* distance table for BFS */
int startX, startY;
int row, column;

int bfs(){
  queue<pair<int, int> > Q;
  
  for ( int i = 0; i < 2*row + 3; i++ ){
    for ( int j = 0; j < 2*column + 3; j++ ){
      D[i][j] = 0;
    }
  }

  D[ startX ][ startY ] = 1;
  Q.push( make_pair( startX, startY ) );
  
  pair<int, int> u;
  int x, y, dist;
  while ( !Q.empty() ){
    u = Q.front(), Q.pop();
    x = u.first; y = u.second;
    dist = D[x][y];

    int nx, ny;
    for ( int r = 0; r < 4; r++ ){
      nx = x + dx[r];
      ny = y + dy[r];
      if ( G[nx][ny] == ESCAPE ) return dist;

      if ( G[nx][ny] == SPACE && !D[nx][ny] ){
	D[nx][ny] = dist + 1;
	Q.push( make_pair( nx, ny ) );
      }
      if ( G[nx][ny] == DOOR && !D[nx][ny] ){
	D[nx][ny] = dist;
	Q.push( make_pair( nx, ny ) );
      }
      
    }
  }

  return -1;
}


void work(){
  int cost;
  cost = bfs();
  if ( cost == -1 ) cout << "No escape!" << endl;
  else cout << cost << endl;
}

bool read(){
  cin >> column >> row;
  if ( row == 0 && column == 0 ) return false;

  string line;
  getline( cin, line ); /* empty line */

  for ( int i = 1; i <= 2 * row + 1; i++ ){
    getline( cin, line );
    for ( int j = 1; j <= 2 * column + 1; j++ ){
      char ch = line[j - 1];
      if ( ch == 's' ){ 
	startX = i; startY = j;
	G[i][j] = SPACE;
      }
      else if ( ch == '+' || ch == '|' || ch == '-' ){
	G[i][j] = WALL;
      } else if ( ch == '.' ){
	G[i][j] = DOOR;
      } else if ( ch == ' ' ){
	G[i][j] = SPACE;
      } else {
	assert( false );
      }
    }
  }

  /* banpei */
  for ( int j = 0; j < 2*column + 3; j++ ){
    G[0][j] = ESCAPE;
    G[ row * 2 + 2 ][j] = ESCAPE;
  }
  for ( int i = 0; i < 2*row + 3; i++ ){
    G[i][0] = ESCAPE;
    G[i][column * 2 + 2] = ESCAPE;
  }

  return true;
}

main(){
  for ( int i = 1; read(); i++ ){
    cout << "Maze " << i << ": ";
    work();
  }
}

// @end_of_source_code


