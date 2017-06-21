// 11538:Chess Queen:2.5:Math, Numerical Sequence
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


main(){
  llong N, M, a, b;
  while( cin >> a >> b && a && b ){
    N = max(a, b);
    M = min(a, b);
    llong s = 0, d=0;
    s += M*N*(N-1)/2;
    s += N*M*(M-1)/2;
    llong n = M-1;
    d += N*M*(M-1)/2 - n*(n+1)*(n+2)/6;
    d *= 2;

    //    cout << "s=" << s << endl;
    //    cout << "d=" << d << endl;
    cout << (s+d)*2 << endl;
  }
}
