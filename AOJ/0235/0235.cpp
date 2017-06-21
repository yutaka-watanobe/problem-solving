#include<iostream>
#include<vector>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define MAX 20
#define INFTY (1<<21)

class Node{
    public:
    int P;
    vector<int> C;
    Node(){
	P = -1;
	C.clear();
    }
};

int N, G[MAX][MAX], total;
Node node[MAX];
bool visited[MAX];

void dfs(int u, int p){
    visited[u] = true;
    node[u].P = p;
    rep(v, N){
	if ( G[u][v] == INFTY || visited[v]) continue;
	node[u].C.push_back(v);
	dfs(v, u);
    }
}

void parse(int u, int cost){
    visited[u] = true;
    if ( node[u].C.size() == 0 ) return;

    for ( int i = 0; i < node[u].C.size(); i++ ){
	int v = node[u].C[i];
	if ( !visited[v] ) parse(v, G[u][v]);
    }
    total += cost*2;
}

int getCost(){
    rep(i, N) visited[i] = false;
    int cur = 0;
    total = 0;
    while( cur != -1 ){
	parse(cur, 0);
	if ( node[cur].P != -1 ) total += G[cur][node[cur].P];
	cur = node[cur].P;
    }
    return total;
}

int compute(){
    int minc = INFTY;
    for ( int s = 0; s < N; s++ ){
	rep(i, N) { visited[i] = false; node[i] = Node(); }
	dfs(s, -1);
	minc = min(minc, getCost());
    }
    return minc;
}

main(){
    int s, t, c;
    while( cin >> N && N ){
	rep(i, N) rep(j, N) G[i][j] = INFTY;
	rep(i, N-1){
	    cin >> s >> t >> c;
	    s--; t--;
	    G[s][t] = G[t][s] = c;
	}
	cout << compute() << endl;
    }
}
