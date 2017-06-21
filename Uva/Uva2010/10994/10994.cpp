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

llong compute(llong p, llong q){
  llong a = p;
  llong b = q;
  while( a % 10 ) a++;
  while( b % 10 ) b--;

  llong aa = a;
  llong bb = b;
  
  a /= 10;
  b /= 10;

  llong n = b - a + 1;
  llong ans = (b-a)*45 + n*(2*a + (n-1))/2;
  
  //  for ( llong i = p; i <= aa; i++ ) ans += (i%10);
  //  for ( llong i = bb; i <= q; i++ ) ans += (i%10);
    
  return ans;

}

main(){
  llong p, q;
  while(1){
    cin >> p >> q;
    if ( p < 0 && q < 0 ) break;
    cout << compute(p, q) << endl;
  }
}
