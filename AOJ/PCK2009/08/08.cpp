#include<iostream>
#include<cassert>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define MAX 100
#define INFTY (1<<21)

int G[MAX][MAX], c, n, s, d;

int dijkstra(){
    int D[MAX][11];
    bool V[MAX][11];
    rep(i, n) rep(k, c+1) { D[i][k] = INFTY; V[i][k] = false; }

    D[s][c] = 0;

    while(1){
	int u, w, minv = INFTY;
	rep(i, n) rep(k, c+1){
	    if ( !V[i][k] && minv > D[i][k] ){ 
		minv = D[i][k]; u = i; w = k; 
	    }
	}
	if ( minv == INFTY ) break;
	V[u][w] = true;
	rep(v, n){
	    if ( G[u][v] == INFTY ) continue;
	    D[v][w] = min(D[v][w], D[u][w] + G[u][v]);
	    if ( w ) D[v][w-1] = min(D[v][w-1], D[u][w] + G[u][v]/2);
	}
    }
    int minv = INFTY;
    rep(k, c+1) minv = min(minv, D[d][k]);
    assert( minv != INFTY );
    return minv;
}

main(){
    int m, a, b, f;
    while( cin >> c >> n >> m >> s >> d && c){

	s--; d--;
	assert( 0 <= s && s < n );
	assert( 0 <= d && d < n );
	assert( 1 <= m && m <= 500);
	assert( 2 <= n && n <= 100);
	assert( 1 <= c && c <= 10);

	rep(i, n) rep(j, n) G[i][j] = INFTY;
	rep(i, m){
	    cin >> a >> b >> f; a--; b--;
	    assert( 0 <= a && a < n );
	    assert( 0 <= b && b < n );
	    assert( 1000 <= f && f <= 10000);
	    assert( f % 100 == 0 );
	    G[a][b] = G[b][a] = f;
	}
	cout << dijkstra() << endl;
    }
}
