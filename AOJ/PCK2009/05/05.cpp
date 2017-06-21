#include<iostream>
#include<cassert>

using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define NMAX 200
#define MMAX 100
#define INFTY (1<<21)
int n, m, T[NMAX][NMAX], P[MMAX][MMAX];

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
    int tmp[MMAX][MMAX];
    int ly = INFTY, lx;
    rep(r, 4){
	valid(sx, sy, lx, ly);
	rep(y, m) rep(x, m) tmp[x][y] = P[x][y];
	rep(y, m) rep(x, m) P[y][m-x-1] = tmp[x][y];
    }
    if ( ly == INFTY ) return false;
    cout << lx+1 << " " << ly+1 << endl;
    return true;
}

void compute(){
    rep(y, n-m+1) rep(x, n-m+1) if ( rotate(x, y) ) return;
    cout << "NA" << endl;
}

void check(){
    rep(i, m){
	int sum = 0;
	rep(j, m) if (P[i][j] == -1) sum++;
	assert( sum != m );
    }
    rep(j, m){
	int sum = 0;
	rep(i, m) if (P[i][j] == -1) sum++;
	assert( sum != m );
    }

    int di[4] = {0, -1, 0, 1};
    int dj[4] = {1, 0, -1, 0};
    rep(i, m) rep(j, m){
	if ( P[i][j] == -1 ) continue;

	int sum = 0;
	rep(r, 4){
	    int ni = i + di[r];
	    int nj = j + dj[r];
	    if ( ni < 0 || nj < 0 || ni >= m || nj >= m ) continue;
	    sum++;
	}
	if ( m > 1 ) assert( sum > 0 ) ;
    }

}


main(){
    while( cin >> n >> m && n ){
	assert( 1 <= n && n <= 100);
	assert( 1 <= m && m <= 50);
	assert( n >= m );
	rep(y, n) rep(x, n) cin >> T[x][y];
	rep(y, m) rep(x, m) cin >> P[x][y];

	rep(y, n) rep(x, n) {
	    assert( 0 <=  T[x][y] && T[x][y] <= 15 );
	}
	rep(y, m) rep(x, m) {
	    if ( T[x][y] >= 0 ) assert( 0 <=  T[x][y] && T[x][y] <= 15 );
	}

	check();

	compute();
    }
}
