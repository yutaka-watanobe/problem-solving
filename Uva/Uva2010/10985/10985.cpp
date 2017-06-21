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

int bfs(int s ){
    queue<int> q;
    
    int d[MAX], t[MAX];
    rep(i, n){
	d[i] = INFTY;
	t[i] = 0;
    }
    d[s] = 0;
    q.push(s);

    int u;

    while(!q.empty() ){
	int u = q.front(); q.pop();

	for ( int i = 0; i < adj[u].size(); i++ ){
	    int v = adj[u][i];

	    if ( d[v] == d[u] + 1 ){
		t[v] += t[u]+1;
	    } else if ( d[v] == INFTY ){
		d[v] = d[u] + 1;
		t[v] = t[u]+1;
		q.push(v);
	    } else if ( d[v] > d[u] + 1 ){
		assert( false );
	    }
	}
    }
    
    int maxv = 0;
    for ( int i = 0; i < n; i++ ) maxv = max(maxv, t[i]);
    return maxv;
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

    int maxv = 0;
    REP(i, 0, n) maxv = max(maxv, bfs(i) );
    return maxv;
}

main(){
    int tcase; cin >> tcase;
    rep(i, tcase){
	cout << "Case #" << i+1 << ": " << compute() << endl;
    }
}
