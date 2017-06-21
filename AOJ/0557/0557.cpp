#include<iostream>
#include<algorithm>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)
typedef long long llong;

static const int MAX = 101;
main(){
  int n; 
  llong T[MAX], dp[21][MAX];
  cin >> n;

  rep(i, n) cin >> T[i];
  rep(i, 21) rep(j, n) dp[i][j] = 0;

  if ( 0 <= T[0] && T[0] <= 20 ) dp[T[0]][0] = 1;

  int p1, p2;
  for ( int j = 1; j < n-1; j++ ){
    for ( int i = 0; i <= 20; i++ ){      
      p1 = i + T[j];
      if ( p1 <= 20 ) dp[p1][j] += dp[i][j-1];
      p2 = i - T[j];
      if ( p2 >= 0 ) dp[p2][j] += dp[i][j-1];
    }
  }
  cout << dp[T[n-1]][n-2] << endl;
}
