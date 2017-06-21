#include<iostream>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)
#define MAX 1001

main(){
  unsigned int H, W, T[MAX][MAX][3], q, i1, j1, i2, j2;
  char ch;
  cin >> H >> W >> q;

  rep(i, H+1) rep(j, W+1) rep(k, 3) T[i][j][k] = 0;

  REP(i, 1, H+1) REP(j, 1, W+1){
      cin >> ch;
      if ( ch == 'J' ) T[i][j][0]++;
      if ( ch == 'O' ) T[i][j][1]++;
      if ( ch == 'I' ) T[i][j][2]++;
  }

  REP(i, 1, H+1) REP(j, 1, W+1) rep (k, 3) T[i][j][k] += T[i][j-1][k];
  REP(i, 1, H+1) REP(j, 1, W+1) rep (k, 3) T[i][j][k] += T[i-1][j][k];
  rep(i, q){
   cin >> i1 >> j1 >> i2 >> j2;
   rep(k, 3){
      if ( k ) cout << " ";
      cout << T[i2][j2][k] - T[i2][j1-1][k] - T[i1-1][j2][k] + T[i1-1][j1-1][k];
    }
    cout << endl;
  }
}
