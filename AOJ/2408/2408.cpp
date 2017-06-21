#include<iostream>
#include<algorithm>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)
static const int MAX = 50;

main(){
  int N, K, R;
  int aff[MAX];
  bool angly[MAX];
  cin >> N >> K;
  rep(i, N) angly[i] = false;
  rep(i, K){
    int m, u; cin >> m;
    rep(j, m){
      cin >> u; u--;
      aff[u] = i;
    }
  }

  cin >> R;
  rep(i, R){
    int p, q; cin >> p >> q;
    p--; q--;
    if ( aff[p] == aff[q] ) {
      angly[p] = angly[q] = true;
    }
  }
  int cnt = 0;
  rep(i, N) if ( angly[i] ) cnt++;
  cout << cnt << endl;

}
