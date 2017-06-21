#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100
#define INFTY (1<<21)
#define rep(i, n) for ( int i = 0; i < n; i++)
int N, M, L, D[MAX][MAX], E[MAX][MAX];

int dijkstra(){
    int cost[MAX][MAX+1];
    bool visited[MAX][MAX+1];
    rep(i, N) rep(j, L+1){
	cost[i][j] = INFTY;
	visited[i][j] = false;
    }
    cost[0][L] = 0;
    
    while(1){
	pair<int, int> u;
	int minv = INFTY;
	rep(i, N) rep(j, L+1){
	    if ( !visited[i][j] && minv > cost[i][j] ){
		u = make_pair(i, j);
		minv = cost[i][j];
	    }
	}
	if ( minv == INFTY ) break;
	visited[u.first][u.second] = true;
	if ( u.first == N-1 ) return cost[u.first][u.second];
	for ( int v = 0; v < N; v++ ){
	    if ( D[u.first][v] == INFTY ) continue;
	    if ( !visited[v][u.second] ){
		cost[v][u.second] = min(cost[v][u.second], cost[u.first][u.second] + E[u.first][v]);
	    }
	    if ( u.second < D[u.first][v] ) continue;
	    int l = u.second - D[u.first][v];
	    if ( visited[v][l] ) continue;
	    cost[v][l] = min(cost[v][l], cost[u.first][u.second]);
	}
    }
}

main(){
    int s, t, d, e;
    while( cin >> N >> M >> L && N ){
	rep(i, N) rep(j, N){ D[i][j] = INFTY; E[i][j] = 0; }
	rep(i, M){
	    cin >> s >> t >> d >> e; s--; t--;
	    D[s][t] = D[t][s] = d;
	    E[s][t] = E[t][s] = e;
	}
	cout << dijkstra() << endl;
    }
}
