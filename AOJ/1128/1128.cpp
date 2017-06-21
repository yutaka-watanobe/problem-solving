#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i, b, e) for ( int i = b; i <= e; i++ )
#define rep(i, n) for ( int i = 0; i < (int)n; i++)
#define MAX 10

int cnt, H, W, limit, maxw;
int T[MAX][MAX], K[MAX][MAX], C[MAX][MAX], X[MAX][MAX];
vector<pair<int, int> > v;

int MD(){
  int sum = 0;
  rep(i, H) rep(j, W){
    if ( C[i][j] && X[i][j] == 0 ) sum++;
  }
  return sum/(maxw*maxw);
}

bool dfs(int pos, int cost){
  bool solved = true;
  rep(i, H) rep(j, W) if ( C[i][j] && X[i][j] == 0 ) solved = false;
  if ( solved ) return true;
  if ( pos >= v.size() ) return false;
  if ( cost + MD() >= limit ) return false;

  for ( int i = v[pos].first+1; i < H; i++ ) rep(j, W){
      if ( C[i][j] && X[i][j] == 0 ) return false;
    }

  int tmp[MAX][MAX];

  if ( dfs(pos+1, cost) ) return true;

  rep(i, H) rep(j, W) tmp[i][j] = X[i][j];
  int pi = v[pos].first;
  int pj = v[pos].second;
  int w = T[pi][pj];
  FOR(y, pi-w+1, pi) FOR(x, pj-w+1, pj) X[y][x]++;

  if ( dfs(pos+1, cost+1) ) return true;
  rep(i, H) rep(j, W) X[i][j] = tmp[i][j];

  return false;
}

int idp(){
  if ( maxw == 0 ) return 0;
  for ( limit = MD(); limit < 100; limit++){
    if ( dfs(0, 0) ) return limit;
  }
}

void compute(){

  bool U[MAX][MAX], V[MAX][MAX];

  rep(i, H) rep(j, W) U[i][j] = true;
  rep(i, H) rep(j, W) V[i][j] = false;
  rep(i, H) rep(j, W) T[i][j] = K[i][j] = X[i][j] = 0;
  rep(i, H) T[i][0] = (C[i][0])?1:0;
  rep(j, W) T[0][j] = (C[0][j])?1:0;

  FOR(i, 1, H-1) FOR(j, 1, W-1){
    if ( C[i][j] ){
      T[i][j] = min(T[i-1][j-1], min(T[i-1][j], T[i][j-1])) +1;
    } else T[i][j] = 0;
  }

  rep(i, H) rep(j, W){
    int w = T[i][j];
    FOR(pi, i-(w-1), i) FOR(pj, j-(w-1), j) {
      if ( i == pi && j == pj ) continue;
      int l = max(i-pi, j-pj);
      if ( w-l >= T[pi][pj] ) U[pi][pj] = false;
    }
  }

  rep(i, H) rep(j, W){
    if ( U[i][j] && T[i][j] ){
      FOR(y, i-T[i][j]+1, i) FOR(x, j-T[i][j]+1, j) K[y][x]++;
    }
  }

  v.clear();
  rep(i, H) rep(j, W){
    if ( U[i][j] && T[i][j] ){
      bool f = false;
      FOR(y, i-T[i][j]+1, i) FOR(x, j-T[i][j]+1, j){
	if ( K[y][x] == 1 ) f = true;
      }
      if ( f ){
	FOR(y, i-T[i][j]+1, i) FOR(x, j-T[i][j]+1, j) X[y][x]++;
	cnt++;
	T[i][j] = 0;
      }
    }
  }
  maxw = 0;
  rep(i, H) rep(j, W){
    if ( T[i][j] > 0 && U[i][j]){
      maxw = max(maxw, T[i][j]);
      v.push_back(make_pair(i, j));
    }
  }

  reverse(v.begin(), v.end());
}

main(){
  while( cin >> W >> H ){
    if ( W == 0 && H == 0 ) break;
    rep(i, H) rep(j, W) cin >> C[i][j];
    cnt = 0;
    compute();
    cout << idp() + cnt << endl;
  }
}

