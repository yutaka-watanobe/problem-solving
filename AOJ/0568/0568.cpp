#include<iostream>
#include<algorithm>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)
static const int M = 10000;
static const int NMAX = 100;

main(){
  int N, K, A, B;
  int dp[NMAX+1][3][2], T[NMAX+1];

  cin >> N >> K;

  rep(i, N+1) rep(j, 3) rep(k, 2) dp[i][j][k] = 0;
  rep(i, N+1) T[i] = -1;

  rep(i, K){
    cin >> A >> B;
    B--; // 0, 1, 2
    T[A] = B;
  }
  
  // init
  if ( T[1] >= 0 ){
    dp[1][T[1]][1] = 1;
  } else {
    rep(j, 3) dp[1][j][0] = 1;
  }

  for ( int i = 2; i <= N; i++ ){
    rep(s, 3){
      rep(j, 3){
	if ( T[i] >= 0 && j != T[i] ) continue;
	
	if ( s != j ){
	  dp[i][j][0] = (dp[i][j][0] + dp[i-1][s][0])%M;
	  dp[i][j][0] = (dp[i][j][0] + dp[i-1][s][1])%M;
	} else {
	  dp[i][j][1] = (dp[i][j][1] + dp[i-1][s][0])%M;
	}
      }
    }
  }

  int sum = 0;
  rep(j, 3) rep(k, 2) sum = (sum + dp[N][j][k])%M;

  cout << sum << endl;
}
