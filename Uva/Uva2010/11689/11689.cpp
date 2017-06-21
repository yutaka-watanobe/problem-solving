// 11689:Soda Surpler:1.0:Simulation
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

void compute(){
  int e, f, c, s =0, r, x;
  cin >> e >> f  >> c;
  e += f;
  while(1){
    if ( e < c ) break;
    x = e/c;
    s += x;
    e = e%c + x;
  }
  cout << s << endl;
}

main(){
  int tcase; cin >> tcase;
  rep(t, tcase) compute();
}
