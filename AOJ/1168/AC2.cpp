#include<iostream>
#include<queue>
#include<cassert>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
int W, H;
char G[62][22];
bool stable, V[62][22];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

pair<double, int> dfs(int y, int x, char ch){
  double c = 0.0;
  int cnt = 0;
  queue<pair<int, int> > Q;
  V[y][x] = true;
  pair<int, int> u;
  int ny, nx;
  int minx = x, maxx = x+1;
  for (Q.push(make_pair(y, x)); !Q.empty(); ){
    u = Q.front(); Q.pop();
    int b = u.first+1;
    if ( u.first == H-1 || (b < H && G[b][u.second] != '.' && G[b][u.second] != ch )){
      minx = min(minx, u.second);
      maxx = max(maxx, u.second+1);
    }
    c += u.second + 0.5;
    cnt++;
    rep(r, 4){
      ny = u.first + dy[r];
      nx = u.second + dx[r];
      if ( ny < 0 || nx < 0 || ny > H-1 || nx > W-1 || V[ny][nx]) continue;
      if ( G[ny][nx] == ch ){
	V[ny][nx] = true;
	Q.push(make_pair(ny, nx));
      } else if ( G[ny][nx] != '.' && r == 1 ) {
	pair<double, int> np = dfs(ny, nx, G[ny][nx]);
	c += np.first;
	cnt += np.second;
      }
    }
  }

  if ( ! ( minx < c/cnt && c/cnt < maxx ) ) stable = false;

  return make_pair(c, cnt);
}

main(){
  while( cin >> W >> H && W ){
    rep(i, H) rep(j, W) { cin >> G[i][j]; V[i][j] = false; }
    stable = true;
    rep(j, W){ 
      if ( G[H-1][j] != '.' ){
	dfs(H-1, j, G[H-1][j]);
	break;
      }
    }
    cout << (stable?"STABLE":"UNSTABLE") << endl;
  }
}
