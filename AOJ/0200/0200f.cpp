#include<iostream>
using namespace std;
#define INFTY (1<<21)
#define MAX 100
#define rep(i, n) for ( int i = 0; i < (int)n; i++)

void floyd(int m, int C[MAX][MAX], int T[MAX][MAX]){
    rep(k, m) rep(i, m) rep(j, m){
	C[i][j] = min( C[i][j], C[i][k] + C[k][j] );
	T[i][j] = min( T[i][j], T[i][k] + T[k][j] );
    }
}

main(){
    int n, m, a, b, c, t, k, q, C[MAX][MAX], T[MAX][MAX];
    while( cin >> n >> m && n && m){
	rep(i, m) rep(j, m) { C[i][j] = T[i][j] = INFTY; }
	rep(i, n){
	    cin >> a >> b >> c >> t;
	    C[a-1][b-1] = C[b-1][a-1] = c;
	    T[a-1][b-1] = T[b-1][a-1] = t;
	}
	floyd(m, C, T);
	cin >> k;
	rep(i, k){
	    cin >> a >> b >> q;
	    if ( q ) cout << T[a-1][b-1] << endl;
	    else cout << C[a-1][b-1] << endl;
	}
    }
}
