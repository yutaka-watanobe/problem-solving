#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<string>
#include<vector>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)
static const int MAX = 105;
static const string DIR = "NESW";
static const int di[4] = {-1, 0, 1, 0};
static const int dj[4] = {0, 1, 0, -1};

int H, W, pi, pj, dir;
long long L;
char G[MAX][MAX];

void input(){
  REP(i, 1, H+1) REP(j, 1, W+1){
    cin >> G[i][j];
    if ( G[i][j] != '.' && G[i][j] != '#' ){
      pi = i; pj = j;
      rep(r, 4)	if ( G[i][j] == DIR[r] ) dir = r;
      G[i][j] = '.';
    }
  }
}

void simulate(){
  int v[MAX][MAX][4];
  rep(i, H+2) rep(j, W+2) rep(r, 4) v[i][j][r] = -1;
  long long pos = 0;
  v[pi][pj][dir] = pos++;
  for (bool cycle = false;  pos <= L; pos++ ){
    int ni = pi + di[dir];
    int nj = pj + dj[dir];
    while(G[ni][nj] == '#'){
      dir = (dir+1)%4;
      ni = pi + di[dir];
      nj = pj + dj[dir];
    } 
    pi = ni;
    pj = nj;
    if ( v[pi][pj][dir] == -1 || cycle ) {
      v[pi][pj][dir] = pos;
    } else {
      long long cycle_len = pos - v[pi][pj][dir];
      long long remain = L - pos;
      pos = L - remain%cycle_len;
      cycle = true;
    }
  }

  cout << pi << " " << pj << " " << DIR[dir] << endl;
}

main(){
  while(1){
    cin >> H >> W >> L;
    if ( H == 0 ) break;
    rep(i, H+2) rep(j, W+2 ) G[i][j] = '#';
    input();
    simulate();
  }
}
