// @JUDGE_ID:  17051CA  2341  C++
// @begin_of_source_code
/* DFS !! */ 
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#define MAX 105

#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

class Memory{
 public:
  int start, end;
  int direction;

  Memory(){}
  Memory( int  start, int end, char d ): start(start), end(end){
    switch( d ){
    case 'R':
      direction = RIGHT; break;
    case 'U':
      direction = UP; break;
    case 'L':
      direction = LEFT; break;
    case 'D':
      direction = DOWN; break;
      assert( false );
    }
  }
};

int m, n;
int G[ MAX ][ MAX ]; /* grid */
vector<Memory> M;

void read(){
  cin >> m >> n;
  M.clear();
  for ( int i = 0; i < m; i++ ){
    for ( int j = 0; j < n; j++ ){
      cin >> G[i][j];
    }
  }
  
  int start, end;
  char direction;
  while ( 1 ){
    cin >> start >> end;
    if ( start == 0 && end == 0 ) break;
    cin >> direction;
    M.push_back( Memory( start, end, direction ) );
  }
}

bool dfs( int x, int y, int mpos ){

  if ( mpos == M.size() ){
    return true;
  }
  
  Memory memory = M[ mpos ];

  int nx, ny;
  int pos = 1;
  
  /* be careful about this process !!! */
  while ( pos < memory.start ){
    nx = x + dx[ memory.direction ]*pos;
    ny = y + dy[ memory.direction ]*pos;
    if ( nx < 0 || ny < 0 || m <= nx || n <= ny || G[nx][ny] == 1 ) return false;
    pos++;
  }

  for ( int step = memory.start; step <= memory.end; step++ ){
    nx = x + dx[ memory.direction ]*step;
    ny = y + dy[ memory.direction ]*step;
    if ( nx < 0 || ny < 0 || m <= nx || n <= ny || G[nx][ny] == 1 ) return false;
    if ( dfs( nx, ny, mpos + 1 ) ) return true;
  }

  return false;
}

void work(){
  int count = 0;

  for ( int i = 0; i < m; i++ ){
    for ( int j = 0; j < n; j++ ){
      if ( G[i][j] == 0 ){
	if ( dfs( i, j, 0 ) ){
	  count++;
	}
      }
    }
  }
  
  cout << count << endl;
}

main(){
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    read();
    work();
  }
}
// @end_of_source_code
