#include<cstdio>

#define rep(i, n) for ( int i = 0; i < n; i++ )
#define MAX 200
#define INFTY (1<<21)
int n, m, T[MAX][MAX], P[MAX][MAX];

void valid(int sx, int sy, int &lx, int &ly ){
    int ax = -1, ay;
    rep(y, m) rep(x, m){
	if ( P[x][y] == -1 ) continue;
	if ( P[x][y] != T[sx+x][sy+y] ) return;
	if ( ax == -1 ) {ay = y; ax = x;}
    }
    if ( ay < ly || (ay == ly && ax < lx) ) {ly = sy+ay; lx = sx+ax; }
}

bool rotate(int sx, int sy){
    int tmp[MAX][MAX];
    int ly = INFTY, lx;
    rep(r, 4){
	valid(sx, sy, lx, ly);
	rep(y, m) rep(x, m) tmp[x][y] = P[x][y];
	rep(y, m) rep(x, m) P[y][m-x-1] = tmp[x][y];
    }
    if ( ly == INFTY ) return false;
    printf("%d %d\n", lx+1, ly+1);
    return true;
}

void compute(){
    rep(y, n-m+1) rep(x, n-m+1) if ( rotate(x, y) ) return;
    printf("NA\n");
}

main(){
    while( scanf("%d %d", &n, &m) && n ){
	rep(y, n) rep(x, n) scanf("%d", &T[x][y]);
	rep(y, m) rep(x, m) scanf("%d", &P[x][y]);
	compute();
    }
}
