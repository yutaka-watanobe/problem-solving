#include<iostream>
#include<queue>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++ )
int W, H;
char G[62][22];
bool stable, V[62][22];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

pair<double, int> dfs(int y, int x, char ch){
  double c = 0.0;
  queue<int> Q;
  V[y][x] = 1;
  int u, ny, nx, cnt = 0;
  int minx = x, maxx = x+1;
  for (Q.push(y*W+x); !Q.empty(); ){
    u = Q.front(); Q.pop();
    int b = u/W+1;
    if ( u/W == H-1 || (b < H && G[b][u%W] != '.' && G[b][u%W] != ch )){
      minx = min(minx, u%W);
      maxx = max(maxx, u%W+1);
    }
    c += u%W + 0.5;
    cnt++;
    rep(r, 4){
      ny = u/W + dy[r];
      nx = u%W + dx[r];
      if ( ny < 0 || nx < 0 || ny > H-1 || nx > W-1 || V[ny][nx]) continue;
      if ( G[ny][nx] == ch ){
	V[ny][nx] = 1;
	Q.push(ny*W+nx);
      } else if ( G[ny][nx] != '.' && r == 1 ) {
	pair<double, int> np = dfs(ny, nx, G[ny][nx]);
	c += np.first;
	cnt += np.second;
      }
    }
  }
  if ( ! ( minx < c/cnt && c/cnt < maxx ) ) stable = 0;

  return make_pair(c, cnt);
}

main(){
  while( cin >> W >> H && W ){
    rep(i, H) rep(j, W) { cin >> G[i][j]; V[i][j] = 0; }
    rep(j, W) if ( G[H-1][j] != '.' ){
      stable = 1;
      dfs(H-1, j, G[H-1][j]);
      cout << (stable?"STABLE":"UNSTABLE") << endl;
      break;
    }
  }
}
