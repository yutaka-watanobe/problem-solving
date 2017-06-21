#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)
#define INFTY (1<<21)

#define MAX 120

void floyd(int D[MAX][MAX], int n){
  rep(k, n) rep(i, n) rep(j, n){
    if ( D[i][k] == INFTY ) continue;
    if ( D[k][j] == INFTY ) continue;
    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
  }
}

int compute(){
  int D[MAX][MAX];
  int n, m, s, t;
  cin >> n >> m;
  rep(i, n) rep(j, n) D[i][j] = INFTY;
  
  rep(i, m){
    cin >> s >> t;
    D[s][t] = D[t][s] = 1;
  }
  floyd(D, n);
  int maxv = 0;
  for ( int i = 0; i < n-1; i++ ){
    for ( int j = i+1; j < n; j++ ){
      maxv = max(maxv, D[i][j] );
    }
  }
  return maxv;
}

main(){
  int tcase; cin >> tcase;
  rep(t, tcase) {
    cout << "Case #" << t+1 << ": " << compute() << endl;
  }
}
