// 11364:Optimal Parking:0.5:Writing
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

void compute(){
  int n, x;
  int minv = (1<<21);
  int maxv = 0;
  cin >> n;
  rep(i, n){
    cin >> x;
    minv = min(minv, x);
    maxv = max(maxv, x);
  }

  cout << 2*(maxv-minv) << endl;
}

main(){
  int t; cin >> t;
  rep(i, t ) compute();
}
