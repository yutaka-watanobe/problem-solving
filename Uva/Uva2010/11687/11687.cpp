// 11687:Digits:1.5:Simulation
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

int getDigit(int x){
  int c = 0;
  while( x ){
    x /= 10;
    c++;
  }
  return c;
}

main(){
  string x0;
  int x, i;
  while(1){
    cin >> x0;
    if ( x0 == "END" ) break;
    x = x0.size();
    i = 1;
    while(1){
      if ( x == 1 ) { break; }
      x = getDigit(x);
      i++;
    }
    if ( x0 == "1" ) cout << 1 << endl;
    else cout << i+1 << endl;
  }
}

