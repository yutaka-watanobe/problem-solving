#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)
static const int DMAX = 200;
static const int NMAX = 200;
static const int INPOS = -1;

main(){
  int D, N, T[DMAX+1], C[NMAX+1], dp[NMAX+1][DMAX+1];
  pair<int, int> AB[NMAX+1];
  cin >> D >> N;
  rep(i, D) cin >> T[i+1]; // +1 for 1 base
  rep(i, N) cin >> AB[i+1].first >> AB[i+1].second >> C[i+1];
  rep(i, N+1) rep(j, D+1) dp[i][j] = INPOS;
  
  REP(i, 1, N+1)
    if ( AB[i].first <= T[1] && T[1] <= AB[i].second ) dp[i][1] = 0;

  REP(j, 2, D+1){
    REP(i, 1, N+1){
      if ( !( AB[i].first <= T[j] && T[j] <= AB[i].second) ) continue;
      REP(k, 1, N+1){
	if ( dp[k][j-1] == INPOS ) continue;
	dp[i][j] = max(dp[i][j], dp[k][j-1] + abs(C[k] - C[i]));
      }
    }
  }

  int ans = 0;
  REP(i, 1, N+1) ans = max(ans, dp[i][D]);
  cout << ans << endl;
}

