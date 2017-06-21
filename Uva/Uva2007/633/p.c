// @JUDGE_ID:  17051CA  633  C++
// @begin_of_source_code
/* 3 Dimensional BFS */  
#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<stl.h>
#define MAX 25
#define SPACE 0
#define OBSTACLE 1
#define TYPE_K 0
#define TYPE_B 1
#define TYPE_T 2
int dxK[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dyK[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dxB[4] = {-2, -2, 2, 2};
int dyB[4] = {2, -2, -2, 2};

class Move{
 public:
  int i, j, k, type;
  Move(){}
  Move( int i, int j, int k, int type ): i(i), j(j), k(k), type(type){}
};

class ChessKnight{
 public:
  int N;
  int G[ MAX * 2 ][ MAX * 2 ];
  int from[ MAX * 2 ][ MAX * 2 ][ 14 ];
  int sx, sy, tx, ty;

  int bfs(){
    queue<Move> q;
    
    q.push( Move( sx, sy, 0, -1 ) );
    
    for ( int i = 0; i < 14; i++ ) from[sx][sy][i] = 0;

    Move u, v;

    while ( !q.empty() ){
      u = q.front(), q.pop();

      int i = u.i;
      int j = u.j;
      int k = u.k;
      int type = u.type;
      if ( i == tx && j == ty ) return from[i][j][k];

      int x, y;

      /* K */
      for ( int r = 0; r < 8; r++ ){
	x = i + dxK[r];
	y = j + dyK[r];
	if ( 0 <= x && 0 <= y && x < N && y < N && G[x][y] == SPACE && type != TYPE_K ){
	  if ( from[x][y][r] == INT_MAX ){
	    from[x][y][r] = from[i][j][k] + 1;
	    q.push( Move( x, y, r, TYPE_K ) );
	  }
	}
      }
      /* B */
      for ( int r = 0; r < 4; r++ ){
	x = i + dxB[r];
	y = j + dyB[r];
	if ( 0 <= x && 0 <= y && x < N && y < N && G[x][y] == SPACE && u.type != TYPE_B ){
	  if ( from[x][y][r+8] == INT_MAX ){
	    from[x][y][r+8] = from[i][j][k] + 1;
	    q.push( Move( x, y, r+8, TYPE_B ) );
	  }
	}
      }
      /* T */
      y = j;
      x = N - i - 1;
      if ( 0 <= x && 0 <= y && x < N && y < N && G[x][y] == SPACE && u.type != TYPE_T ){
	if ( from[x][y][12] == INT_MAX ){
	  from[x][y][12] = from[i][j][k] + 1;
	    q.push( Move( x, y, 12, TYPE_T ) );
	}
      }
      x = i;
      y = N - j - 1;
      if ( 0 <= x && 0 <= y && x < N && y < N && G[x][y] == SPACE && u.type != TYPE_T ){
	if ( from[x][y][13] == INT_MAX ){
	  from[x][y][13] = from[i][j][k] + 1;
	    q.push( Move( x, y, 13, TYPE_T ) );
	}
      }

    }
    return -1;
  }

  void work(){
    int cost = bfs();
    if ( cost == -1 ){
      cout << "Solution doesn't exist" << endl;
    } else {
      cout << "Result : " << cost << endl;
    }
  }

  void init(){
    for ( int i = 0; i < N; i++ ){
      for ( int j = 0; j < N; j++ ){
	G[i][j] = SPACE;
	for ( int k = 0; k < 14; k++ ){
	  from[i][j][k] = INT_MAX;
	}
      }
    }
  }

  bool read(){
    int n;
    cin >> n;
    if ( n == 0 ) return false;
    N = 2*n;    
    
    init();

    cin >> sx >> sy >> tx >> ty;
    sx--; sy--; tx--; ty--;

    int x, y;
    while ( 1 ){
      cin >> x >> y;
      if ( x == 0 && y == 0 ) break;
      G[ x - 1 ][ y - 1 ] = OBSTACLE;
    }
    return true;
  }
};

main(){
  ChessKnight CK;
  while ( CK.read() ){
    CK.work();
  }
}

// @end_of_source_code


