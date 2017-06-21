#include<iostream>
#include<algorithm>
using namespace std;
#define REP(i, n) for ( int i = 0; i < (int)n; i++ )
#define MAX 10

static const int INFTY = (1 << 21);

void floyd( int G[MAX][MAX], int n ){
    REP(k, n) REP(i, n) REP(j, n){
	if ( G[i][k] == INFTY || G[k][j] == INFTY ) continue;
	G[i][j] = min(G[i][j], G[i][k] + G[k][j] );
    }
}

int main(){
    int m, G[MAX][MAX];
    while( cin >> m && m ){
        REP(i, MAX) REP(j, MAX) G[i][j] = INFTY;
	int s, t, c, n = 0; 
	REP(i, m) {
	    cin >> s >> t >> c;
	    G[s][t] = G[t][s] = c;
	    n = max(n, max(s, t));
	}
	n++;
	floyd(G, n);
	int ansi, minc = INFTY;
	REP(source, n){
	    int sum = 0;
	    REP(target, n){
		if ( target == source ) continue;
		sum += G[source][target];
	    }
	    if ( sum < minc ){
		minc = sum;
		ansi = source;
	    }
	}
	cout << ansi << " " << minc << endl;
    }

    return 0;
}
