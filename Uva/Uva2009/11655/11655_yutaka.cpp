#include<iostream>
#include<vector>
using namespace std;
#define MAX 5000
#define M 100000

vector<int> G[MAX];
int n, T[MAX], E[MAX];
bool visited[MAX];

pair<int, int>  dfs( int u ){
    if ( visited[u] ){
	return make_pair(T[u], E[u]);
    }
    for ( int i = 0; i < G[u].size(); i++ ){
	int v = G[u][i];
	pair<int, int> pp = dfs(v);
	T[u] = (T[u]+pp.first)%M;
	E[u] = (E[u]+pp.second+pp.first)%M;
    }
    visited[u] = true;
    return make_pair(T[u], E[u]);
}

void compute( int tcase){
    pair<int, int> pp = dfs(0);
    cout << "Case " << tcase << ": " << pp.second << " " << pp.first << endl;
}

void input(){
    int m, s, t;
    cin >> n >> m;
    for ( int i = 0; i < n; i++ ) {
	G[i].clear();
	T[i] = E[i] = 0;
	visited[i] = false;
    }
    visited[n-1] = true;
    T[n-1] = 1;
    E[n-1] = 0;
    for ( int i = 0; i < m; i++ ){
	cin >> s >> t;
	s--; t--;
	G[s].push_back(t);
    }
}

main(){
    int m;
    int tcase; cin >> tcase;
    for ( int i = 1; i <= tcase; i++ ){
	input();
	compute(i);
    }

}
