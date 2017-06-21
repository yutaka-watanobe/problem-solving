#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 100
#define REP(i, e) for ( int i = 0; i < e; i++ )

bool G[MAX][MAX];
int n, start, goal;

void bfs( int s, int D[] ){
    queue<int> Q;
    bool V[MAX];
    REP(i, n) V[i] = false;
    Q.push(s);
    D[s] = 0;
    V[s] = true;
    int u;
    while(!Q.empty()){
	u = Q.front(); Q.pop();
	for ( int v = 0; v < n; v++ ){
	    if ( !G[u][v] || V[v]) continue;
	    D[v] = D[u] + 1;
	    V[v] = true;
	    Q.push(v);
	}
    }
}

int compute(){
    int DS[MAX], DG[MAX];
    bfs(start, DS);
    bfs(goal, DG);

    int maxv = 0;
    for ( int i = 0; i < n; i++ ){
	maxv = max( maxv, DS[i] + DG[i] );
    }

    return maxv;
}

void input(){
    scanf("%d", &n);
    REP(i, n) REP(j, n) G[i][j] = false;
    int m, u, v;     scanf("%d", &m);
    REP(i, m){
	scanf("%d %d", &u, &v);
	G[u][v] = G[v][u] = true;
    }
    scanf("%d %d", &start, &goal);
}

int main(){
    int tcase; scanf("%d", &tcase);
    for ( int i = 1; i <= tcase; i++ ){
	input();
	printf("Case %d: %d\n", i, compute());
    }
    return 0;
}
