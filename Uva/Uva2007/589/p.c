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
#define EAST 0
#define NORTH 1
#define WEST 2
#define SOUTH 3

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int id[4] = {2, 3, 0, 1}; /* inverse direction */

char walkTable[4] = {'e', 'n', 'w', 's'};
char pushTable[4] = {'E', 'N', 'W', 'S'};

class State{
 public:
  int bx, by;
  int direction;
  int nwalk;
  int npush;

  string path;

  State(){}
  State( int bx, int by , int direction):bx(bx), by(by), direction(direction){
    nwalk = 0;
    npush = 0;
    path = "";
  }

  void move( char ch ){
    if ( islower( ch ) ) nwalk++;
    else npush++;
    path += ch;
  }

};

class PushingBox{
 public:
  int row, column;
  int G[ MAX + 2 ][ MAX + 2 ];
  int sx, sy, bx, by, tx, ty;
  bool visited[ MAX + 2 ][ MAX + 2 ][4];
  bool used[ MAX + 2 ][ MAX + 2 ];

  queue<State> Q;

  int min_push;
  int min_walk;
  string min_path;

  int getPos( int x, int y ){
    return ( x - 1 ) * column + ( y - 1 );
  }

  void addResult( State s ){
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

  void addWalk( State &state, vector<vector<int> > &pi, int x, int y ){
    int nx, ny;
    while ( 1 ){
      state.move( walkTable[ pi[x][y] ] );
      if ( x == -1 ) break;
      x = x + dx[ id[ pi[x][y] ] ];
      y = y + dy[ id[ pi[x][y] ] ];
    }
  }

  void addState( State state, int sourceX, int sourceY ){
    int targetX = state.bx;
    int targetY = state.by;

    queue<pair<int, int> > q;
    vector<vector<int> > pi;
    pi.resize( row + 2 );
    for ( int i = 0; i < row + 2; i++ ) pi[i].resize( column + 2, -1 );

    for ( int i = 1; i <= row; i++ ){
      for ( int j = 1; j <= column; j++ ){
	used[i][j] = false;
      }
    }

    q.push( make_pair( sourceX, sourceY ) );
    used[sourceX][sourceY] = true;

    pair<int, int> u, v;

    State ns;

    while ( !q.empty() ){
      u = q.front(); q.pop();

      int x, y;
      x = u.first;
      y = u.second;

      /* east */
      for ( int r = 0; r < 4; r++ ){
	if ( targetX + dx[r] == x && targetY + dy[r] == y && !visited[targetX][targetY][r] ) {
	  ns = state;
	  ns.direction = r;
	  addWalk( ns, pi, x, y );
	  cout << ns.path << endl;
	  Q.push( ns );
	  visited[targetX][targetY][r] = true;
	}
      }
      
      int nx, ny;

      for ( int r = 0; r < 4; r++ ){
	nx = x + dx[r];
	ny = y + dy[r];
	if ( G[nx][ny] == SPACE && !used[nx][ny] && !( nx == targetX && ny == targetY ) ){
	  used[nx][ny] = true;
	  pi[nx][ny] = r;
	  q.push( make_pair( nx, ny ) );
	}
      }
    }
  }
  
  void BFS(){

    State u, v;

    while ( !Q.empty() ){
      u = Q.front(); Q.pop();

      if ( u.bx == tx && u.by == ty ) addResult( u );

      int nx, ny;
      nx = u.bx + dx[ id[u.direction] ];
      ny = u.by + dy[ id[u.direction] ];
      if ( G[nx][ny] == SPACE ){
	addState( u, u.bx, u.by );
      }
    }

  }

  void work(){
    min_push = INT_MAX;
    min_walk = INT_MAX;

    for ( int i = 0; i < row + 2; i++ ){
      for ( int j = 0; j < column + 2; j++ ){
	for ( int k = 0; k < 4; k++ ){
	  visited[i][j][k] = false;
	}
      }
    }
    
    Q = queue<State>();

    State initial = State( bx, by, 0 );
    addState( initial, sx, sy );

    //BFS();

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



