#include<iostream>
#include<string>
#include<queue>

using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define MAX 18
#define INFTY (1<<20)

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};

char M[MAX][MAX];
int C[256], U[256];
bool V[MAX][MAX];
int I[MAX][MAX];
int D[MAX][MAX][MAX][MAX];

int ncomponent;
int limit;

int H, W, sy, sx, gy, gx;

bool valid(int ny, int nx){
  return ( ny >= 0 && nx >= 0 && ny < H && nx < W );
}
void init(){
  for ( int i = 0; i < 256; i++ ) C[i] = 0;
}
void init2(){
  for ( int i = 0; i < 256; i++ ) U[i] = 0;
  for ( int i = 0; i < H; i++ ){
    for ( int j = 0; j < W; j++ ){
      V[i][j] = false;
    }
  }
}
bool dfs(int py, int px , int depth){
  if ( py == gy && px == gx ) return true;
  //if ( depth >= limit ) return false;
  if ( depth + D[py][px][gy][gx] > limit ) return false;

  int nx, ny;
  for ( int r = 0; r < 4; r++ ){
    ny = py + dy[r];
    nx = px + dx[r];
    if ( ny < 0 || nx < 0 || ny >= H || nx >= W ) continue;
    if ( M[ny][nx] == '#' || V[ny][nx] ) continue;
     
    if (M[ny][nx] != '.' ){
      if ( !(U[I[ny][nx]] >= C[I[ny][nx]]/2) ){
	V[ny][nx] = true;
	U[I[ny][nx]]++;
	if ( dfs(ny, nx, depth+1) ) return true;
	V[ny][nx] = false;
	U[I[ny][nx]]--;
      }
    } else {
      V[ny][nx] = true;
      if ( dfs(ny, nx, depth+1) ) return true;
      V[ny][nx] = false;
    }
  }
  return false;
}

int solve(){
  for ( limit = 0; limit < H*W; limit++ ){
    init2();
    if ( dfs(sy, sx, 0) ){
      return limit;
    }
  }
  return -1;
}

void parse(int y, int x, int id, int &area){
  I[y][x] = id;
  area++;
  int ny, nx;
  for ( int r = 0; r < 4; r++ ){
    ny = y + dy[r];
    nx = x + dx[r];
    if ( !valid(ny, nx) ) continue;
    if ( M[ny][nx] != 'X' ) continue;
    if ( I[ny][nx] != -1 ) continue;
    parse(ny, nx, id, area);
  }
}

int bfs(int psy, int psx, int pgy, int pgx){
  queue<pair<int, int>  > Q;
  int d[MAX][MAX];
  rep(i, H) rep(j, W) d[i][j] = INFTY;
  d[psy][psx] = 0;
  Q.push(make_pair(psy, psx));
  
  pair<int, int> u, v;
  while( !Q.empty() ){
    u = Q.front(); Q.pop();
    if ( u.first == pgy && u.second == pgx ) return d[pgy][pgx];
    int ny, nx;
    for ( int r = 0; r < 4; r++ ){
      ny = u.first + dy[r];
      nx = u.second + dx[r];
      if ( !valid(ny, nx) ) continue;
      if ( M[ny][nx] == '#' ) continue;
      if ( d[ny][nx] != INFTY ) continue;
      d[ny][nx] = d[u.first][u.second] + 1;
      Q.push(make_pair(ny, nx));
    }
  }
  return INFTY;
}
void makeTable(){
  ncomponent = 0;
  rep(i, H) rep(j, W) I[i][j] = -1;
  rep(i, H) rep(j, W){
    if ( M[i][j] == 'X' && I[i][j] < 0) {
      int area = 0;
      parse(i, j, ncomponent, area);
      C[ncomponent] = area;
      ncomponent++;
    }
  }
  for ( int a = 0; a < H*W-1; a++){
    for ( int b = a+1; b < H*W; b++ ){
      D[a/W][a%W][b/W][b%W] = D[b/W][b%W][a/W][a%W] = bfs(a/W, a%W, b/W, b%W);
    }
  }
}

main(){
  while(1){
    cin >> W >> H;
    if ( H == 0 && W == 0 ) break;
    init();
    for ( int i = 0; i < H; i++ ){
      for ( int j = 0; j < W; j++ ){
	cin >> M[i][j];
	if ( M[i][j] == 'S' ) {
	  sy = i; sx = j;
	  M[i][j] = '.';
	} else if ( M[i][j] == 'G' ){
	  gy = i; gx = j;
	  M[i][j] = '.';
	}
      }
    }
    makeTable();
    cout << solve() << endl;
  }
}

