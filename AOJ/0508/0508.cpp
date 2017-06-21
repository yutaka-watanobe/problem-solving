#include<iostream>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define MAX 100

bool G[MAX][MAX];
bool visited[MAX];

int len;

void dfs( int u, int depth ){

    len = max( len, depth );

    for ( int v = 0; v < MAX; v++ ){
	if ( !G[u][v] || visited[v] ) continue;
	visited[v] = true;
	dfs(v, depth+1);
	visited[v] = false;
    }
}

int compute( int s ){
    len = 0;
    rep(i, MAX) visited[i] = false;
    visited[s] = true;
    dfs(s, 1);
    return len;
}

int main(){
    int m, s, t;
    while(1){
	cin >> m;
	if ( m == 0 ) break;
	rep(i, MAX) rep(j, MAX ) G[i][j] = false;

	for ( int i = 0; i < m; i++ ){
	    cin >> s >> t; s--; t--;
	    G[s][t] = G[t][s] = true;
	}

	int maxl = 0;
	for ( int i = 0; i < MAX; i++ ){
	    maxl = max( maxl, compute(i) );
	}
	cout << maxl << endl;
    }
    return 0;
}
