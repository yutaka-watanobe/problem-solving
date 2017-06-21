#include<iostream>
#include<queue>
#include<algorithm>
#include<cassert>

using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
#define NMAX 20
#define TMAX 100
static const int dy[5] = {0, 0, -1, 0, 1};
static const int dx[5] = {0, 1, 0, -1, 0};
class State{
public:
  int y, x, t, s;
  State(){}
  State(int y, int x, int t, int s):y(y), x(x), t(t), s(s){}
};

struct Item{ int disc, ts, te; };

int W, H, sy, sx, n;

bool T[NMAX][NMAX][TMAX+1][(1<<8)];
char G[NMAX][NMAX];
Item I[10];

bool valid(int ny, int nx){
  if ( ny < 0 || nx < 0 || ny >= H || nx >= W ) return false;
  return G[ny][nx] == '.';
}

int getAVPoint( int y, int x, int t ){
  int u = 0;

  for ( int r = 1; r < 5; r++ ){
    int ny = y + dy[r];
    int nx = x + dx[r];
    if (ny < 0 || nx < 0 || ny >= H || nx >= W )  continue;
    if ( G[ny][nx] == '.' ) continue;
    int inum = G[ny][nx] - '0';
    //if ( I[inum].ts  <= t && t <= I[inum].te ){
    if ( I[inum].ts  <= t && t < I[inum].te ){
      u = (u | (1<<inum));
    }
  }

  return u;
}

int getPoint(int s){
  int sum = 0;

  for ( int i = 0; i < n; i++ ){
    if ( (s & (1<<i)) > 0 ){
      sum += I[i].disc;
    }
  }

  return sum;
}

void compute(){
  rep(i, H) rep(j, W) rep(k, TMAX+1) rep(l, (1<<n)){
    T[i][j][k][l] = false;
  }

  T[sy][sx][0][getAVPoint(sy, sx, 0)] = true;

  queue<State> Q;
  Q.push(State(sy, sx, 0, getAVPoint(sy, sx, 0)));

  State u, v;

  int ans = 0;
  while(!Q.empty() ){
    u = Q.front(); Q.pop();
    ans = max(ans, getPoint(u.s));
    for ( int r = 0;  r < 5; r++ ){
      int ny = u.y + dy[r];
      int nx = u.x + dx[r];
      if ( !valid(ny, nx) ) continue;
      v = u;
      v.y = ny;
      v.x = nx;
      v.t++;
      if ( v.t > 100 ) continue;
      v.s = (v.s | getAVPoint(v.y, v.x, v.t));
      if ( !T[v.y][v.x][v.t][v.s] ){
	T[v.y][v.x][v.t][v.s] = true;
	Q.push(v);
      }
    }
  }

  cout << ans << endl;
}

main(){
  while(1){
    cin >> W >> H;
    if ( W == 0 && H == 0 ) break;
    rep(i, H) rep(j, W) {
      cin >> G[i][j];
      if ( G[i][j] == 'P' ){
	G[i][j] = '.';
	sy = i; sx = j;
      }
    }
    cin >> n;
    rep(i, n) {
      int g; cin >> g;
      cin >> I[g].disc >> I[g].ts >> I[g].te;
    }
    compute();
  }
}
