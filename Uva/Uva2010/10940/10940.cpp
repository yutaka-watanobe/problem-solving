// 10940:Throwing cards away II:2.0:Josephus Problem
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

int power(int p, int n){
  int s = 1;
  for ( int i = 0; i < n; i++ ) s *= p;
  return s;
}
main(){
  int n;
  while ( cin >> n && n ){
    if ( n == 1 ) cout << 1 << endl;
    else cout << 2*n - power(2, 1+(int)(log2(n)-0.0000001)) << endl;
  }
}
