// 11760:Brother Arif, please feed us!:1.0:Grid, Writing
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
#define MAX 2000

int R, C, N, t;
pair<int, int> P[MAX], pos;

bool check(){
  int di[5] = {0, 0, -1, 0, 1};
  int dj[5] = {0, 1, 0, -1, 0};
  
  int ni, nj;
  rep(r, 5){
    ni = pos.first + di[r];
    nj = pos.second + dj[r];
    if ( ni < 0 || nj < 0 || ni >= R || nj >= C ) continue;

    bool escaped = true;
    rep(i, N){
      if ( P[i].first == ni || P[i].second == nj ) {
	escaped = false;
	break;
      }
    }
    if ( escaped ) return true;
  }
  return false;
}

main(){
  int t = 1;
  while( cin >> R >> C >> N && R && C && N ){
    rep(i, N) { cin >> P[i].first >> P[i].second; }
    cin >> pos.first >> pos.second;
    
    cout << "Case " << t << ": ";
    if ( check()){
      cout << "Escaped again! More 2D grid problems!" << endl;
    } else {
      cout << "Party time! Let's find a restaurant!" << endl;
    }
    t++;
  }
}
