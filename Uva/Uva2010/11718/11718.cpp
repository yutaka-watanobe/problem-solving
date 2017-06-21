// 11718:Fantasy of a Summation:1.5:Power
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

typedef long long llong;

#define MAX 1000

llong power(llong x, llong n, llong m){
  llong tmp = 1;
  if( n > 0 ){
    tmp = power(x, n/2, m);
    tmp = (n%2)?(((tmp*tmp)%m)*x)%m:(tmp*tmp)%m;
  }
  return tmp;
}

main(){
  int tcase; cin >> tcase;
  llong n, k, m, A[MAX], sum;
  rep(t, tcase){
    cin >> n >> k >> m;
    rep(i, n) cin >> A[i];
    sum = 0;
    llong base = (power(n, k-1, m)*k)%m;

    rep(i, n){
      sum = (sum + (A[i]*base)%m)%m;
    }

    cout << "Case " << t+1 << ": " << sum << endl;
  }
}
