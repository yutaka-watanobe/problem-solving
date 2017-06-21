// 11231:Black and white painting:1.5:Math, Count
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

llong even(int x){
  if ( x < 8 ) return 0;
  return (x-8)/2 + 1;
}

llong odd(int x){
  if ( x < 9 ) return 0;
  return (x-9)/2 + 1;
}

main(){
  llong r, c, b, sum;
  while(1){
    cin >> r >> c >> b;
    if ( r == 0 && c == 0 && b == 0 ) break;
    if ( b ){
      sum = even(c)*even(r) + even(c-1)*even(r-1);
    } else {
      sum = odd(c)*even(r) + even(c)*odd(r);
    }
    cout << sum << endl;
  }
}
