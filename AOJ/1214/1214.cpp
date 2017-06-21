#include<iostream>
#include<queue>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n ;i++ )
#define MAX 8
#define INFTY (1<<21)

int h, w, G[MAX][MAX], si, sj;
struct State{ int i, j, hp; };

int bfs(){
    State s;
    s.i = si; s.j = sj; s.hp = 6;
    queue<State> Q;
    int d[MAX][MAX][7];
    rep(i, h) rep(j, w) rep(hp, 7) d[i][j][hp] = INFTY;
    Q.push(s);
    d[s.i][s.j][s.hp] = 0;
    static const int di[4] = {0, -1, 0, 1};
    static const int dj[4] = {1, 0, -1, 0};
    State u, v;
    int ni, nj;
    while( !Q.empty() ){
	u = Q.front(); Q.pop();
	if ( G[u.i][u.j] == 3 ) return d[u.i][u.j][u.hp];
	for ( int r = 0; r < 4; r++ ){
	    ni = u.i + di[r];
	    nj = u.j + dj[r];
	    if ( ni < 0 || nj < 0 || ni >= h || nj >= w ) continue;
	    if ( G[ni][nj] == 0 ) continue;
	    v = u; v.i = ni; v.j = nj; v.hp--;
	    if ( v.hp < 1 ) continue;
	    if ( G[v.i][v.j] == 4 ) v.hp = 6;
	    if ( d[v.i][v.j][v.hp] != INFTY ) continue;
	    d[v.i][v.j][v.hp] = d[u.i][u.j][u.hp] + 1;
	    Q.push(v);
	}
    }
    return -1;
}

main(){
    while( cin >> w >> h && h && w ){
	rep(i, h) rep(j, w){
	    cin >> G[i][j];
	    if ( G[i][j] == 2 ) { si = i; sj = j; G[i][j] = 1; };
	}
	cout << bfs() << endl;
    }
}





