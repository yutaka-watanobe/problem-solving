// 10714:Ants:2.0: Max-Max, Min-Max
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

main(){
  int tcase; cin >> tcase;
  int l, n, minv, maxv, p;
  rep(t, tcase){
    cin >> l >> n;
    minv = 0;
    maxv = 0;
    rep(t, n){
      cin >> p;
      minv = max(minv, max(l-p, p));
      maxv = max(maxv, min(l-p, p));
    }
    cout << maxv << " " << minv << endl;
  }
}
