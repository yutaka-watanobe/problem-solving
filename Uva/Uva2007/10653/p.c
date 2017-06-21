// @JUDGE_ID:  17051CA  10653  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<queue>
#include<stl.h>
#define MAX 1001

class Bombs{
 public:
  int row, column;
  int G[MAX][MAX];
  int gx, gy, sx, sy;

  void init(){
    for ( int i = 0; i < row; i++ ){
      for ( int j = 0; j < column; j++ ){
	G[i][j] = 0;
      }
    }
  }

  bool read(){
    cin >> row >> column;
    if ( row == 0 && column == 0 ) return false;
    
    init();
    int r, rownumber, n, j;
    cin >> r;
    for ( int i = 0; i < r; i++ ){
      cin >> rownumber >> n;
      for ( int k = 0; k < n; k++ ){
	cin >> j;
	G[rownumber][j] = 1;
      }
    }

    return true;
  }

  int bfs(){
    queue<pair<int, int> > q;
    int d[MAX][MAX];

    for ( int i = 0; i < row; i++ ){
      for ( int j = 0; j < column; j++ ){
	d[i][j] = 0;
      }
    }
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};

    q.push( make_pair(sx, sy) );

    pair<int, int> u, v;
    int x, y, nx, ny;
    
    d[sx][sy] = 1;
    
    while ( !q.empty() ){
      u = q.front(); q.pop();
      x = u.first;
      y = u.second;
      if ( x == gx && y == gy ) return d[x][y] - 1;

      for ( int r = 0; r < 4; r++ ){
	nx = x + dx[r];
	ny = y + dy[r];
	if ( !( 0 <= nx && 0 <= ny && nx < row && ny < column ) ) continue;

	if ( d[nx][ny] == 0 && G[nx][ny] == 0 ){
	  d[nx][ny] = d[x][y] + 1;
	  q.push( make_pair(nx, ny) );
	}
      }
    }
    
    assert( false );

  }

  void work(){
    cin >> sx >> sy;
    cin >> gx >> gy;
    printf("%d\n", bfs());
  }

};

main(){
  Bombs B;
  while ( B.read() ){
    B.work();
  }
}

// @end_of_source_code


