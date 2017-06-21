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

#define MAX 100

void compute(){
  int P, Q; cin >> P >> Q;
  int n = 0;
  int bit[MAX];

  if (P) { bit[n++] = 1; P--; }
  if (Q) { bit[n++] = 0; Q--; }

  while( P || Q ){
    if ( P == 0 ){ bit[n++] = 0; Q--; }
    else if ( Q == 0 ){ bit[n++] = 1; P--; }
    else {
      if ( bit[n-1] == 1 && bit[n-2] == 0 ) { bit[n++] = 1; P--; }
      else if ( bit[n-1] == 1 &&  bit[n-2] == 1 ) { bit[n++] = 0; Q--; }
      else if ( bit[n-1] == 0 ) { bit[n++] = 1; P--;}
      else assert(false);
    }
  }

  int p = 1, sum = 0;
  rep(i, n){
    sum += bit[i]*p;
    p *= 2;
  }

  cout << sum << endl;

}

main(){
  int t; cin>> t;
  rep(i, t) compute();
}
