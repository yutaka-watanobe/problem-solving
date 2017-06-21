#include<iostream>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)

char G[8][8];
bool V[8][8];

void activate(int x, int y){
  G[y][x] = '0';
  V[y][x] = true;
  static const int dx[4] = {1, 0, -1, 0};
  static const int dy[4] = {0, -1, 0, 1};
  int nx, ny;

  rep(d, 3) rep(r, 4){
    nx = x + dx[r]*(d+1);
    ny = y + dy[r]*(d+1);
    if ( nx < 0 || nx >= 8 ) continue;
    if ( ny < 0 || ny >= 8 ) continue;
    if ( !V[ny][nx] && G[ny][nx] == '1' ) activate(nx, ny);
  }
}
main(){

  int n; cin >> n;
  int sx, sy;
  rep(tcase, n){
    rep(y, 8) rep(x, 8) cin >> G[y][x];
    rep(y, 8) rep(x, 8) V[y][x] = false;
    cin >> sx >> sy; 
    sx--; sy--;
    if ( G[sy][sx] == '1' ) activate(sx, sy);
    cout << "Data " << tcase+1 << ":" << endl;
    rep(y, 8){
      rep(x, 8) cout << G[y][x];
      cout << endl;
    }
  }
}
