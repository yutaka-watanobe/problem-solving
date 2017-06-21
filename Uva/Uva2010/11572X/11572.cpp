#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

void compute(){
  set<int> S;
  int n, x; cin >> n;

  int maxs = 0;

  rep(i, n){
    cin >> x;
    if ( S.find(x) == S.end() ){
      S.insert(x);
    } else {
      maxs = max(maxs, (int)S.size());
      S.clear();
      S.insert(x);
    }
  }
  maxs = max(maxs, (int)S.size());
  cout << maxs << endl;
}

main(){
  int t; cin >> t;
  rep(i, t) compute();
}
