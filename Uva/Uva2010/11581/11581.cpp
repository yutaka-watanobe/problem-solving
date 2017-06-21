// 11581:Grid Successors:1.0:Grid simulation
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

#define N 3
#define MAX  (1<<9)

int getValue(int G[N][N]){
  int v = 0, p = 1;
  rep(i, N) rep(j, N){
    v += G[i][j]*p;
    p *= 2;
  }
  return v;
}

void transform(int G[N][N]){
  int T[N][N];
  rep(i, N) rep(j, N) T[i][j] = 0;
  static const int di[4] = {0, -1, 0, 1};
  static const int dj[4] = {1, 0, -1, 0};
  int ni, nj;
  rep(i, N) rep(j, N){
    rep(r, 4){
      ni = i + di[r];
      nj = j + dj[r];
      if ( ni < 0 || nj < 0 || ni >= N || nj >= N ) continue;
      if ( G[ni][nj] ) T[i][j]++;
    }
  }
  rep(i, N) rep(j, N){
    G[i][j] = T[i][j]%2;
  }
}

void compute(){
  int G[N][N];
  bool V[MAX];
  char ch;
  rep(i, N) rep(j, N){
    cin >> ch; G[i][j] = ch-'0';
  }
  rep(i, MAX ) V[i] = false;
  V[getValue(G)] = true;

  int cnt = 0;
  while(1){
    transform(G);
    if ( V[getValue(G)] ) break;
    V[getValue(G)] = true;
    cnt++;
  }
  
  cout << cnt-1 << endl;
}

main(){
  int t; cin >> t;
  rep(i, t) compute();
}
