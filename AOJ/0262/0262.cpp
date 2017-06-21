#include<iostream>
#include<cassert>
using namespace std;
#define MAX 250
#define rep(i, n) for ( int i = 0; i < n; i++ )
int G[MAX+2][MAX+2], D[MAX+2];

main(){
  int m, n; 
  int tcase = 0;
  while(cin >> m){
    if ( m == 0 ) break;
    cin >> n;
    tcase++;
    rep(i, n+2) rep(j, n+2) G[i][j] = 0;
    D[0] = D[n+1] = 0;
    for ( int i = 1; i <= n; i++ ) cin >> D[i];
    for ( int i = 0; i <= n; i++ ){
      assert( -n <= D[i] && D[i] <= n );
      for ( int k = 1; k <= m; k++ ){
	int t = min(i+k, n+1);
	if ( D[t] > 0 ) t = min(n+1, t + D[t]);
	else if ( D[t] < 0 ) t = max(0, t + D[t]);
	G[i][t] = 1;
      }
    }
    rep(k, n+2) rep(i, n+2) rep(j, n+2){
      if ( G[i][k] && G[k][j] ) G[i][j] = 1;
    }
    bool valid = true;
    for ( int i = 0; i <= n; i++ ){
      if ( G[0][i] && !G[i][n+1]) valid = false;
    }
    cout << (valid?"OK":"NG") << endl;
  }
}
