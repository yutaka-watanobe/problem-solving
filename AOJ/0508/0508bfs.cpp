#include<iostream>
#include<queue>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define MAX 100

class Graph{
public:
  int adj[MAX][MAX];
  int size[MAX];
};

Graph G;
bool visited[MAX];
int len;

int d[MAX];

void bfs(int s){
    queue<int> Q;
    rep(i, MAX){
	visited[i] = false;
	d[i] = INT_MAX;
    }
    d[s] = 0;
    visited[s] = true;
    Q.push(s);

    int u, v;
    while(!Q.empty()){
	u = Q.front(); Q.pop();
	for ( int i = 0; i < G.size[u]; i++ ){
	    int v = G.adj[u][i];
	    if ( visited[v] ) continue;
	    visited[v] = true;
	    d[v] = d[u] + 1;
	    Q.push(v);
	}
    }
}

void dfs( int u, int depth ){
    len = max( len, depth );

    for ( int i = 0; i < G.size[u]; i++ ){
	int v = G.adj[u][i];
	if ( visited[v] ) continue;
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
	rep(i, MAX) G.size[i] = 0;

	for ( int i = 0; i < m; i++ ){
	    cin >> s >> t; s--; t--;
	    G.adj[s][G.size[s]++] = t;
	    G.adj[t][G.size[t]++] = s;
	}
	
	int md = 0;
	bfs(0);
	for ( int i = 0; i < MAX; i++ ){
	    if ( d[i] == INT_MAX ) continue;
	    md = max( md, d[i] );
	}

	int maxl = 0;
	for ( int i = 0; i < MAX; i++ ){
	    if ( G.size[i] == 0 ) continue;
	    //	    if ( d[i] != md ) continue;
	    maxl = max( maxl, compute(i) );
	}
	cout << maxl << endl;
    }
    return 0;
}
