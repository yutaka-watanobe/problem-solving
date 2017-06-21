#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<vector>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)
typedef unsigned long long ullong;

static const int MAX = 50;
static const int GMAX = 102;

struct Point{ ullong x, y, z; };
int G[GMAX][GMAX][GMAX];

main(){
  int N, K, nx, ny, nz;
  cin >> N >> K;
  pair<Point, Point> C[MAX];
  set<ullong> X, Y, Z;
  vector<ullong> VX, VY, VZ;
  map<ullong, int> MX, MY, MZ;

  rep(i, N){
    cin >> C[i].first.x >> C[i].first.y >> C[i].first.z;
    cin >> C[i].second.x >> C[i].second.y >> C[i].second.z;
    X.insert(C[i].first.x);
    X.insert(C[i].second.x);
    Y.insert(C[i].first.y);
    Y.insert(C[i].second.y);
    Z.insert(C[i].first.z);
    Z.insert(C[i].second.z);
  }

  nx = ny = nz = 0;
  for ( set<ullong>::iterator it = X.begin(); it != X.end(); it++){
    VX.push_back(*it);
    MX[*it] = nx++;
  }
  for ( set<ullong>::iterator it = Y.begin(); it != Y.end(); it++){
    VY.push_back(*it);
    MY[*it] = ny++;
  }
  for ( set<ullong>::iterator it = Z.begin(); it != Z.end(); it++){
    VZ.push_back(*it);
    MZ[*it] = nz++;
  }

  rep(i, nx) rep(j, ny) rep(k, nz) G[i][j][k] = 0;

  rep(i, N){
    int sx = MX[C[i].first.x];
    int tx = MX[C[i].second.x];
    int sy = MY[C[i].first.y];
    int ty = MY[C[i].second.y];
    int sz = MZ[C[i].first.z];
    int tz = MZ[C[i].second.z];
    REP(x, sx, tx) REP(y, sy, ty) REP(z, sz, tz) G[x][y][z]++;
  }

  ullong sum = 0;
  rep(x, nx){
    rep(y, ny){
      rep(z, nz){
	if ( G[x][y][z] >= K ){
	  sum += (VX[x+1] - VX[x])*(VY[y+1] - VY[y])*(VZ[z+1] - VZ[z]);
	}
      }
    }
  }

  cout << sum << endl;
}
