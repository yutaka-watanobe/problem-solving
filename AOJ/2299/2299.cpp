#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cassert>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)
static const int MAX = 502;

int H, W;
char G[MAX][MAX];

bool canGo(int si, int sj, int ti, int tj){
  int di = ti - si;
  int dj = tj - sj;
  if ( abs(di) > 0 ) di /= abs(di);
  if ( abs(dj) > 0 ) dj /= abs(dj);
  
  int pi = si + di;
  int pj = sj + dj;

  while(1){
    if ( G[pi][pj] != '.' ) return false;
    if ( pi == ti && pj == tj ) return true;
    pi += di;
    pj += dj;
  }
}

int solve(){
  vector<pair<int, int> > POS[26];
  bool removed[26];
  rep(i, 26) removed[i] = false;
  
  REP(i, 1, H+1) REP(j, 1, W+1){
    if ( G[i][j] != '.' ){
      char ch = G[i][j];
      POS[ch-'A'].push_back(make_pair(i, j));
    }
  }
  rep(i, 26) assert( POS[i].size() == 2 || POS[i].size() == 0 );

  int score = 0;
  bool isActivated;

  while(1){
    isActivated = false;
    rep(i, 26){
      if ( removed[i] ) continue;
      if ( POS[i].size() == 0 ) continue;
      int i1 = POS[i][0].first;
      int j1 = POS[i][0].second;
      int i2 = POS[i][1].first;
      int j2 = POS[i][1].second;

      bool suc = false;
      if ( i1 == i2 && j1 != j2 ){
	suc =  (canGo(i1, j1, i1, (j1+j2)/2) && canGo(i2, j2, i1, (j1+j2)/2));
      } else if ( i1 != i2 && j1 == j2 ){
	suc =  (canGo(i1, j1, (i1+i2)/2, j2) && canGo(i2, j2, (i1+i2)/2, j1));
      } else {
	suc = (canGo(i1, j1, i1, j2) && canGo(i2, j2, i1, j2) ||
	       canGo(i1, j1, i2, j1) && canGo(i2, j2, i2, j1) );
      }

      if ( suc ){
	G[i1][j1] = G[i2][j2] = '.';
	removed[i] = true;
	score += 2;
	isActivated = true;
      }
    }
    if ( !isActivated ) break;
  }

  return score;
}

main(){
  cin >> H >> W;
  rep(i, H+2) rep(j, W+2) G[i][j] = '#'; // sentinel
  rep(i, H) rep(j, W) cin >> G[i+1][j+1];
  cout << solve() << endl;
}
