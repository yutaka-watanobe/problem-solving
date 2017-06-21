#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)

char G[5][5][5];
bool A[28], B[28];

int count(int i, int j, int k, char t){
  int cnt = 0;
  REP(dx, -1, 2) REP(dy, -1, 2) REP(dz, -1, 2){
    if ( dx == 0 && dy == 0 && dz == 0 ) continue;
    int ni = i + dx;
    int nj = j + dy;
    int nk = k + dz;
    if ( ni < 0 || nj < 0 || nk < 0 || ni >= 5 || nj >= 5 || nk >= 5 ) continue;
	 if ( G[ni][nj][nk] == t ) cnt++;
  }
    return cnt;
}

void simulate(){
  char T[5][5][5];
  rep(i, 5) rep(j, 5) rep(k, 5) T[i][j][k] = G[i][j][k];
  
  rep(i, 5) rep(j, 5) rep(k, 5) {
    if ( G[i][j][k] == '0' ){
      if ( A[count(i, j, k, '1')] ) T[i][j][k] = '1';
    } else {
      if ( !B[count(i, j, k, '1')] ) T[i][j][k] = '0';
    }
  }

  rep(i, 5) rep(j, 5) rep(k, 5) G[i][j][k] = T[i][j][k];
}

void solve(int N, int tcase){
  rep(i, 5) rep(j, 5) rep(k, 5) cin >> G[i][j][k];
  vector<int> a, b;
  int M1, M2;
  rep(i, 28) A[i] = B[i] = false;
  cin >> M1;
  rep(i, M1){
    int x; cin >> x;
    A[x] = true;
  }
  cin >> M2;
  rep(i, M2){
    int x; cin >> x;
    B[x] = true;
  }
    rep(i, N) simulate();
  
    if ( tcase > 1 ) cout << endl;

  cout << "Case " << tcase << ":" << endl;
  rep(i, 5){
    if (i ) cout << endl;
    rep(j, 5){
      rep(k, 5){
	cout << G[i][j][k];
      }
      cout << endl;
    }
  }
}

main(){
  int N;
  for ( int t = 1;cin>> N, N; t++ ) solve(N, t);
}
