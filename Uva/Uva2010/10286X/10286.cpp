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
  double l, h, s, B, C;
  B = 120.0*acos(-1)/180;
  C = 45.0*acos(-1)/180;
  while( cin >> l ){
    printf("%.10lf\n", l*sin(B)/sin(C));
  }
}
