#include<iostream>

using namespace std;
#define REP(i, n) for ( int i = 1; i <= n; i++ )
#define N 1001

int V, d;
int F[N+1];

bool G[N+1][N+1], visited[N+1];

void makeFibonacci(){
    F[0] = 1;
    F[1] = 2;
    for ( int i = 2; i <= N; i++ ) F[i] = (F[i-2] + F[i-1])%N;
}

void dfs( int u ){
    visited[u] = true;
    for ( int v = 1; v <= V; v++ ){
	if ( G[u][v] && !visited[v] ) dfs( v );
    }
}

void compute(){
    REP(i, V) REP(j, V) G[i][j] = false;

    for ( int i = 1; i <= V-1; i++ ){
	for ( int j = i+1; j <= V; j++ ){
	    if ( max(F[i], F[j]) - min(F[i], F[j] ) <  d ){
		G[i][j] = G[j][i] = true;
	    }
	}
    }
    REP(i, V) visited[i] = false;
    int ncomponent = 0;

    for ( int i = 1; i <= V; i++ ){
	if ( !visited[i] ){
	    dfs(i);
	    ncomponent++;
	}
    }
    cout << ncomponent << endl;

}

int main(){
    makeFibonacci();
    while ( cin >> V >> d ) compute();
    return 0;
}
