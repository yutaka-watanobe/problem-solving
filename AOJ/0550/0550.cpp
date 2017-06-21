#include<iostream>
using namespace std;
static const int MAX = 10000;
static const int INFTY = (1<<24);

main(){
  int N, P[MAX], dp[2][MAX/2+1][2]; 
  cin >> N;
  for ( int i = 0; i < N-1; i++ ) cin >> P[i];

  for ( int i = 0; i < 2; i++ ){
    for ( int j = 0; j <= N/2; j++ ){
      dp[i][j][0] = dp[i][j][1] = INFTY;
    }
  }
  dp[1][1][1] = 0;
  dp[1][0][0] = 0;

  for ( int i = 1; i < N; i++ ){
    for ( int j = 0; j <= N/2; j++ ){
      dp[(i+1)%2][j][0] = INFTY;
      dp[(i+1)%2][j+1][1] = INFTY;
      // + 0
      dp[(i+1)%2][j][0] = min(dp[(i+1)%2][j][0], dp[i%2][j][0]);
      dp[(i+1)%2][j][0] = min(dp[(i+1)%2][j][0], dp[i%2][j][1] + P[i-1]);
      // + 1
      if ( j+1 > N/2 ) continue;
      dp[(i+1)%2][j+1][1] = min(dp[(i+1)%2][j+1][1], dp[i%2][j][0] + P[i-1]);
      dp[(i+1)%2][j+1][1] = min(dp[(i+1)%2][j+1][1], dp[i%2][j][1]);
    }
  }
  cout << min(dp[0][N/2][0], dp[0][N/2][1]) << endl;
}
