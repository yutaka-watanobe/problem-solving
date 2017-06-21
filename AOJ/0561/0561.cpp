#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<string>
#include<vector>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)

static const int NMAX = 2005;
static const int KMAX = 12;

int dp[KMAX+1][NMAX+1]; // max score when we sell j books of genre k
int T[KMAX+1][NMAX+1]; // max score of n books of genre k
vector<int> G[KMAX];

main(){
  int N, K;
  cin >> N >> K;
  rep(i, KMAX+1) rep(j, K+1) dp[i][j] = T[i][j] = 0;
  rep(i, N){
    int c, g; cin >> c >> g;
    G[g].push_back(c);
  }
  
  REP(i, 1, 11){
    sort(G[i].begin(), G[i].end(), greater<int>());
    for ( int j = 0; j < G[i].size(); j++ ){
      T[i][j+1] = T[i][j] + G[i][j];
    }
    for ( int j = 0; j < G[i].size(); j++ ){
      T[i][j+1] += j*(j+1);
    }
    }

  REP(k, 1, 11){
    REP(j, 1, K+1){
      for ( int l = 1; T[k][l]; l++ ){
	if ( j - l >= 0 )
	  dp[k][j] = max(dp[k][j], dp[k-1][j-l] + T[k][l]);
      }
    }
    rep(i, K+1) dp[k+1][i] = dp[k][i];
  }
  
  cout << dp[10][K] << endl;

  return 0;
}
