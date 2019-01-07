/*
dp[i][j] = 星0～iの入り口jから入れる累計数
dp[j]に省略可能 yutaka2
*/
#include <iostream>
using namespace std;
const int M = 1000000007;
const int N_MAX = 100000;

int n, dp[N_MAX+1][26];
string s, t;

int main() {
  cin >> n;
  cin >> s >> t;

  dp[0][s[0]-'a'] = 1;

  for ( int i = 1; i < n; i++ ){
    dp[i][s[i]-'a'] = (dp[i][s[i]-'a'] + dp[i-1][t[i]-'a']) % M;
    for ( int j = 0; j < 26; j++ ) dp[i][j] = (dp[i][j] + dp[i-1][j]) % M;
  }

  cout << dp[n-2][t[n-1]-'a'] << endl;

  return 0;
}


