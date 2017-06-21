#include<cstdio>
#include<algorithm>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
#define MAX 100
#define INFTY (1<<21)
int n, m, G[MAX][MAX], E[MAX*MAX];

int eprim( int base ){
    int d[MAX];
    bool visited[MAX];
    rep(i, n){ d[i] = INFTY; visited[i] = false;}
    d[0] = 0;
    int cnt = 0, ans = 0;

    while(1){
	int u, minv = INFTY;
	rep(i, n){
	    if ( !visited[i] && minv > d[i]){
		minv = d[i]; u = i;
	    }
	}
	if ( minv == INFTY ) break;
	if ( u != 0 && ans < minv ) ans = minv;
	cnt++;
	visited[u] = true;
	rep(v, n){
	    if ( visited[v] || G[u][v] == INFTY || base > G[u][v]) continue;
	    d[v] = min( d[v], G[u][v] - base );
	}
    }
    return ( cnt != n )?INFTY:ans;
}

void compute(){
    int minv = INFTY;
    rep(i, m) minv = min ( minv, eprim(E[i]) );
    printf("%d\n", (minv == INFTY)?-1:minv);
}

main(){
    int s, t, e;
    while(1){ 
	scanf("%d %d", &n, &m);
	if ( n == 0 && m == 0 ) break;
	rep(i, n) rep(j, n) G[i][j] = INFTY;
	rep(i, m){
	    scanf("%d %d %d", &s, &t, &e);s--; t--;
	    G[s][t] = G[t][s] = E[i] = e;
	}
	compute();
    }
}
