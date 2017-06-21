#include<iostream>
#include<cstdio>
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

void dfs( int u, int depth ){
    //   len = max( len, depth );
    if ( len < depth ) len = depth;

    for ( int i = 0; i < G.size[u]; ++i ){
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
	//	scanf("%d", &m);
	cin >> m;
	if ( m == 0 ) break;
	rep(i, MAX) G.size[i] = 0;

	for ( int i = 0; i < m; i++ ){
	    //	    scanf("%d %d", &s, &t); s--; t--;
	    cin >> s >> t; s--; t--;
	    G.adj[s][G.size[s]++] = t;
	    G.adj[t][G.size[t]++] = s;
	}

	int maxl = 0;
	for ( int i = 0; i < MAX; i++ ){
	    if ( G.size[i] == 0 ) continue;
	    int c = compute(i);
	    //maxl = max( maxl, compute(i) );
	    if ( maxl < c ) maxl = c;
	}
	cout << maxl << endl;
    }
    return 0;
}
