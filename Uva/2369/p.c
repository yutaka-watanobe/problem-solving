// @JUDGE_ID:  17051CA  2369  C++
// @begin_of_source_code
/* BFS & create BFS Path */
#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<stl.h>
#define MAX 21
typedef pair<int, int> Pos;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

char M[ MAX ][ MAX ]; /* map */
int D[ MAX ][ MAX ]; /* distance table for BFS */
int W[ MAX ][ MAX ]; /* weight of path */
bool U[ MAX ][ MAX ]; /* visited table for BFS */
double L[ MAX ][ MAX ]; /* load table */

vector< vector<Pos> > P; /* path list */
map<char, Pos> CtoP; /* char to pos */
map<Pos, char> PtoC; /* pos to char */
int row, column;

void read(){
  cin >> column >> row;
  assert( column < 20 && row < 20 );

  char ch;
  for ( int i = 0; i < row; i++ ){
    for ( int j = 0; j < column; j++ ){
      cin >> ch;
      if ( ch == 'X' || ch == '.'){
	M[i][j] = ch;
      } else if ( 'A' <= ch && ch <= 'O' ) {
	CtoP[ ch ] = make_pair( i, j );
	PtoC[ make_pair(i, j ) ] = ch; 
	M[i][j] = ch;
      } else {
	assert ( false );
      }
    }
  }
}

void init(){
  for ( int i = 0; i < row; i++ ){
    for ( int j = 0; j < column; j++ ){
      L[i][j] = 0.0;
    }
  }
}

void printResult(){
  for ( int i = 0; i < row; i++ ){
    for ( int j = 0; j < column; j++ ){
      cout << " ";
      if ( M[i][j] == '.' ) printf("%6.2lf", L[i][j] );
      else printf("%6.2lf", 0.0 );
    }
    cout << endl;
  }
}

void bfs( Pos source, Pos target ){
  /* init */
  for ( int i = 0; i < row; i++ ){
    for ( int j = 0; j < column; j++ ){
      D[i][j] = INT_MAX;
      U[i][j] = false;
      W[i][j] = 0;
    }
  }

  queue<Pos> q;

  U[ source.first ][ source.second ] = true;
  D[ source.first ][ source.second ] = 1;

  q.push( source );
  Pos u, v;
  int nx, ny;
  char tchar = PtoC[ target ];

  while ( !q.empty() ){
    u = q.front(), q.pop();

    if ( u == target ) break;

    for ( int r = 0; r < 4; r++ ){
      nx = u.first + dx[r];
      ny = u.second + dy[r];
      if ( 0 <= nx && 0 <= ny && nx < row && ny < column && !U[nx][ny] && 
	   ( M[nx][ny] == '.' || M[nx][ny] == tchar)  ){
	U[nx][ny] = true;
	D[nx][ny] = D[u.first][u.second] + 1;
	q.push( make_pair( nx, ny ) );
      }
    }
  }
}

void createPath( Pos pos, int d, vector<Pos> p, Pos &target ){
  if ( pos == target ){
    P.push_back( p );
    return ;
  }

  int nx, ny;

  vector<Pos> u;

  for ( int r = 0; r < 4; r++ ){
    nx = pos.first + dx[r];
    ny = pos.second + dy[r];
    if ( 0 <= nx && 0 <= ny && nx < row && ny < column && D[nx][ny] == d - 1 ){
      u = p;
      u.push_back( make_pair( nx, ny ) );
      createPath( make_pair( nx, ny ), d - 1, u, target );
    }
  }


}

void survey( Pos source, Pos target, double load ){
  bfs( source, target );

  P.clear();
  vector<Pos> p;
  createPath( target, D[target.first][target.second], p, source );

  int size = P.size();

  for ( int i = 0; i < P.size(); i++ ){
    p = P[i];
    for ( int j = 0; j < p.size(); j++ ){
      L[ p[j].first ][ p[j].second ] += load / size;
    }
  }

}

void work(){
  string str;
  init();
  double load;
  while ( 1 ){
    cin >> str >> load;
    if ( str == "XX" && load == 0.0 ) break;
    if ( CtoP.find( str[0] ) == CtoP.end() ||
	 CtoP.find( str[1] ) == CtoP.end() ) continue;

    survey( CtoP[ str[0] ], CtoP[ str[1] ], load );
  }

  printResult();
}

main(){
  read();
  work();
}
// @end_of_source_code
