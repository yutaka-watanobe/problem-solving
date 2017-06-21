// @JUDGE_ID:  17051CA  2358  C++
// @begin_of_source_code
/* Grid BFS or DFS */
/*( use stack or queue not recursion, or stack overflow will occue ! ) */
#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#define MAX 65
#define SAFE 0
#define OUT 1
#define ACM 2
int dx[6] = { 0, -1, 0, 1, 0, 0};
int dy[6] = { 1, 0, -1, 0, 0, 0};
int dz[6] = { 0, 0, 0, 0, 1, -1};

int S[ MAX + 2 ][ MAX + 2 ][ MAX + 2 ]; /* space */
int n, m, k, l;
int n_max, m_max, k_max;

class Pos{
 public:
  int x, y, z;
  Pos(){}
  Pos( int x, int y, int z ): x(x), y(y), z(z){}
};

void init(){
  n_max = n + 2;
  m_max = m + 2;
  k_max = k + 2;
  for ( int i = 0; i < m_max; i++ ){
    for ( int j = 0; j < n_max; j++ ){
      for ( int h = 0; h < k_max; h++ ){
	S[i][j][h] = SAFE;
      }
    }
  }
}

bool read(){
  cin >> n >> m >> k >> l;
  if ( n == 0 && m == 0 && k == 0 && l == 0 ) return false;
  
  init();

  int pos;
  for ( int x = 0; x < l; x++ ){
    cin >> pos;
    int i = ( pos%(m*n) ) / n + 1;
    int j = ( pos%(m*n) ) % n + 1;
    int h = pos / (m*n) + 1;
    S[i][j][h] = ACM;
  }

  return true;
}

void bfs(){

  queue<Pos> q;
  Pos u;

  S[0][0][0] = OUT;
  q.push( Pos( 0, 0, 0 ) );

  int nx, ny, nz;
  while ( !q.empty() ){
    u = q.front(), q.pop();

    for ( int r = 0; r < 6; r++ ){
      nx = u.x + dx[r];
      ny = u.y + dy[r];
      nz = u.z + dz[r];
      if ( 0 <= nx  && 0 <= ny && 0 <= nz &&
	   nx < m_max && ny < n_max && nz < k_max && S[nx][ny][nz] == SAFE ) {
	S[nx][ny][nz] = OUT;
	q.push( Pos( nx, ny, nz ) );
      }
    }
  }
}

void makeOutSpace(){
  bfs();
}

void work(){

  makeOutSpace();

  int sum = 0;
  int nx, ny, nz;

  for ( int i = 1; i <= m; i++ ){
    for ( int j = 1; j <= n; j++ ){
      for ( int h = 1; h <= k; h++ ){
	if ( S[i][j][h] != ACM ) continue;
	for ( int r = 0; r < 6; r++ ){
	  nx = i + dx[r];
	  ny = j + dy[r];
	  nz = h + dz[r];
	  if ( 0 <= nx  && 0 <= ny && 0 <= nz &&
	       nx < m_max && ny < n_max && nz < k_max )
	    if ( S[nx][ny][nz] == OUT ) sum++;
	  }
      }
    }
  }

  cout << "The number of faces needing shielding is " << sum << "." << endl;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
