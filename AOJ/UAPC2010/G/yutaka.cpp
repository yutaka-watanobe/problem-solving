#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<cassert>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define MAX 10
#define INFTY (1 << 21)
map<string, int> M;

class Cube{
public:
  string f;
  Cube(){ f = "123456"; }
  void roll_left(){ roll(0, 2, 5, 3);}
  void roll_back(){ roll(0, 1, 5, 4);}
  void roll_right(){ rep(i, 3) roll_left(); }
  void roll_front(){ rep(i, 3) roll_back(); }
  void roll(int i, int j, int k, int l){
    char t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
  }
};

class State{
public:
  int i, j, cost;
  Cube c;
  State(int i=0, int j=0, Cube c=Cube(), int cost=0): i(i), j(j), c(c), cost(cost){}
  bool operator < ( const State &s) const{ return cost > s.cost; }
};

int dijkstra(int H, int W, int G[MAX][MAX], int si, int sj, int gi, int gj){
  Cube s = Cube();
  bool visited[MAX][MAX][24];
  int d[MAX][MAX][24];
  priority_queue<State> PQ;

  rep(i, H) rep(j, W) rep(k, 24){
    visited[i][j][k] = false;
    d[i][j][k] = INFTY;
  }

  PQ.push(State(si, sj, s, 0));
  d[si][sj][M[s.f]] = 0;

  State u, v;
  while(!PQ.empty()){
    u = PQ.top(); PQ.pop();
    if ( u.i == gi && u.j == gj ) return u.cost;
    Cube cube = u.c;
    int c = M[cube.f];
    if ( visited[u.i][u.j][c] ) continue;
    visited[u.i][u.j][c] = true;

    int ni, nj;
    rep(r, 4){
      v = u;
      ni = u.i;
      nj = u.j;
      if ( r == 0 && u.j < W-1 ) { v.c.roll_right(); nj++; }
      if ( r == 1 && u.i >= 1 ) { v.c.roll_back(); ni--; }
      if ( r == 2 && u.j >= 1 ) { v.c.roll_left(); nj--; }
      if ( r == 3 && u.i < H-1) { v.c.roll_front(); ni++; }
      v.i = ni;
      v.j = nj;
      int cost = G[ni][nj] * (v.c.f[5]-'0') + u.cost;
      int nc = M[v.c.f];
      if ( d[ni][nj][nc] > cost ){
	d[ni][nj][nc] = cost;
	v.i = ni;
	v.j = nj;
	v.cost = cost;
	PQ.push(v);
      }
    }
  }
  return -1;
}

void init(){
  string t[24] = {"123456","135246","154326","142536","326154","365214","351624","312564","246135","263415","231645","214365","645231","653421","632541","624351","415263","456123","462513","421653","513462","536142","564312","541632"};
  rep(i, 24) M[t[i]] = i;
}

main(){
  init();
  int H, W, G[MAX][MAX], si, sj, gi, gj;
  while(1){
    cin >> H >> W;
    if ( H == 0 && W == 0 ) break;
    assert( 1 <= H && H <= MAX );
    assert( 1 <= W && W <= MAX );
    rep(i, H) rep(j, W) cin >> G[i][j];
    rep(i, H) rep(j, W) assert( 0 <= G[i][j] && G[i][j] <= 9 );
    cin >> si >> sj >> gi >> gj;
    assert( !(si == gi && sj == gj) );
    assert( 0 <= si && si < H );
    assert( 0 <= sj && sj < W );
    assert( 0 <= gi && gi < H );
    assert( 0 <= gj && gj < W );
    cout << dijkstra(H, W, G, si, sj, gi, gj) << endl;
  }
}
