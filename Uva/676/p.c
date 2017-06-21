// @JUDGE_ID:  17051CA  676  C++
// @begin_of_source_code
/* DFS - Backtracking */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#define EMPTY 0
#define STONE 1
#define LIMIT 50001

int checkBoard[9][9] = { {0,1,0,1,0,1,0,1,0},
			 {1,0,1,0,1,0,1,0,1},
			 {0,1,0,1,0,1,0,1,0},
			 {1,0,1,0,1,0,1,0,1},
			 {0,1,0,1,0,1,0,1,0},
			 {1,0,1,0,1,0,1,0,1},
			 {0,1,0,1,0,1,0,1,0},
			 {1,0,1,0,1,0,1,0,1},
			 {0,1,0,1,0,1,0,1,0} };
			 
class HorseStepMaze{
 public:
  int sx, sy, ex, ey;
  int M[11][11];
  int nstep;
  pair<int, int> P[ LIMIT ];

  bool dfs( int x, int y ){
    nstep++;
    if ( nstep >= LIMIT ) return false;

    P[ nstep ] = make_pair( x, y );

    if ( x == ex && y == ey ){
      return true;
    }

    int nx, ny;
    /* 1 */
    nx = x - 1;
    ny = y + 1;
    M[x][y] = STONE;
    if ( M[nx][ny] == EMPTY ) {
      if ( dfs( nx, ny ) ) return true;
      nstep++;
      if ( nstep >= LIMIT ) return false;
      P[ nstep ] = make_pair( x, y );
    }

    /* 2 */
    nx = x + 1;
    ny = y + 1;
    if ( M[nx][ny] == EMPTY ) {
      if ( dfs( nx, ny ) ) return true;
      nstep++;
      if ( nstep >= LIMIT ) return false;
      P[ nstep ] = make_pair( x, y );
    }

    /* 3 */
    nx = x + 1;
    ny = y - 1;
    if ( M[nx][ny] == EMPTY ) {
      if ( dfs( nx, ny ) ) return true;
      nstep++;
      if ( nstep >= LIMIT ) return false;
      P[ nstep ] = make_pair( x, y );
    }

    /* 4 */
    nx = x - 1;
    ny = y - 1;
    if ( M[nx][ny] == EMPTY ) {
      if ( dfs( nx, ny ) ) return true;
      nstep++;
      if ( nstep >= LIMIT ) return false;
      P[ nstep ] = make_pair( x, y );
    }

    M[x][y] = EMPTY;

    return false;
  }

  void init(){
    for ( int i = 0; i < 11; i++ ){
      for ( int j = 0; j < 11; j++ ){
	if ( i == 0 || j == 0 || i == 10 || j == 10 ){
	  M[i][j] = STONE;
	} else {
	  M[i][j] = EMPTY;
	}
      }
    }
  }

  void work(){
    init();

    if ( checkBoard[ex-1][ey-1] != checkBoard[sx-1][sy-1] ){
      printf("fail\n");
      return;
    } else {
      nstep = -1;
      dfs( sx, sy );
    }

    if ( nstep  > 50000 ){
      printf("more than 50000 steps\n");
    } else {
      for ( int i = 0; i <= nstep; i++ ){
	if ( i ) printf(", ");
	printf("(%d,%d)", P[i].first, P[i].second);
      }
      printf("\n");
    }
  }

  void read(){
    char ch;
    /* scanf("(%d,%d)(%d,%d)", &sx, &sy, &ex, &ey ); */
    cin >> ch >> sx >> ch >> sy >> ch >> ch >> ex >> ch >> ey >> ch;
    assert( 1 <= sx && sx <= 9 );
    assert( 1 <= sy && sy <= 9 );
    assert( 1 <= ex && ex <= 9 );
    assert( 1 <= ey && ey <= 9 );
  }
};

main(){
  HorseStepMaze HSM;
  int tcase;
  /* scanf( "%d", &tcase ); */
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    if ( i ) printf("\n");
    HSM.read();
    HSM.work();
  }
}

// @end_of_source_code


