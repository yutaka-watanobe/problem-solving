#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++)
#define MAX 10


int cnt, H, W;
int T[MAX][MAX], K[MAX][MAX];
int C[MAX][MAX];
int X[MAX][MAX];
int limit;
int maxw;

int MD(){
  int sum = 0;
  rep(i, H) rep(j, W){
    if ( C[i][j] && X[i][j] == 0 ) sum++;
  }
  return sum/(maxw*maxw);
}

bool valid(vector<pair<int, int> > &v){
  rep(i, v.size()){
    bool val = false;
    int pi = v[i].first;
    int pj = v[i].second;
    int w = T[pi][pj];
    for ( int y = pi; y >= pi-w+1; y-- ){
      for ( int x = pj; x >= pj-w+1; x--){
	if ( X[y][x] <= 1 ) { val = true; break;}
      }
    }
    if( !val) return false;
  }
  return true;
}

bool dfs(vector<pair<int, int> > &v, int pos, int cost){
  bool solved = true;
  rep(i, H) rep(j, W) if ( C[i][j] && X[i][j] == 0 ) solved = false;
  if ( solved ) return true;

  if ( pos >= v.size() ) return false;

  if ( cost + MD() >= limit ) return false;
  //   if ( md > v.size()-pos) return false;
  if ( !valid(v) ) return false;

  int si = v[pos].first+1;
  for ( int i = si; i < H; i++ ) rep(j, W){
      if ( C[i][j] && X[i][j] == 0 ) return false;
  }


  int tmp[MAX][MAX];

  if ( dfs(v, pos+1, cost) ) return true;

  rep(i, H) rep(j, W) tmp[i][j] = X[i][j];
  int pi = v[pos].first;
  int pj = v[pos].second;
  int w = T[pi][pj];
  for ( int y = pi; y >= pi-w+1; y-- ){
    for ( int x = pj; x >= pj-w+1; x--){
      X[y][x]++;
    }
  }
  if ( dfs(v, pos+1, cost+1) ) return true;
  rep(i, H) rep(j, W) X[i][j] = tmp[i][j];

  return false;
}

int idp(vector<pair<int, int> > v){
  reverse(v.begin(), v.end());
  if ( maxw == 0 ) return 0;
  for ( limit = MD(); limit < 100; limit++){
    if ( dfs(v, 0, 0) ) return limit;
  }
}

vector<pair<int, int> > compute(){
  
  bool U[MAX][MAX];
  bool V[MAX][MAX];

  rep(i, H) rep(j, W) U[i][j] = true;
  rep(i, H) rep(j, W) V[i][j] = false;
  rep(i, H) rep(j, W) T[i][j] = K[i][j] = X[i][j] = 0;
  rep(i, H) T[i][0] = (C[i][0])?1:0;
  rep(j, W) T[0][j] = (C[0][j])?1:0;
  for ( int i = 1; i < H; i++ ){
    for ( int j = 1; j < W; j++ ){
      if ( C[i][j] ){
	T[i][j] = min(T[i-1][j-1], min(T[i-1][j], T[i][j-1])) +1;
      } else T[i][j] = 0;
    }
  }

  rep(i, H) rep(j, W){
    int w = T[i][j];
    for ( int pi=i; pi >= i-(w-1); pi--){
      for ( int pj=j; pj >= j-(w-1); pj--){
	if ( i == pi && j == pj ) continue;
	int l = max(i-pi, j-pj);
	if ( w-l >= T[pi][pj] ) U[pi][pj] = false;
      }
    }
  }

  rep(i, H) rep(j, W){
    if ( U[i][j] && T[i][j] ){
      for ( int y = i; y >= i-T[i][j]+1; y--){
	for ( int x = j; x >= j-T[i][j]+1; x--) K[y][x]++;
      }
    }
  }

  vector<pair<int, int> > v;
  rep(i, H) rep(j, W){
    if ( U[i][j] && T[i][j] ){
      bool f = false;
      for ( int y = i; y >= i-T[i][j]+1; y--){
      	for ( int x = j; x >= j-T[i][j]+1; x--) {
      	  if ( K[y][x] == 1 ) f = true;
      	}
      }
      if ( f ){
	for ( int y = i; y >= i-T[i][j]+1; y--){
	  for ( int x = j; x >= j-T[i][j]+1; x--) {
	    X[y][x]++;
	  }
	}
	cnt++;
	T[i][j] = 0;
      }
    }
  }
  maxw = 0;
  rep(i, H) rep(j, W){
    if ( T[i][j] > 0 && U[i][j])maxw = max(maxw, T[i][j]);
  }
  rep(i, H) rep(j, W){
    if ( U[i][j] && T[i][j] ){
      v.push_back(make_pair(i, j));
    }
 }

  return v;
}



main(){
  while( cin >> W >> H ){
    if ( W == 0 && H == 0 ) break;
    rep(i, H) rep(j, W) cin >> C[i][j];
    cnt = 0;
    cout << idp( compute()) + cnt << endl;
  }
}

