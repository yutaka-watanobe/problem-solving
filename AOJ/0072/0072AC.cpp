#include<iostream>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
#define MAX 100
#define INFTY (1<<21)
int G[MAX][MAX], n;

void prim(){
    int D[MAX], V[MAX], P[MAX], sum = 0;
    rep(i, n) { D[i] = INFTY; V[i] = 0; }
    D[0] = 0;

    while(1){
	int u, minv = INFTY;
	rep(i, n) if ( !V[i] && minv > D[i]) { 
	    minv = D[i], u = i; 
	}
	if ( minv == INFTY ) break;
	V[u] = 1;
	if ( u ) sum += G[u][P[u]];
	rep(v, n){
	    if ( !V[v] && G[u][v] < D[v] ){
		D[v] = G[u][v];
		P[v] = u;
	    }
	}
    }

    cout << sum<< endl;
}

main(){
    int m, s, t, c;
    char ch;
    while( cin >> n >> m && n ){
	rep(i, n) rep(j, n) G[i][j] = INFTY;
	rep(i, m) {
	    cin >> s >> ch >> t >> ch >> c; 
	    G[s][t] = G[t][s] = c/100-1;
	}
	prim();
    }
}

