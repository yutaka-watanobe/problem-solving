#include<iostream>
#include<queue>
#define MAX 25
using namespace std;
#define REP(i, n) for ( int i = 0; i < n; i++ )
#define FOR(i, s, e) for ( int i = s; i <= e; i++ )
#define BLOCK '#'
#define SPACE '.'
#define INFTY (1<<21)

class Cycle{
    public:
    int y, x, d, c;

    Cycle(){}
    Cycle( int y, int x, int d, int c): y(y), x(x), d(d), c(c){

    }

    void forward( int ny, int nx){
	y = ny; x = nx;
	c = (c+1)%5;
    }

    void backward(int ny, int nx){
	y = ny; x = nx;
	if ( c == 0 ) c = 4;
	else c--;
    }

    void turnLeft(){
	d = (d+1)%4;
    }

    void turnRight(){
	if ( d== 0 ) d = 3;
	else d--;
    }
};

int H, W;
char G[MAX+2][MAX+2];
int sy, sx, gy, gx;

int bfs(){
    queue<Cycle> Q;

    int D[MAX+2][MAX+2][4][5];
    FOR(y, 1, H) FOR(x, 1, W) REP(d, 4) REP(c, 5) D[y][x][d][c] = INFTY;

    Cycle start = Cycle(sy, sx, 1, 0);
    Q.push(start);
    D[sy][sx][1][0] = 0;
    
    Cycle u, v;
    int dist, ny, nx;

    static const int dy[4] = {0, -1, 0, 1};
    static const int dx[4] = {1, 0, -1, 0};

    while(!Q.empty()){
	u = Q.front(); Q.pop();
	//	cout << u.y << " " << u.x << " " << u.d << " " << u.c << endl;
	if ( u.y == gy && u.x == gx && u.c == 0 ) return D[u.y][u.x][u.d][u.c];
	dist = D[u.y][u.x][u.d][u.c];
	// forward
	v = u;
	ny = v.y + dy[v.d];
	nx = v.x + dx[v.d];
	if ( G[ny][nx] == SPACE ){
	    v.forward(ny, nx);
	    if ( D[v.y][v.x][v.d][v.c] == INFTY ){ D[v.y][v.x][v.d][v.c] = dist + 1; Q.push(v);}
	}
	// backward
	/*
	v = u;
	ny = v.y + dy[v.d]*(-1);
	nx = v.x + dx[v.d]*(-1);
	if ( G[ny][nx] == SPACE ){
	    v.backward(ny, nx);
	    if ( D[v.y][v.x][v.d][v.c] == INFTY ){ D[v.y][v.x][v.d][v.c] = dist + 1; Q.push(v);}
	    }*/
	// left
	v = u;
	v.turnLeft();
	if ( D[v.y][v.x][v.d][v.c] == INFTY ){ D[v.y][v.x][v.d][v.c] = dist + 1; Q.push(v);}
	// right
	v = u;
	v.turnRight();
	if ( D[v.y][v.x][v.d][v.c] == INFTY ){ D[v.y][v.x][v.d][v.c] = dist + 1; Q.push(v);}
    }

    return INFTY;
}

int main(){
    int tcase = 1;
    while(1){
	cin >> H >> W;
	if ( H == 0 && W == 0 ) break;
	REP(i, H+2) G[i][0] = G[i][W+1] = BLOCK;
	REP(j, W+2) G[0][j] = G[H+1][j] = BLOCK;
	FOR(y, 1, H) FOR(x, 1, W) {
	    cin >> G[y][x];
	    if ( G[y][x] == 'S' ) {
		sy = y; sx = x; G[y][x] = SPACE;
	    } else if ( G[y][x] == 'T' ){
		gy = y; gx = x; G[y][x] = SPACE;
	    }
	}
	if ( tcase > 1 ) cout << endl;
	cout << "Case #" << tcase++ << endl;
	int cost = bfs();
	if ( cost == INFTY ) cout << "destination not reachable" << endl;
	else cout << "minimum time = " << cost << " sec" << endl;
    }
    return 0;
}
