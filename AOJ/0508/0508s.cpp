#include<iostream>
#include<map>
#include<set>
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
map<set<int>, bool> M;

int len;

void dfs(set<int> vv,  int u, int depth ){
    len = max( len, depth );
    for ( int i = 0; i < G.size[u]; i++ ){
	int v = G.adj[u][i];
	
	set<int> uv = vv;
	uv.insert(v);
	if ( visited[v] ) continue;
	if ( M[uv] ) continue;
	M[uv] = true;
	visited[v] = true;
	dfs(uv, v, depth+1);
	visited[v] = false;
    }
}

int compute( int s ){
    len = 0;
    rep(i, MAX) visited[i] = false;
    M = map<set<int>, bool>();
    visited[s] = true;
    set<int> u; u.insert(s);
    M[u] = true;
    dfs(u, s, 1);
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

	int maxl = 0;
	for ( int i = 0; i < MAX; i++ ){
	    if ( G.size[i] == 0 ) continue;
	    maxl = max( maxl, compute(i) );
	}
	cout << maxl << endl;
    }
    return 0;
}
