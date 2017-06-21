#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)

static const int MAX = 22;
static const double EPS = 1e-8;

double T[MAX][MAX], dp[MAX][MAX+1];
int P[MAX][MAX+1], n;

void makePath(vector<int> &v, int i, int j){
  v.push_back(i+1);
  if ( j == 0 ) return;
  makePath(v, P[i][j], j-1);
}

vector<int> solve(int s){
  vector<int> v;
  rep(i, n) rep(j, n) dp[i][j] = 0.0;
  rep(i, n) dp[i][0] = T[s][i];

  REP(j, 1, n) rep(i, n){
    rep(k, n){ // k --> i
      double v = dp[k][j-1]*T[k][i];
      if ( dp[i][j] < v ){
	dp[i][j] = v;
	P[i][j] = k;
      }
    }
  }

  REP(j, 1, n) if ( dp[s][j] > 1.01 ){
      makePath(v, s, j);
      return v;
  }

  return v;
}

main(){
  while( cin >> n ) {
    rep(i, n) rep(j, n){
      if ( i == j ) T[i][j] = 1.0;
      else cin >> T[i][j];
    }

    vector<int> ans(MAX+1), v;

    rep(s, n){
      v = solve(s);
      if ( v.size() < 2 ) continue;
      if ( v.size() < ans.size() ) ans = v;
    }

    if ( ans.size() == MAX+1 ) {
      cout << "no arbitrage sequence exists" << endl;
    } else {
      ans.push_back(ans[0]);
      reverse(ans.begin(), ans.end());
      rep(i, ans.size()){
	if ( i ) cout << " ";
	cout << ans[i];
      }
      cout << endl;
    }
  }
}
