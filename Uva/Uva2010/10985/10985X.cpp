#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)
#define MAX 121
#define INFTY (1<<21)

int G[MAX][MAX];
bool  T[MAX][MAX], R[MAX];
vector<int> adj[MAX];

int n, m, cnt;

void dfs(int u, vector<int> p[], int d[]){
    R[u] = true;
    for ( int i = 0; i < p[u].size(); i++ ){
	int v = p[u][i];
	if ( !R[v] && d[v]+1 == d[u]) dfs(v, p, d);
    }
}

int bfs(int s, int g ){
    queue<int> q;
    vector<int> p[MAX];

    int d[MAX];
    rep(i, n){
	d[i] = INFTY;
    }
    d[s] = 0;
    q.push(s);

    int u;

    while(!q.empty() ){
	int u = q.front(); q.pop();

	for ( int i = 0; i < adj[u].size(); i++ ){
	    int v = adj[u][i];

	    if ( d[v] == d[u] + 1 ){
		p[v].push_back(u);
	    } else if ( d[v] == INFTY ){
		assert(p[v].size()==0);
		p[v].push_back(u);
		d[v] = d[u] + 1;
		q.push(v);
	    } else if ( d[v] > d[u] + 1 ){
		assert( false );
		//		d[v] = d[u] + 1;
		//p[v].clear();
		//p[v].push_back(u);
	    }
	}
    }
    
    cnt = 0;

    rep(i, n) R[i] = false;

    dfs(g, p, d);

    for ( int u = 0; u < n; u++ ){
	if ( R[u] ) cnt += p[u].size();
    }

    //    rep(i, n) rep(j, n) if ( T[i][j] && i != j ) cnt++;

    return cnt;
}

int compute(){
    cin >> n >> m;
    int s, t;
    rep(i, n) rep(j, n) G[i][j] = INFTY;
    rep(i, n) adj[i].clear();
    rep(i, m){
	cin >> s >> t;
	G[s][t] = G[t][s] = 1;
	adj[s].push_back(t);
	adj[t].push_back(s);
    }

    rep(k, n) rep(i, n) {
	if ( G[i][k] == INFTY ) continue;
	rep(j, n){
	    if ( G[k][j] == INFTY ) continue;
	    if ( G[i][j] == INFTY || G[i][k] + G[k][j] < G[i][j] ){
		G[i][j]  = G[i][k] + G[k][j];
	    }
	}
    }
    int maxd = 0;
    REP(i, 0, n-1) REP(j, i+1, n){
	maxd = max(maxd, G[i][j] );
    }
    

    int maxv = 0;
    REP(i, 0, n-1) REP(j, i+1, n){
	if ( G[i][j] == maxd ){
	    maxv = max(maxv, bfs(i, j) );
	}
    }
    return maxv;
}

main(){
    int tcase; cin >> tcase;
    rep(i, tcase){
	cout << "Case #" << i+1 << ": " << compute() << endl;
    }
}
