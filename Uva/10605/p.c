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
  int row, column;
  int ndiamond;
  int limit;

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
    if ( tmp == '*' ) nget++;
    if ( nget == ndiamond ) return true;

    if ( ndigged  + (ndiamond - nget) > limit ) return false;


    G[x][y] = '#';
    if ( tmp == '*' && ( startDig(startPos + 1, nget, ndigged ) ) ) return true;
    // 4 方向にさらに掘る
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

	if ( G[nx][ny] == '#' ){
	  S.insert( make_pair(x, y) );
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


