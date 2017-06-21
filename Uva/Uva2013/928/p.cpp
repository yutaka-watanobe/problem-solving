#include<iostream>
#include<queue>
using namespace std;
#define MAX  300
#define INFTY (1<<21)

class State{
    public:
    int i, j, c;
    State(){}
    State(int i, int j, int c): i(i), j(j), c(c){}
};

int R, C;
char G[MAX][MAX];
State start;

bool hasPath(int i, int j, int ii, int jj, int di, int dj ){
    while (1){
	if ( i == ii && j == jj ) return true;
	i += di;
	j += dj;
	if ( G[i][j] == '#' ) return false;
    }
}

int bfs(){
    bool visited[MAX][MAX][3];
    int d[MAX][MAX][3];
    queue<State> Q;
    for (int i = 0; i < R; i++ ){
	for ( int j = 0; j < C; j++ ){
	    for ( int c = 0; c < 3; c++ ){
		visited[i][j][c] = false;
		d[i][j][c] = INFTY;
	    }
	}
    }

    visited[start.i][start.j][start.c] = true;
    d[start.i][start.j][start.c] = 0;
    Q.push(start);

    int di[4] = {0, -1, 0, 1};
    int dj[4] = {1, 0, -1, 0};

    State u, v;
    int ni, nj, nc;

    while(!Q.empty()){
	u = Q.front(); Q.pop();

	if ( G[u.i][u.j] == 'E') return d[u.i][u.j][u.c];


	for ( int r = 0; r < 4; r++ ){
	    ni = u.i + di[r]*(u.c+1);
	    nj = u.j + dj[r]*(u.c+1);
	    if ( 0 > ni || 0 > nj || ni >= R || nj >= C ) continue;
	    if ( !hasPath(u.i, u.j, ni, nj, di[r], dj[r] ) ) continue;

	    nc = (u.c+1)%3;

	    if ( !visited[ni][nj][nc] && G[ni][nj] != '#'){
		visited[ni][nj][nc] = true;
		d[ni][nj][nc] = d[u.i][u.j][u.c] + 1;
		Q.push(State(ni, nj, nc));
	    }
	}
    }


    return -1;
}

void input(){
    cin >> R >> C;
    for ( int i = 0; i < R; i++ ){
	for ( int j = 0; j < C; j++ ) {
	    cin >> G[i][j];
	    if ( G[i][j] == 'S' ){
		start.i = i; start.j = j; start.c = 0;
	    }
	}
    }
}

main(){
    int tcase; cin >> tcase;
    for (  int i = 0; i < tcase; i++ ){
	input(); 
	int cost = bfs();
	if ( cost < 0 ) cout << "NO" << endl;
	else cout << cost << endl;
    }
    
}
