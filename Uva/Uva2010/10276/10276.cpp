// 10276:Hanoi Tower Troubles Again!:1.0:DP
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
#define MAX 52

int T[MAX];

main(){
  T[1] = 1;
  T[2] = 3;
  int d = 4;
  for ( int i = 3; i < MAX; i++){
    T[i] = T[i-1] + d;
    if ( i % 2 == 0 ) d+=2;
  }
  int tcase; cin >> tcase;
  rep(t, tcase){
    int k; cin >> k;
    cout << T[k] << endl;
  }
}
