// @JUDGE_ID:  17051CA  589  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<queue>
#include<string>
#define MAX 25
#define SPACE 0
#define BLOCK 1

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
char moveTable[4] = {'e', 'n', 'w', 's'};
char pushTable[4] = {'E', 'N', 'W', 'S'};

struct Cost{
  int nwalk;
  int npush;
};

class State{
 public:
  int px, py, bx, by;
  int nwalk;
  int npush;
  string path;

  State(){}
  State( int px, int py, int bx, int by ):px(px), py(py), bx(bx), by(by){
    nwalk = 0;
    npush = 0;
    path = "";
  }

  void move( char ch ){
    if ( islower( ch ) ){
      nwalk++;
    } else {
      npush++;
    }
    path += ch;
  }

};

class PushingBox{
 public:
  int row, column;
  int G[ MAX + 2 ][ MAX + 2 ];
  int sx, sy, bx, by, tx, ty;
  Cost used[ MAX * MAX ][ MAX * MAX ];
  int min_push;
  int min_walk;
  string min_path;

  int getPos( int x, int y ){
    return ( x - 1 ) * column + ( y - 1 );
  }

  bool relax( Cost cost, int w, int p ){
    if ( cost.npush == p ){
      if ( cost.nwalk > w ) return true;
    } else if ( cost.npush > p ) {
      return true;
    }
    return false;
  }

  void bfs( State s ){

    queue<State> q;

    for ( int i = 0; i < row * column; i++ ){
      for ( int j = 0; j < row * column; j++ ){
	used[i][j].nwalk = INT_MAX;
	used[i][j].npush = INT_MAX;
      }
    }

    used[ getPos( s.px, s.py) ][ getPos( s.bx, s.by ) ].nwalk = 0;
    used[ getPos( s.px, s.py) ][ getPos( s.bx, s.by ) ].npush = 0;
    
    q.push( s );

    State u, v;

    int nx, ny, nbx, nby, pos, npos, bpos, nbpos;

    while ( !q.empty() ){
      u = q.front(); q.pop();

      if ( u.bx == tx && u.by == ty ) addResult( u );

      if ( min_push < u.npush ) continue;

      pos = getPos( u.px, u.py );
      bpos = getPos( u.bx, u.by );

      for ( int r = 0; r < 4; r++ ){
	nx = u.px + dx[r];
	ny = u.py + dy[r];
	npos = getPos( nx, ny );

	if ( nx == u.bx && ny == u.by ){
	  nbx = u.px + dx[r]*2;
	  nby = u.py + dy[r]*2;
	  nbpos = getPos( nbx, nby );
	  if ( G[nbx][nby] == SPACE && relax( used[npos][nbpos], u.nwalk, u.npush  ) ){
	    used[npos][nbpos].nwalk = u.nwalk;
	    used[npos][nbpos].npush = u.npush + 1;
	    v = u;
	    v.px = nx; v.py = ny;
	    v.bx = nbx; v.by = nby;
	    v.move( pushTable[r] );
	    q.push( v );
	  }
	} 
	if ( G[nx][ny] == SPACE && !( nx == u.bx && ny == u.by ) &&
	     relax( used[npos][bpos], u.nwalk, u.npush ) ){
	  used[npos][bpos].nwalk = u.nwalk + 1;
	  used[npos][bpos].npush = u.npush;
	  v = u;
	  v.px = nx; v.py = ny;
	  v.move( moveTable[r] );
	  q.push( v );
	}
      }



    }

  }
  
  void addResult( State s ){
//    cout << s.path << endl;
    if ( min_push == s.npush ){
      if ( min_walk > s.nwalk ){
	min_push = s.npush;
	min_walk = s.nwalk;
	min_path = s.path;
      }
    } else {
      if ( min_push > s.npush ){
	min_push = s.npush;
	min_walk = s.nwalk;
	min_path = s.path;
      }
    }
  }

  void work(){
    min_push = INT_MAX;
    min_walk = INT_MAX;

    State initial = State( sx, sy, bx, by );
    bfs( initial );

    if ( min_push == INT_MAX ){
      printf("Impossible.\n");
    } else {
      printf("%s\n", min_path.c_str() );
    }
  }

  bool read(){
    cin >> row >> column;
    if ( row == 0 && column == 0 ) return false;
    assert( 0 <= row && row <= 20 );
    assert( 0 <= column && column <= 20 );

    char ch;
    for ( int i = 0; i < row + 2; i++ ){
      for ( int j = 0; j < column + 2; j++ ){
	if ( i == 0 || j == 0 || i == row + 1 || j == column + 1 ){
	  G[i][j] = BLOCK;
	} else {
	  cin >> ch;
	  if ( ch == '#' ){
	    G[i][j] = BLOCK;
	  } else if ( ch == '.' ){
	    G[i][j] = SPACE;
	  } else if ( ch == 'S' ){
	    G[i][j] = SPACE;
	    sx = i; sy = j;
	  } else if ( ch == 'B' ){
	    G[i][j] = SPACE;
	    bx = i; by = j;
	  } else if ( ch == 'T' ){
	    G[i][j] = SPACE;
	    tx = i; ty = j;
	  } else {
	    assert( false );
	  }
	}
      }
    }
    return true;
  }
};

main(){
  PushingBox PB;
  for ( int i = 1; PB.read(); i++ ){
    printf("Maze #%d\n", i );
    PB.work();
    printf("\n");
  }
}

// @end_of_source_code


