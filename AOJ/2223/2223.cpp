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
static const int MAX = 10;
static const int di[4] = {0, -1, 0, 1};
static const int dj[4] = {1, 0, -1, 0};
static const string D = "RULD";

int H, W, sum;
char G[MAX][MAX];

bool hasLeaf(int pi, int pj, int r, int &ni, int &nj){
  do{
      pi += di[r];
      pj += dj[r];
      if ( pi < 0 || pj < 0 || pi >= H ||  pj >= W ) break;
      if ( G[pi][pj] == 'o' ) {
	  ni = pi;
	  nj = pj;
	  return true;
      }
  } while(1);
  return false;
}

bool dfs(int pi, int pj, int dir, vector<int> path, int rem){
  if ( rem == 1 ){
      rep(i, path.size()) cout << D[path[i]];    
      cout << endl;
      return true;
  }

  rep(r, 4){
    if ( (r+2)%4 == dir ) continue;
    int ni, nj;
    if ( hasLeaf(pi, pj, r, ni, nj) ){
	vector<int> np = path;
	G[pi][pj] = '.';
	np.push_back(r);
	if (dfs(ni, nj, r, np, rem-1)) return true;
	G[pi][pj] = 'o';
    }
  }
  return false;
}

int getDir(char c){
    rep(i, D.size()) if ( c == D[i] ) return i;
}

main(){
  int si, sj, dir;
  cin >> H >> W;
  sum = 0;
  rep(i, H) rep(j, W) {
    cin >> G[i][j];
    if ( G[i][j] != 'o' && G[i][j] != '.' ){
      dir = getDir(G[i][j]);
      si = i; sj = j;
      G[i][j] = 'o';
    }
    if ( G[i][j] == 'o' ) sum++;
  }
  vector<int> P;
  dfs(si, sj, dir, P, sum);
}
