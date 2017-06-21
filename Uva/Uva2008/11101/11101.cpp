#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
#define MAX 2001
typedef unsigned short ushort;
static const int INFTY = (1<<21);
int maxx, maxy;
ushort M[MAX][MAX];

void plot( int x1, int y1, int x2, int y2, int mole, queue<pair<int, int> > &Q){
    if ( x1 == x2 ){
	for ( int y = min(y1, y2); y <= max(y1, y2); y++ ){
	    M[y][x1] = mole;
	    if ( mole == 1 ) Q.push(make_pair(x1, y));
	}
    } else if (y1 == y2 ){
	for ( int x = min(x1, x2); x <= max(x1, x2); x++ ){
	    M[y1][x] = mole;
	    if ( mole == 1 ) Q.push(make_pair(x, y1));
	}
    }
}

int bfs( queue<pair<int, int> > Q ){
    static const int dy[4] = {0, 1, 0, -1};
    static const int dx[4] = {1, 0, -1, 0};
    ushort D[MAX][MAX];
    for ( int y = 0; y <= maxy; y++ )
	for (int x = 0; x <= maxx; x++ ) D[y][x] = INFTY;

    queue<pair<int, int> > TQ = Q;
    while( !TQ.empty() ){
	pair<int, int> p = TQ.front(); TQ.pop();
	D[p.second][p.first] = 0;
    }

    int nx, ny;
    pair<int, int> u;
    while(!Q.empty()){
	u = Q.front(); Q.pop();
	for ( int d = 0; d < 4; d++ ){
	    nx = u.first + dx[d];
	    ny = u.second + dy[d];
	    if ( nx < 0 || ny < 0 || maxx < nx || maxy < ny ) continue;
	    if ( M[ny][nx] == 2 ) return D[u.second][u.first]+1;
	    if ( M[ny][nx] == 0 ){
		M[ny][nx] = 1;
		D[ny][nx] = D[u.second][u.first]+1;
		Q.push(make_pair(nx, ny));
	    }
	}
    }
}

void input(int m, int mole, queue<pair<int, int> > &Q){
    int x, y, sx, sy, px, py;
    scanf("%d %d", &sx, &sy);
    px = sx; py = sy;
    maxx = max(maxx, px);
    maxy = max(maxy, py);
    for ( int i = 1; i < m; i++ ){
	scanf("%d %d", &x, &y);
	plot(px, py, x, y, mole, Q);
	maxx = max(maxx, x);
	maxy = max(maxy, y);
	px = x; py = y;
    }
    plot(px, py, sx, sy, mole, Q);
}

int main(){
    int m1, m2;

    while( scanf("%d", &m1) && m1 ){
	queue<pair<int, int> > Q;
	for ( int y = 0; y <= maxy; y++ )
	    for ( int x = 0; x <= maxx; x++ ) M[y][x] = 0;
	maxx = maxy = 0;

	input(m1, 1, Q);
	scanf("%d", &m2);
	input(m2, 2, Q);

	printf("%d\n", bfs(Q));
    }

    return 0;
}
