/**
 * BFS in grid
 */
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<string>
#include<vector>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)
static const int MAX = 1000;
static const int INFTY = (1<<20);

int H, W, N;
char G[MAX][MAX];
pair<int, int> C[11];

int bfs(int sy, int sx, int ty, int tx){
  queue<pair<int, int> > Q;
  int d[MAX][MAX];
  rep(i, H) rep(j, W) d[i][j] = INFTY;
  Q.push(make_pair(sy, sx));
  d[sy][sx] = 0;
  pair<int, int> u, v;
  static const int dy[4] = {0, -1, 0, 1};
  static const int dx[4] = {1, 0, -1, 0};
  int ny, nx;
  while(!Q.empty()){
    u = Q.front(); Q.pop();
    if ( u.first == ty && u.second == tx ) return d[u.first][u.second];
    rep(r, 4){
      ny = u.first + dy[r];
      nx = u.second + dx[r];
      if ( ny < 0 || nx < 0 || ny >= H || nx >= W ) continue;
	   if ( d[ny][nx] != INFTY ) continue;
	   if ( G[ny][nx] == 'X' ) continue;
	   d[ny][nx] = d[u.first][u.second] + 1;
	   Q.push(make_pair(ny, nx));
    }
  }
    return -1;

}
main(){
  cin >> H >> W >> N;
  rep(i, H) rep(j, W){
    cin >> G[i][j];
    if ( G[i][j] == 'S' ) C[0] = make_pair(i, j);
    if ( '1' <= G[i][j] && G[i][j] <= '9' ) C[G[i][j]-'0'] = make_pair(i, j);
  }
  int sum = 0;
  rep(i, N) {
    int tmp = bfs(C[i].first, C[i].second, C[i+1].first, C[i+1].second);
    sum += tmp;
  }
  cout << sum << endl;

}
