// 11601:Avoiding Overlaps:1.5:Fill Grid
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

#define MAX 303
#define SHIFT 100

bool check(int x1, int y1, int x2, int y2, bool G[MAX][MAX]){
  REP(y, y1, y2) REP(x ,x1, x2){
    if ( G[y][x] ) return true;
  }
  return false;
}

int compute(){
  bool G[MAX][MAX];
  rep(y, MAX) rep(x, MAX) G[y][x] = false;
  int x1, y1, x2, y2;
  int n; cin >> n;
  int cnt = 0;
  rep(i, n){
    cin >> x1 >> y1 >> x2 >> y2;
    x1 += SHIFT;
    y1 += SHIFT;
    x2 += SHIFT;
    y2 += SHIFT;
    if ( check( x1, y1, x2, y2, G ) ) continue;

    REP(y, y1, y2) REP(x ,x1, x2) {
      G[y][x] = true;
      cnt++;
    }
  }
  return cnt;
}

main(){
  int tcase; cin>> tcase;
  rep(i, tcase){
    cout << "Case " << i+1 << ": " << compute() << endl;
  }
}
