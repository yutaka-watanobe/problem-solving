#include<iostream>
#include<cassert>
using namespace std;
#define BLACK 0
#define WHITE 1
#define SPACE 2
int n, m, p;
int board[7][7][7], zsize[7][7];
static const int dx[13] = {0, -1, -1, -1, -1, 0, 1, 0, 0, -1, -1, 1, 1};
static const int dy[13] = {1, 1, 0, -1, 0, 0, 0, 1, -1, 1, -1, -1, 1};
static const int dz[13] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

bool in( int a ){ return (0 <= a && a < n); }

int parse( int x, int y, int z, int d ){
    int nx, ny, nz;
    int sum = 0;
    nx = x; ny = y; nz = z;
    while( in(nx) && in(ny) && in(nz) && board[nx][ny][nz] == board[x][y][z]){
	sum++;
	nx += dx[d]; ny += dy[d]; nz += dz[d];
    }
    nx = x; ny = y; nz = z;
    while( in(nx) && in(ny) && in(nz) && board[nx][ny][nz] == board[x][y][z]){
	sum++;
	nx -= dx[d]; ny -= dy[d]; nz -= dz[d];
    }
    return sum - 1;
}

void simulate(){
    for ( int x = 0; x < n; x++ ){
	for ( int y = 0; y < n; y++ ){
	    zsize[x][y] = 0;
	    for ( int z = 0; z < n; z++ ) board[x][y][z] = SPACE;
	}
    }
    int move = 0;
    bool isDraw = true;
    int x, y;
    for ( int i = 0; i < p; i++ ){
	cin >> x >> y; x--; y--;
	if ( !isDraw ) continue;
	board[x][y][zsize[x][y]++] = ((++move)%2);
	for ( int d = 0; d < 13; d++ ){
	    if ( parse( x, y, zsize[x][y]-1, d ) >= m )	isDraw = false; 
	}
    }
    
    if ( isDraw ) cout << "Draw" << endl;
    else {
	cout << ((move%2 == 1) ? "Black" : "White") << " " << move << endl;
    }
}

main(){
    while ( cin >> n >> m >> p, (n || m || p) ) simulate();
}
