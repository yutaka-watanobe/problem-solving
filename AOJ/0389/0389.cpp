#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++ )
static const int N_MAX = 100000;
static const int NINF = -1000000000;
int N, P[N_MAX], ans;
int dp[N_MAX][3]; // 0:1p, 1:0p, 2:2p
vector<int> T[N_MAX];
bool V[N_MAX];

void dfs(int u){
  V[u] = true;
  vector<int> C;
  rep (i, T[u].size()){
    int v = T[u][i];
    if ( !V[v] ) {
      C.push_back(v);
      dfs(v);
    }
  }
  // 子Cが全て訪問・決定済み

  if ( C.size() == 0 ){
    rep(i, 3) dp[u][i] = P[u]; // 葉の場合はノードの得点
  } else if ( C.size() == 1 ){
    int v = C[0];
    dp[u][0] = max(dp[v][0] - 1 + P[u], P[u]); //
    dp[u][1] = max(dp[v][1] - 2 + P[u], P[u]); //
    dp[u][2] = max(dp[v][2] - 2 + P[u], P[u]); //


    //    dp[u][0] = max(dp[u][0], dp[v][1] - 2 + P[u]); // not need
    //    dp[u][2] = max(dp[u][2], dp[v][1] - 2 + P[u]); // not need
    //    dp[u][2] = max(dp[u][2], dp[v][0] - 1 + P[u]); // not need
  } else {
    int a1, a2, c1; // candidate child
    a1 = a2 = c1 = C[0];
    rep (i, C.size()){
      int v = C[i];
      if ( dp[a1][0] - 1 - max(dp[a1][1] -  2, 0) <= dp[v][0] - 1 - max(dp[v][1] - 2, 0) ) a1 = v;
      if ( dp[c1][2] - 2 - max(dp[c1][1] -  2, 0) <= dp[v][2] - 2 - max(dp[v][1] - 2, 0) ) c1 = v;
    }
    rep(i, C.size()) if ( C[i] != a1 ) { a2 = C[i]; break; }
    rep(i, C.size()){
      int v = C[i];
      if ( v == a1 ) continue;
      if ( dp[a2][0] - 1 - max(dp[a2][1] -  2, 0) <= dp[v][0] - 1 - max(dp[v][1]  - 2, 0) ) a2 = v;
    }
    int sumA1 = 0; // bbbbab
    int sumB1 = 0; // bbbbbb
    int sumC1 = 0; // bbbcbb
    int sumC2 = 0; // abbabb
    for ( int i = 0; i < C.size(); i++ ){
      int v = C[i];
      sumA1 += (v == a1) ? (dp[v][0] - 1) : max(dp[v][1] - 2, 0);
      sumB1 += max(dp[v][1] - 2, 0);
      sumC1 += (v == c1) ? (dp[v][2] - 2) : max(dp[v][1] - 2, 0);
      sumC2 += (v == a1 || v == a2) ? (dp[v][0] - 1) : max(dp[v][1] - 2, 0);
    }
    //    int sumA = max(sumA1, sumB1);
    int sumA = sumA1;
    //int sumC = max(sumA, max(sumC1, sumC2));
    int sumC = max(sumC1, sumC2);
    int sumB = sumB1;
    dp[u][0] = max(P[u], sumA + P[u]);
    dp[u][1] = max(P[u], sumB + P[u]);
    dp[u][2] = max(P[u], sumC + P[u]);
  }
  rep(i, 3) ans = max(ans, dp[u][i]);
}

int solve(int s){
  rep(i, N) rep(j, 3) dp[i][j] = NINF;
  rep(i, N) V[i] = false;
  ans = NINF;
  dfs(s);
  return ans;
}

int main(){
  cin >> N;
  for ( int i = 0; i < N; i++ ) cin >> P[i];
  for ( int i = 0; i < N - 1; i++ ) {
    int s, t; cin >> s >> t;
    s--; t--;
    T[s].push_back(t);
    T[t].push_back(s);
  }

  int a = solve(0);
  //  for ( int i = 0; i < N; i++ ) assert(a == solve(i)); // safety check
  cout << a << endl;

  return 0;
}

