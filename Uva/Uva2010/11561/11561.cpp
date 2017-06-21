// 11561:Getting Gold:2.0: DFS in Grid
// 回りにTがあると分かったら探索を打ち切ればよい
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
#define MAX 50

static const int di[4] = {0, -1, 0, 1};
static const int dj[4] = {1, 0, -1, 0};

int H, W, cnt;
char G[MAX][MAX];
bool V[MAX][MAX];

void dfs(int pi, int pj){
  V[pi][pj] = true;
  if ( G[pi][pj] == 'G' ) cnt++;

  rep(r, 4){
    if ( G[pi+di[r]][pj+dj[r]] == 'T' ) return;
  }

  int ni, nj;
  rep(r, 4){
    ni = pi + di[r];
    nj = pj + dj[r];
    if ( !V[ni][nj] && G[ni][nj] != '#' ) dfs(ni, nj);
  }
  

}


void compute(){
  int si, sj;
  rep(i, H) rep(j, W) {
    cin >> G[i][j];
    if ( G[i][j] == 'P' ) {
      G[i][j] = '.';
      si = i; sj = j;
    }
  }
  
  cnt = 0;
  rep(i, H) rep(j, W) V[i][j] = false;
  
  dfs(si, sj);

  cout << cnt << endl;
}

main(){
  while( cin >> W >> H ) compute();
}
