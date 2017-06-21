#include<iostream>
using namespace std;
#define REP(i, e) for ( int i = 0; i < e; i++ )
#define MAX 100
static const int INFTY = (1<<21);
int G[MAX][MAX], n;

int prim(){
    int P[MAX], D[MAX];
    bool V[MAX];
    REP(i, n) { D[i] = INFTY; V[i] = false;}
    D[0] = 0;
    P[0] = -1;
    int cost = 0;
    while(1){
	int u;
	int minv = INFTY;
	REP(i, n)  if ( !V[i] && D[i] < minv ){
	    minv = D[i]; u = i;
	}
	if ( minv == INFTY ) break;
	V[u] = true;
	if ( P[u] != -1 ) cost += G[u][P[u]];

	REP(v, n){
	    if ( G[u][v] != INFTY && !V[v] ){
		if ( D[v] > G[u][v] ){
		    P[v] = u;
		    D[v] = G[u][v];
		}
	    }
	}
    }
    return cost;
}

int main(){
    int m, s, t, c;
    while( cin >> n >> m && n){
	REP(i, n) REP(j, n) G[i][j] = INFTY;
	for ( int i = 0; i < m; i++ ){
	    cin >> s >> t >> c;
	    G[s][t] = G[t][s] = c;
	}
	cout << prim() << endl;
    }
}
