// 1.36 sec
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

#define MAX 400
#define INFTY INT_MAX

int prim(int N, int M[MAX][MAX]){
    bool visited[MAX];
    int cost[MAX];
    int pi[MAX];
    
    for ( int i = 0; i < N; i++ ){
	visited[i] = false;
	cost[i] = INT_MAX;
    }
    
    cost[0] = 0;
    pi[0] = -1;
    
    while ( 1 ){
	int mincost = INT_MAX;
	int u;
	for ( int i = 0; i < N; i++ ){
	    if ( !visited[i] && cost[i] < mincost ){
		mincost = cost[i];
		u = i;
	    }
	}
	
	if ( mincost == INT_MAX ) break;
	visited[u] = true;
	
	for ( int v = 0; v < N; v++ ){
	    if ( visited[v] || M[u][v] == INFTY ) continue;
	    if ( M[u][v] < cost[v] ){
		cost[v] = M[u][v];
		pi[v] = u;
	    }
	}
    }
    int sum = 0;
    rep(i, N){
      if ( !visited[i] ) return -1;
      if ( pi[i] == -1 ) continue;
      sum += M[i][pi[i]];
    }
    return sum;
}

int main(){
    int N, M, cost;
    string source, target;
    while(1){
      cin >> N >> M;
      if ( N == 0 && M == 0 ) break;
	map<string, int> NM;
	rep(i, N){
	    cin >> source;
	    NM[source] = i;
	}
	int adj[MAX][MAX];
	rep(i, N) rep(j, N) adj[i][j] = INFTY;
	for ( int i = 0; i < M; i++ ){
	    cin >> source >> target >> cost;
	    adj[NM[source]][NM[target]] = cost;
	    adj[NM[target]][NM[source]] = cost;
	}
	cin >> source;

	int cost = prim(N, adj);
	if ( cost == -1 ) cout << "Impossible" << endl;
	else cout << cost << endl;
    }
}

