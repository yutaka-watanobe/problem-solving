#include<iostream>
#include<string>
#define MAX 100
using namespace std;
#define GROUND '.'
#define CASTLE '&'
#define MOAT '#'
#define INFTY (1<<21)

int H, W;
char G[MAX+2][MAX+2]; 
int T[MAX+2][MAX+2];
pair<int, int> castle;

bool fill( int i, int j, int color, char target ){
    T[i][j] = color;
    if ( i == 0 || j == 0 || i == H + 1 || j == W + 1 ) return true;
    static const int di[4] = {0, -1, 0, 1};
    static const int dj[4] = {1, 0, -1, 0};
    int ni, nj;
    for ( int r = 0; r < 4; r++ ){
	ni = i + di[r]; nj = j + dj[r];
	if ( (G[ni][nj] == target && T[ni][nj] == INFTY) || T[ni][nj] < color ){
	    if ( fill( ni, nj, color, target ) ) return true;
	}
    }
    return false;
}

int compute(){
    int color = 0;

    for ( int i = 0; i < H + 2; i++ ){
	for ( int j = 0; j < W + 2; j++ ) T[i][j] = INFTY;
    }

    while(1){
	if ( fill( castle.first, castle.second, color, GROUND ) ) return color;
	color++;
	if ( fill( castle.first, castle.second, color, MOAT ) ) return color;
	color++;
    }
}

bool initialize(){
    cin >> W >> H;
    if ( W == 0 && H == 0 ) return false;
    for ( int i = 0; i < H + 2; i++ ) G[i][0] = G[i][W+1] = GROUND;
    for ( int j = 0; j < W + 2; j++ ) G[0][j] = G[H+1][j] = GROUND;

    for ( int i = 1; i <= H; i++ ){
	for ( int j = 1; j <= W; j++ ) {
	    cin >> G[i][j];
	    if ( G[i][j] == CASTLE ) {
		castle = make_pair(i, j);
		G[i][j] = GROUND;
	    }
	}
    }
    return true;
}

main(){
    while(initialize()){
      	cout << compute()/2 << endl;
    }
}
