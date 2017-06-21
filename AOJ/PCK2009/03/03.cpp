#include<iostream>
#include<cassert>
using namespace std;
#define MAX 100
static const int dx[4] = {1, 0, -1, 0};
static const int dy[4] = {0, -1, 0, 1};

int w, h, sx, sy, gx, gy, G[MAX+2][MAX+2];
 
bool dfs( int x, int y, int color ){
    if ( color == 0 || G[x][y] != color ) return false;
    if ( x == gx && y == gy ) return true;
    G[x][y] = 0;
    for ( int r = 0; r < 4; r++ ){
	if ( dfs(x + dx[r], y + dy[r], color) ) return true;
    }
    return false;
}

main(){
    int n, c, d, px, py, ww, hh;
    while( cin >> w >> h && w ){
	assert( 4 <= w && w <= 100);
	assert( 4 <= h && h <= 100);
	cin >> sx >> sy >> gx >> gy >> n;
	assert( 1 <= sx && sx <= w);
	assert( 1 <= sy && sy <= h);
	assert( 1 <= gx && gx <= w);
	assert( 1 <= gy && gy <= h);

	for ( int y = 0; y < h+2; y++ )
	    for ( int x = 0; x < w+2; x++ ) G[x][y] = 0;
	for ( int i = 1; i <=n; i++ ){
	    cin >> c >> d >> px >> py;
	    assert( 1 <= c && c <= 5 );
	    assert( d == 0 || d == 1 );
	    if ( d == 0 ) { ww = 4; hh = 2; }
	    else { ww = 2; hh = 4; }
	    for ( int y = 0; y <= hh-1; y++ ){
		for ( int x = 0; x <= ww-1; x++ ) {
		    assert( 1 <= px+x );
		    assert( 1 <= py+y );
		    assert( px+x <= w );
		    assert( py+y <= h );
		    assert(G[px+x][py+y] == 0 );
		    G[px+x][py+y] = c;
		}
	    }
	}
	if ( dfs(sx, sy, G[sx][sy]) ) cout << "OK" << endl;
	else cout << "NG" << endl;
    }
}
