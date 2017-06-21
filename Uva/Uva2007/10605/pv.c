// @JUDGE_ID:  17051CA  10605  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<stl.h>
#define MAX 11

class MindeForDiamonds{
 public:
  char G[MAX][MAX];
  vector<pair<int, int> > D;
  int start[MAX][2];
  int nstart;

  set<pair<int, int> > S;
  int MD;
  int row, column;
  int ndiamond;
  int current;
  int limit;

  int getMD(){
    int x, y;
    int sum = 0;
    for ( int i = 0; i < ndiamond; i++ ){
      x = D[i].first;
      y = D[i].second;
      if ( G[x][y] == '*' ) sum += mbfs(x, y );
    }

    /*
    for ( int i = 0; i < row; i++ ){
      for ( int j = 0; j < column; j++ ){
	cout << G[i][j];
      }
      cout << endl;
    }
    cout << "sum  = " << sum << endl;
    */

    return sum;
  }

  int mbfs(int xx, int yy ){
    int dist[MAX][MAX];
    queue<pair<int, int> > q;

    for ( int i = 0 ; i < row; i++ ){
      for ( int j = 0; j < column; j++ ){
	dist[i][j] = INT_MAX;
      }
    }

    dist[xx][yy] = 1;
    q.push( make_pair(xx, yy) );
    
    pair<int, int> u, v;
    int nx, ny;
    int x, y;

    while ( !q.empty() ){
      u = q.front(); q.pop();
      x = u.first;
      y = u.second;

      if ( G[x][y] == '#' || (G[x][y] == '*' && ( x != xx && y!= yy )) ){
	return dist[x][y]-1 ;
      }

      nx = x + 1; ny = y;
      if ( dist[nx][ny] == INT_MAX ){
	dist[nx][ny] = dist[x][y] + 1;
	q.push( make_pair(nx, ny) );
      }
      nx = x; ny = y + 1;
      if ( dist[nx][ny] == INT_MAX ){
	dist[nx][ny] = dist[x][y] + 1;
	q.push( make_pair(nx, ny) );
      }

      nx = x - 1; ny = y;
      if ( dist[nx][ny] == INT_MAX ){
	dist[nx][ny] = dist[x][y] + 1;
	q.push( make_pair(nx, ny) );
      }
      nx = x ; ny = y-1;
      if ( dist[nx][ny] == INT_MAX ){
	dist[nx][ny] = dist[x][y] + 1;
	q.push( make_pair(nx, ny) );
      }
    }
  }

  bool startDig( int startPos, int nget, int ndigged ){
    if ( startPos >= nstart ) return false;

    // この startPos をスタートとしない
    if ( startDig(startPos + 1, nget, ndigged ) ) return true;

    // この startPos から堀始める 
    int x, y;
    x = start[startPos][0]; y = start[startPos][1];
    if ( G[x][y] != '#' && dig(startPos, nget, ndigged, x, y ) ) return true;
    return false;
  }

  bool dig( int startPos, int nget, int ndigged, int x, int y){
    if ( G[x][y] == '#' ) return false;

    char tmp = G[x][y];
    // 掘る
    ndigged++;
    if ( G[x][y] == '*' ) nget++;
    if ( nget == ndiamond ) return true;

    int md = ndiamond - nget;
    G[x][y] = '#';
        md = getMD();
    G[x][y] = tmp;

    if ( ndigged  + md > limit ) {
      return false;
    }

    if ( tmp == '*'){
      G[x][y] = '#';
      if ( startDig(startPos + 1, nget, ndigged ) ) return true;
    }


    // 4 方向にさらに掘る
    G[x][y] = '#';
    if ( dig(startPos, nget, ndigged,  x+1, y ) ) return true;
    if ( dig(startPos, nget, ndigged,  x, y+1 ) ) return true;
    if ( dig(startPos, nget, ndigged,  x-1, y ) ) return true;
    if ( dig(startPos, nget, ndigged,  x, y-1 ) ) return true;
    G[x][y] = tmp;// 元にもどす

    return false;
  }

  int compute(){
    limit = ndiamond;
    while (1){
      if ( startDig( 0, 0, 0) ) return limit;
      limit++;
    }
  }


  void read(){
    char ch;
    cin >> row >> column;
    D.clear();
    for ( int i = 0; i < row; i++ ){
      for ( int j = 0; j < column; j++ ){
	cin >> G[i][j];
	if ( G[i][j] == '*' ) D.push_back( make_pair(i, j) );
      }
    }
    ndiamond = D.size();
  }

  void bfs( int x, int y){
    int dist[MAX][MAX];
    queue<pair<int, int> > q;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    for ( int i = 0 ; i < row; i++ ){
      for ( int j = 0; j < column; j++ ){
	dist[i][j] = INT_MAX;
      }
    }

    dist[x][y] = 0;
    q.push( make_pair(x, y) );
    
    pair<int, int> u, v;
    int nx, ny;

    while ( !q.empty() ){
      u = q.front(); q.pop();
      x = u.first;
      y = u.second;
      for ( int r = 0; r < 4; r++ ){
	nx = x + dx[r];
	ny = y + dy[r];
	if ( !( 0 <= nx && 0 <= ny && nx < row && ny < column ) ) continue;

	if ( G[nx][ny] == '#' ){
	  S.insert( make_pair(x, y) );
	  MD += dist[x][y] + 1;
	  return;
	}

	if ( dist[nx][ny] == INT_MAX && G[nx][ny] != '#' ){
	  dist[nx][ny] = dist[x][y] + 1;
	  q.push( make_pair(nx, ny) );
	}
      }
    }
  }

  void init(){
    MD = 0;
    S.clear();

    for ( int i = 0; i < D.size(); i++ ) bfs( D[i].first, D[i].second );
    set<pair<int, int> >::iterator pos;
    nstart = 0;

    for ( pos = S.begin(); pos != S.end(); pos++ )  {
      start[nstart][0] = (*pos).first;
      start[nstart][1] = (*pos).second;
      nstart++;
    }
  }

  void work(){
    init();
    printf("%d\n", compute());
    /*
    for ( int i = 0; i < row; i++ ){
      for ( int j = 0; j < column; j++ ){
	cout << G[i][j];
      }
      cout << endl;
    }
    cout << endl;*/
  }
};

main(){
  MindeForDiamonds MFD;
  int tcase; cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    MFD.read();
    MFD.work();
  }
}
// @end_of_source_code


