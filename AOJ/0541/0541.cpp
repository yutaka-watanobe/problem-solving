/**
 * DP
 * first, find the number of visit for each node about N-1 th
 */
#include<iostream>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)

static const int MAX = 1001;

main(){
  int H, W, N, D[MAX][MAX], dp[MAX][MAX], k;
  
  while(1){
    cin >> H >> W >> N;
    if ( H == 0 && W == 0 && N == 0) break;
    rep(i, H) rep(j, W) {
      cin >> D[i][j];
      dp[i][j] = 0;
    }
    
    dp[0][0] = N-1;
    rep(i, H) rep(j, W) {
      if ( i ){
	k = dp[i-1][j];
	if ( k % 2 == 0 ){
	  dp[i][j] += dp[i-1][j]/2;
	} else {
	  if ( D[i-1][j] == 0 ) dp[i][j] += (dp[i-1][j] + 1)/2;
	  else dp[i][j] += (dp[i-1][j] - 1)/2;
	}
      } 
      if ( j ){
	k = dp[i][j-1];
	if ( k % 2 == 0 ){
	  dp[i][j] += dp[i][j-1]/2;
	} else {
	  if ( D[i][j-1] == 1 ) dp[i][j] += (dp[i][j-1] + 1)/2;
	  else dp[i][j] += (dp[i][j-1] - 1)/2;
	}
      }
    }

    int pi, pj;
    pi = pj = 0;
    while(1){
      if ( pi == H || pj == W ) break;
      if ( (dp[pi][pj] + D[pi][pj]) % 2 == 1 ) pj++;
      else pi++;
    }

    cout << pi+1 << " " << pj+1 << endl;

  }
}
