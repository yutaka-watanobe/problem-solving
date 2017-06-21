#include<iostream>
#include<queue>
#include<string>
using namespace std;

#define MAX 20
#define PMAX 10
#define rep(i, n) for ( int i = 0; i < (int)n; i++ )
#define INFTY (1<<21)

struct State{ int a, b, cur; };

int H, W;
string P;
char G[MAX][MAX];

int getDi( char ch ){
    if ( ch == '5' || ch == '4' || ch == '6') return 0;
    else if ( ch == '2' ) return 1;
    else if ( ch == '8' ) return -1;
}

int getDj( char ch ){
    if ( ch == '5' || ch == '2' || ch == '8') return 0;
    else if ( ch == '6' ) return 1;
    else if ( ch == '4' ) return -1;
}

int bfs(int as, int bs, int &g){
    int D[MAX*MAX][MAX*MAX][PMAX];
    rep(i, H*W) rep(j, H*W) rep(k, P.size()) {
	D[i][j][k] = INFTY;
    }
    State s;
    s.a = as;
    s.b = bs;
    s.cur = 0;
    queue<State> Q;

    Q.push(s);
    D[s.a][s.b][s.cur] = 0;

    static const int di[5] = {0, 0, -1, 0, 1};
    static const int dj[5] = {0, 1, 0, -1, 0};

    State u, v;
    while( !Q.empty() ){
	u = Q.front(); Q.pop();
	if ( u.a == u.b ) {
	    g = u.a;
	    return D[u.a][u.b][u.cur];
	}
	
	int ni, nj;
	for ( int r = 0; r < 5; r++ ){
	    ni = u.a/W + di[r];
	    nj = u.a%W + dj[r];
	    if ( ni < 0 || nj < 0 || ni >= H || nj >= W ) continue;
	    if ( G[ni][nj] == '#' ) continue;

	    v = u;
	    v.a = ni*W + nj;

	    ni = v.b/W + getDi(P[v.cur]);
	    nj = v.b%W + getDj(P[v.cur]);
	    
	    if ( ni < 0 || nj < 0 || ni >= H || nj >= W ){
		ni = v.b/W;
		nj = v.b%W;
	    }

	    v.cur = (v.cur+1)%P.size();
	    v.b = ni*W + nj;
	    
	    if ( D[v.a][v.b][v.cur] == INFTY ){
		D[v.a][v.b][v.cur] = D[u.a][u.b][u.cur] + 1;
		Q.push(v);
	    }
	}
    }

    return INFTY;
}

main(){
    while( cin >> H >> W && H && W ){	
	int s, g, p;
	rep(i, H) rep(j, W) {
	    cin >> G[i][j];
	    if ( G[i][j] == 'A' ){ G[i][j] = '.'; s = i*W+j; }
	    if ( G[i][j] == 'B' ){ G[i][j] = '.'; p = i*W+j; }
	}
	cin >> P;
	int cost = bfs(s, p, g);
	if ( cost == INFTY ) cout << "impossible" << endl;
	else cout << cost << " " << g/W << " " << g%W << endl;
    }
}
