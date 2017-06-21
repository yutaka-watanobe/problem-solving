// @JUDGE_ID:  17051CA  10381  C++
// @begin_of_source_code
/* Max-min */
#include<stdio.h>
#include<iostream>
#include<queue>
#include<set>
#include<algorithm>

using namespace std;

#define MAX 40

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

#define SPACE 0
#define BLOCK 1

#define NIL -1

class Point{
 public:
  int x, y;
  Point(){}
  Point( int x, int y ):x(x), y(y){}

  bool operator != ( const Point &p ) const{
    return x != p.x || y != p.y;
  }

  bool operator == ( const Point &p ) const{
    return x == p.x && y == p.y;
  }
};

class Cell{
 public:
  int cost[4];
  Cell(){
    for ( int i = 0; i < 4; i++ ) cost[i] = NIL;
  }
};

class State{
 public:
  int local_max, nstep;
  Point position;

  State(){}
  State( int m, int s, Point pos): local_max(m), nstep(s), position(pos){}

  bool operator < ( const State &s ) const {
    if ( local_max == s.local_max ) return nstep < s.nstep;
    else  return local_max < s.local_max;
  }

};

class TheRock{
 public:
  int tunnel_state[MAX+2][MAX+2];
  Cell cells[MAX+2][MAX+2];
  int row, column;
  Point enter_cell, exit_cell;

  int used[MAX+2][MAX+2];
  int dist[MAX+2][MAX+2];

  void init(){
    for ( int i = 1; i <= row; i++ ){
      for ( int j = 1; j <= column; j++ ){
	cells[i][j] = Cell();
	used[i][j] = -1;
	dist[i][j] = 0;
      }
    }
  }

  void bfs( Point extraRock, int current ){
    static int dx[4] = {-1, 0, 1, 0};
    static int dy[4] = {0, 1, 0, -1};

    queue<Point> q;
    
    q.push( exit_cell );

    Point u, v;
    int nx, ny, x, y;

    dist[exit_cell.x][exit_cell.y] = 0;
    used[exit_cell.x][exit_cell.y] = current;

    while ( !q.empty() ){
      u = q.front(), q.pop();
      x = u.x; y = u.y;
      for ( int r = 0; r < 4; r++ ){
	nx = x + dx[r];
	ny = y + dy[r];
	if ( tunnel_state[nx][ny] != BLOCK && Point( nx, ny ) != extraRock && used[nx][ny] != current ){
	  used[nx][ny] = current;
	  dist[nx][ny] = dist[x][y] + 1;
	  q.push( Point( nx, ny ) );
	}
      }
    }

    x = extraRock.x; y = extraRock.y;

    if ( tunnel_state[x-1][y] == SPACE ) cells[x-1][y].cost[SOUTH] = dist[x-1][y];
    if ( tunnel_state[x][y-1] == SPACE ) cells[x][y-1].cost[EAST] = dist[x][y-1];
    if ( tunnel_state[x+1][y] == SPACE ) cells[x+1][y].cost[NORTH] = dist[x+1][y];
    if ( tunnel_state[x][y+1] == SPACE ) cells[x][y+1].cost[WEST] = dist[x][y+1];
  }

  int dijkstra(){
    static int dx[4] = {-1, 0, 1, 0};
    static int dy[4] = {0, 1, 0, -1};
    multiset<State> PQ;
    PQ.insert( State( 0, 0, enter_cell ) );
    
    State cur;
    int x, y, nx, ny;

    for ( int i = 1; i <= row; i++ ){
      for ( int j = 1; j <= column; j++ ){
	used[i][j] = 0;
      }
    }

    while ( 1 ){
      cur = *PQ.begin();
      PQ.erase( PQ.begin() );

      if ( cur.position == exit_cell ) {
	return cur.local_max;
      }

      x = cur.position.x; 
      y = cur.position.y;
      used[x][y] = 1;

      for ( int r = 0; r < 4; r++ ){
	nx = x + dx[r];
	ny = y + dy[r];
	if ( tunnel_state[nx][ny] == SPACE && !used[nx][ny] ){
	  used[nx][ny] = 1;
	  PQ.insert( State( max( cells[x][y].cost[r] + cur.nstep, cur.local_max ), cur.nstep + 1, Point(nx, ny) ) );
	}
      }
    }
  }

  void work(){
    init();
    
    int current = 0;
    for ( int i = 1; i <= row; i++ ){
      for ( int j = 1; j <= column; j++ ){
	if ( tunnel_state[i][j] == SPACE ) bfs( Point( i, j ), current++ );
      }
    }

    printf("%d\n", dijkstra() );
  }
 
  void read(){
    char ch;
    cin >> row >> column;
    for ( int i = 0; i < row + 2; i++ ){
      for ( int j = 0; j < column + 2; j++ ){
	if ( i == 0 || i == row + 1 || j == 0 || j == column + 1 ){
	  tunnel_state[i][j] = BLOCK;
	  continue;
	}
	cin >> ch;
	tunnel_state[i][j] = SPACE;
	if ( ch == '#' ) tunnel_state[i][j] = BLOCK;
	else if ( ch == 'E' ) enter_cell = Point( i, j );
	else if ( ch == 'X' ) exit_cell = Point( i, j );
      }
    }
  }

};

main(){
  TheRock TR;
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    TR.read();
    TR.work();
  }
}


// @end_of_source_code


