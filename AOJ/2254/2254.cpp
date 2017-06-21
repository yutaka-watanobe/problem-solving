#include<iostream>
#include<algorithm>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)
static const int NMAX = 16;
main(){
  int N, T[NMAX][NMAX+1], dp[(1<<NMAX)];
  while( cin >> N, N){
    rep(i, N) REP(j, 0, N+1) cin >> T[i][j];
    rep(i, (1<<N)) dp[i] = (1<<25);
    dp[0] = 0;
    rep(s, (1<<N)){
      rep(i, N){
	int next = s | (1<<i);
	if ( next >= (1<<N) ) continue;
	int cost = T[i][0];
	REP(j,1, N+1){
	  if ( s&(1<<(j-1)) ) cost = min(cost, T[i][j]);
	}
	dp[next] = min(dp[next], dp[s] + cost);      
      }
    }
    cout << dp[(1<<N)-1] << endl;
  }
}

