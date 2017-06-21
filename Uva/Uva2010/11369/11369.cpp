// 11369:Shopaholic:1.0:Sort
// you need 3 items to be discounted
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

typedef long long llong;

#define MAX 20000

void compute(){
  llong n, P[MAX+3];
  cin >> n;
  rep(i, n) cin >> P[i];
  sort( P, P + n );
  reverse(P, P+n);
  while( n % 3 != 0 ){
    P[n] = 0;//P[n-1];
    n++;
  }
  llong sum = 0;
  //  rep(i, n) cout << P[i] << " ";
  //  cout << endl;

  for ( int i = 0; i < n; i+=3 ){
    sum += P[i+2];
  }
  cout << sum << endl;
}

main(){
  int t; cin >> t;
  rep(i, t) compute();
}
