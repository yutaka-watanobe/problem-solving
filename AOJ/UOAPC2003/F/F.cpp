#include<iostream>
using namespace std;

#define FOR(i, b, e) for ( int i = b; i <= e; i++ )
#define MAX 200
#define INFTY (1<<21)

int G[MAX][MAX];
int s, d, n;

int prim(){
    int P[MAX], D[MAX];
    bool V[MAX];
    FOR(i, 1, n) { D[i] = INFTY; V[i] = false;}
    D[1] = 0;
    P[1] = -1;
    int cost = 0;
    while(1){
	int u;
	int minv = INFTY;
	FOR(i, 1, n)  if ( !V[i] && D[i] < minv ){
	    minv = D[i]; u = i;
	}
	if ( minv == INFTY ) break;
        V[u] = true;
	if ( P[u] != -1 ) cost += G[u][P[u]];
	FOR(v, 1, n){
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
    while( cin >> s >> d && (s && d) ){
	n = s + d;
	FOR(i, 1, s+d) FOR(j, 1, s+d) G[i][j] = INFTY;
	FOR(i, 1, s) FOR(j, s+1, s+d){
	    cin >> G[i][j];
	    if ( G[i][j] == 0 ) G[i][j] = INFTY;
	    G[j][i] = G[i][j];
	}
	FOR(i, 1, d-1) FOR(j, 1, d-i){
	    cin >> G[i+s][j+i+s];
	    if ( G[i+s][j+i+s] == 0 ) G[i+s][j+i+s] = INFTY;
	    G[j+i+s][i+s] = G[i+s][j+i+s];
	}
	FOR(i, 1, s) FOR(j, 1, s) G[i][j] = 0;
	
	cout << prim() << endl;
    }
    return 0;
}
