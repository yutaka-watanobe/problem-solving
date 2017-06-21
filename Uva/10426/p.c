// @JUDGE_ID:  17051CA  10426  C++
// @begin_of_source_code
/* BFS */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<stl.h>
#include<queue>

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int mx, my;

class Leader{
 public:
  vector<vector<int> > D;
  vector<vector<int> > DS;
  int row, col, sx, sy;
  bool safty;

  Leader(){}
  Leader( int row, int col, int sx, int sy): row(row), col(col), sx(sx), sy(sy){
    D.resize( row );
    DS.resize( row );
    for ( int i = 0; i < row; i++ ){
      D[i].resize( col, INT_MAX );
      DS[i].resize( col, INT_MAX );
    }
  }

  void compute(){
    safty = false;
    bfs( D );
    safty = true;
    bfs( DS );
  }

  void bfs( vector<vector<int> > &d ){
    queue<pair<int, int> > q;
    vector<vector<int> > U;

    U.resize( row );
    for ( int i = 0; i < row; i++ ) U[i].resize( col, 0 );

    for ( int i = 0; i < row; i++ ){
      for ( int j = 0; j < col; j++ ){
	d[i][j] = INT_MAX;
      }
    }

    q.push( make_pair( sx, sy ) );

    d[sx][sy] = 0;
    U[sx][sy] = 1;

    pair<int, int> p;
    int px, py, nx, ny;

    while ( !q.empty() ){
      p = q.front(), q.pop();
      
      px = p.first; py = p.second;

      for ( int r = 0; r < 8; r++ ){
	nx = px + dx[r];
	ny = py + dy[r];
	if ( 0 <= nx && 0 <= ny && nx < row && ny < col && checkMonster( nx, ny ) ){
	  if ( !U[nx][ny] ){
	    d[nx][ny] = d[px][py] + 1;
	    U[nx][ny] = 1;
	    q.push( make_pair( nx, ny ) );
	  }
	}
      }
    }
  }

  bool checkMonster( int x, int y ){
    if ( safty ) return true;
    else {
      return ( !( x == mx && y == my ) );
    }
  }

};

vector<Leader> L;
int row, col;

void read(){
  L.clear();
  
  int x, y;
  
  cin >> row >> col;
  for ( int i = 0; i < 4; i++ ){
    cin >> x >> y;
    x--; y--;
    L.push_back( Leader( row, col, x, y ) );
  }

  cin >> mx >> my;
  mx--; my--;
}

void work(){
  for ( int i = 0; i < 4; i++ ){
    L[i].compute();
  }

  int minimum = INT_MAX;

  for ( int t = 0; t < 4; t++ ){
    
    for ( int i = 0; i < row; i++ ){
      for ( int j = 0; j < col; j++ ){
	int sum = 0;
	for ( int k = 0; k < 4; k++ ){
	  int d;
	  if ( k == t ) d = L[k].DS[i][j];
	  else d = L[k].D[i][j];
	  if ( d == INT_MAX ) goto next;
	  sum += d;
	}
	minimum = min( minimum, sum );
      next:;
      }
    }
  }

  if ( minimum == INT_MAX ) cout << "Meeting is impossible." << endl;
  else{
    cout << "Minimum time required is " << minimum << " minutes." << endl;
  }

}

main(){
  string test_case;
  while ( cin >> test_case ){
    cout << test_case << endl;
    read();
    work();
  }
}
// @end_of_source_code
