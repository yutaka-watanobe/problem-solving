#include<iostream>
#include<cassert>

using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define INF (1<<20)
#define MAX 101
main(){
  int n, m, a, b, c;
  int D[MAX][MAX], M[MAX][MAX];
  while(1){
    cin >> n >> m;

    if ( n == 0 && m == 0 ) break;
    assert( 2 <= n && n <= 100);
    rep(i, n) rep(j, n) { D[i][j] = INF; M[i][j] = 0; }
    rep(i, n) D[i][i] = 0;
    rep(i, m){
      cin >> a >> b >> c; 
      assert( 1 <= c && c <= 1000 );
      a--; b--;
      D[a][b] = D[b][a] = c;
      M[a][b] = M[b][a] = 1;
    }

    rep(k, n) rep(i, n) rep(j, n)
      D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

    int ans = D[0][n-1];
    rep(k, n) rep(i, n) rep(j, n)
      if ( M[i][k] && M[k][j] ) ans = min(ans, D[0][i] + D[j][n-1] );
    
    cout << ans << endl;
  }
}
