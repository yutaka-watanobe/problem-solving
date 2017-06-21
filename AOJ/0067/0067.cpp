#include<iostream>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define N 12

void dfs(int i, int j, char G[N][N] ){
  G[i][j] = '0';
  static const int di[4] = {0, -1, 0, 1};
  static const int dj[4] = {1, 0, -1, 0};
  int ni, nj;
  rep(r, 4){
    ni = i + di[r];
    nj = j + dj[r];
    if ( ni < 0 || nj < 0 || ni >= N || nj >= N ) continue;
    if ( G[ni][nj] == '0' ) continue;
    dfs(ni, nj, G);
  }
}

int compute(char G[N][N] ){
  int cnt = 0;
  rep(i, N) rep(j, N){
    if ( G[i][j] == '1' ) {
      cnt++;
      dfs(i, j, G);
    }
  }
  return cnt;
}

main(){
  char G[N][N];
  while( cin >> G[0][0] ){
    for ( int j = 1; j < N; j++ ) cin >> G[0][j];
    for ( int i = 1; i < N; i++ ) rep(j, N) cin >> G[i][j];
    cout << compute(G) << endl;
  }
}
