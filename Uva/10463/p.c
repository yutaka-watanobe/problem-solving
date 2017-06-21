// @JUDGE_ID:  17051CA  10463  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<queue>
#include<cmath>

#define MAX 16
#define PMAX 20
#define EVEN 0
#define ODD 1

bool prime[PMAX];

void eratos(int n){
  fill(prime, prime+PMAX, false);
  /* 奇数を素数候補とする */
  for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
  prime[2] = true;
  
  /* 合成数でない奇数だけを残す */
  for ( int i = 3, limit = (int)sqrt(n); i <= limit; i += 2 ) {
    if ( !prime[i] ) continue;
    
    for ( int j = i * i, k = i * 2; j <= n; j += k ) prime[j] = false;
  }
}

class State{
 public:
  int x, y, dist;
  State(){}
  State( int x, int y, int dist ): x(x), y(y), dist(dist){}
};

class AztecKnight{
 public:
  bool dist[MAX][MAX][PMAX];
  int row, column, srow, scol, drow, dcol;
  int type;

  void bfs(){

    queue<State> q;
    q.push( State(srow, scol, 0) );
    dist[srow][scol][0] = true;
    
    int dx[8] = {-1, -3, -3, -1, 1, 3, 3, 1};
    int dy[8] = {3, 1, -1, -3, -3, -1, 1, 3};

    State u, v;
    int x, y;
    int nx, ny;
    int d;

    while( !q.empty() ){
      u = q.front(); q.pop();
      x = u.x; y = u.y; d = u.dist;

      if ( x == drow && y == dcol ){
	if ( type == EVEN ) {
	  if ( d == 2 )printf("The knight takes %d prime moves.\n", d);
	  else printf("The knight takes %d composite move(s).\n", d);
	  return;
	}
	
	if ( prime[d] ) {
	  printf("The knight takes %d prime moves.\n", d);	  
	  return;
	}
      }

      for ( int  r = 0; r < 8; r++ ){
	nx = x + dx[r];
	ny = y + dy[r];
	if( !( 0 <= nx && 0 <= ny && nx < row && ny < column ) )continue;

	if( !dist[nx][ny][d+1] ){
	  dist[nx][ny][d+1] = true;
	  q.push( State( nx, ny, d+1 ) );
	}
      }
    }
  }

  void init(){
    for ( int i = 0; i < row; i++ ){
      for ( int j = 0; j < column; j++ ){
	for ( int k = 0; k < PMAX; k++ ){
	  dist[i][j][k] = false;
	}
      }
    }
    if ( abs(srow-drow) % 2 == 0 &&
	 abs(scol-dcol) % 2 == 0 ) type = EVEN;
    else type = ODD;
  }

  void work(){
    if ( unreachible() ){
      printf("Destination is not reachable.\n");
      return;
    }

    init();
    bfs();
  }

  bool read(){
    cin >> row >> column >> srow >> scol >> drow >> dcol;
    if ( cin.eof() ) return false;
    return true;
  }

  bool unreachible(){
    if ( (abs(srow-drow) + abs(scol-dcol)) % 2 != 0 ) return true;
    else return false;
  }
};

main(){
  eratos(PMAX);
  AztecKnight AK;
  for ( int i = 1; AK.read(); i++ ){
    printf("CASE# %d: ", i);
    AK.work();
  }
}

// @end_of_source_code


