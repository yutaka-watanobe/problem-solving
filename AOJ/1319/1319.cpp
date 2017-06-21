#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
static int C[20][3] = {{5,4,1},{6,0,2},{7,1,3},{8,2,4},{9,3,0},{0,11,10},{1,12,11},{2,13,12},{3,14,13},{4,10,14},{15,9,5},{16,5,6},{17,6,7},{18,7,8},{19,8,9},{10,16,19},{11,17,15},{12,18,16},{13,19,17},{14,15,18}};
static const int dx[3] = {0, -1, 1};
static const int dy[3] = {1, 0, 0};
static const int MAX = 205;
static const int SHIFT = 102;

class State{
public:
  int x, y, b, r, c;
  State(){}
  State(int x, int y, int b, int r):x(x), y(y), b(b), r(r){ c = 0;}
};

State getNext(State u, int r){
  int bt[3], nt[3], nb, nr = -1;
  int nx = dx[r];
  int ny = dy[r];
  if ( (u.x + u.y)%2  ){ nx *= (-1); ny *= (-1); }
  nx += u.x;
  ny += u.y;

  rep(i, 3) bt[i] = C[u.b][i];
  rotate(bt, bt + u.r, bt + 3);
  nb = bt[r]; // next bottom
  rep(i, 3) nt[i] = C[nb][i];

  rep(i, 3){
    if ( u.b == nt[r] ){ nr = i; break; }
    rotate(nt, nt+1, nt+3);
  }

  return State(nx, ny, nb, nr);
}

int bfs(int gx, int gy, int gb){
  bool vis[MAX][MAX][20][3];
  queue<State> Q;
  rep(i, MAX)rep(j, MAX) rep(k,20) rep(l,3) vis[i][j][k][l] = false;
  Q.push(State(SHIFT, SHIFT, 0, 0));
  vis[SHIFT][SHIFT][0][0] = true;
  State u, v;
  while(1){
    u = Q.front(); Q.pop();
    if ( u.x == gx && u.y == gy && u.b == gb ) return u.c;
    rep(r, 3){
      v = getNext(u, r);
      if ( !vis[v.x][v.y][v.b][v.r] ){
	vis[v.x][v.y][v.b][v.r] = true;
	v.c = u.c + 1;
	Q.push(v);
      }
    }
  }
}

main(){
  int gx, gy, gb;
  while(1){
    cin >> gx >> gy >> gb;
    if ( gx == 0 && gy == 0 && gb == 0 ) break;
    gx += SHIFT;
    gy += SHIFT;
    cout << bfs(gx, gy, gb) << endl;
  }
}
