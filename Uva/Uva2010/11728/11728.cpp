// 11728:Alternate Task:1.0:Factors, Math
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

void factorize( int x, set<int> &factors ){
  factors.insert(x);
  factors.insert(1);
  if ( x == 1 ) return;
    int d, q;
    while ( x >= 4 && x % 2 == 0 ) {
	factors.insert(2);
	x /= 2;
    }
    d = 3; q = x / d;
    while ( q >= d ){
	if ( x % d == 0 ) { factors.insert(d); x = q; }
	else d += 2;
	q = x / d;
    }
    factors.insert(x);

}

int compute(int n){
  int ans = -1;
  for ( int i = 1; i <= n; i++ ){
    int sum = 0;
    for ( int j = 1; j <= i; j++ ){
      if ( i % j == 0 ) sum += j;
    }
    if ( sum == n ) ans = i;
  }

  return ans;

}

main(){
  int x, t = 1;
  while( cin >> x && x ) {
    cout << "Case " << t++ << ": " << compute(x) << endl;
  }
}
