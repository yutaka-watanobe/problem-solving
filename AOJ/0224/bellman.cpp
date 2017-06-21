#include<iostream>
#include<string>
#include<cassert>
#include<algorithm>
using namespace std;
#define REP(i, a, b) for ( int i = a; i < b; i++ )
#define rep(i, n) REP(i, 0, n)
#define INFTY (1<<21)

int m, n, k, d, C[7], G[110][110], N;

int getID(string str){
    if ( str == "H" ) return 0;
    if ( str == "D" ) return N - 1;
    string num = str.substr(1, str.size()-1);
    if ( str[0] == 'C' ) return atoi(num.c_str());
    if ( str[0] == 'L' ) return atoi(num.c_str()) + m;
    assert( false );
}

bool isCake(int x){ return 1 <= x && x <= m; }

void bellman(){
    int D[110][64];
    rep(i, N) rep(j, (1<<m)) D[i][j] = INFTY;

    D[0][0] = 0;

    rep(o, N*(1<<m)){
	rep(u, N) rep(v, N){
	    if ( u == v || G[u][v] == INFTY ) continue;
	    rep(b, (1<<m)){
		if (isCake(v) && (b&(1<<(v-1))) != 0 ) continue; 
		if ( isCake(v) ){
		    int t = (b | (1<<(v-1)));
		    D[v][t] = min(D[v][t], D[u][b] + G[u][v] - C[v]);
		} else {
		    D[v][b] = min(D[v][b], D[u][b] + G[u][v]);
		}
	    }
	}
    }
    int minv = INFTY;
    rep(i, (1<<m)) minv = min(minv, D[N-1][i]);
    cout << minv << endl;
}

main(){
    string source, target;
    int cost;
    while(1){
	cin >> m >> n >> k >> d;
	if ( m == 0 && n == 0 && k == 0 && d == 0 ) break;
	N = 2 + n + m;
	REP(i, 1, m+1) cin >> C[i];
	rep(i, N) rep(j, N) G[i][j] = INFTY;
	rep(i, d){
	    cin >> source >> target >> cost;
	    int s = getID(source);
	    int t = getID(target);
	    G[s][t] = min(G[s][t], cost * k);
	    G[t][s] = G[s][t];
	}
	bellman();
    }
}
