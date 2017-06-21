#include<iostream>
#include<vector>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)
static const int MAX = 100;
main(){
  int N, k; 
  bool T[MAX][MAX], C[MAX];
  while(1){
    cin >> N;
    if ( N == 0 ) break;
    rep(i, N) rep(j, N) T[i][j] = C[i] = false;
    rep(i, N){
      cin >> k;
      rep(s, k) {
	int j; cin >> j; j--;
	T[i][j] = true;
      }
    }
    cin >> k;
    rep(i, k){
      int j; cin >> j; j--;
      C[j] = true;
    }
    vector<int> ans;
    rep(i, N){
      bool suc = true;
      rep(j, N){
	if ( C[j] && !T[i][j] ) suc = false;
      }
      if ( suc ) ans.push_back(i+1);
    }

    if ( ans.size() == 1 ) cout << ans[0] << endl;
    else cout << -1 << endl;
  }
}
