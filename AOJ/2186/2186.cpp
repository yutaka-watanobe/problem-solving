#include<iostream>
using namespace std;
#define MAX 20
#define rep(i, n) for ( int i = 0; i < n; i++ )

void compute(){
    int gy, gx, n, sx, sy, tx, ty;
    bool G[MAX+1][MAX+1][MAX+1][MAX+1];
    int T[MAX+1][MAX+1];
    rep(i,MAX+1) rep(j,MAX+1) rep(k,MAX+1) rep(m,MAX+1) G[i][j][k][m] = false;
    rep(i, MAX+1) rep(j, MAX+1) T[i][j] = 0;
    cin >> gx >> gy >> n;
    rep(i, n){
	cin >> sx >> sy >> tx >> ty;
	G[sy][sx][ty][tx] = true;
	G[ty][tx][sy][sx] = true;
    }
    T[0][0] = 1;
    rep(y, gy+1) rep(x, gx+1){
	if ( x < gx && !G[y][x][y][x+1]) T[y][x+1] += T[y][x];
	if ( y < gy && !G[y][x][y+1][x]) T[y+1][x] += T[y][x];
    }

    if ( T[gy][gx] == 0 ) cout << "Miserable Hokusai!" << endl;
    else cout << T[gy][gx] << endl;
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) compute();
}

