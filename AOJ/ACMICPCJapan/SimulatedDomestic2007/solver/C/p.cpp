// Problem C: Surrounding Area
// @author yutaka
#include<iostream>
using namespace std;
#define MAX 50
#define SPACE 0
#define BLACK 1// black 01
#define WHITE 2// white 10  // both 11

int W, H;
int G[MAX+2][MAX+2], T[MAX+2][MAX+2];

void recursive( int i, int j, int symbol ){
    if ( G[i][j] == SPACE ) T[i][j] |= (1<<(symbol-1));

    static const int di[4] = {0, -1, 0, 1};
    static const int dj[4] = {1, 0, -1, 0};

    int ni, nj;
    for ( int r = 0; r < 4; r++ ){
	ni = i + di[r];
	nj = j + dj[r];
	if ( G[ni][nj] == SPACE ) {
	    if ( (T[ni][nj] & (1<<(symbol-1))) != (1<<(symbol-1)) ) 
		recursive( ni, nj, symbol );
	}
    }
}

void compute(){
    for ( int i = 1; i <= H; i++ )
	for ( int j = 1; j <= W; j++ )
	    if ( G[i][j] != SPACE ) recursive( i, j, G[i][j] );
    
    int countB, countW;
    countB = countW = 0;

    for ( int i = 1; i <= H; i++ ){
	for ( int j = 1; j <= W; j++ ){
	    if ( T[i][j] == BLACK ) countB++;
	    if ( T[i][j] == WHITE ) countW++;
	}
    }
    
    cout << countB << " " << countW << endl;
}

bool input(){
    char ch;
    cin >> W >> H;
    if ( W == 0 && H == 0 ) return false;
    for ( int i = 0; i < H + 2; i++ ) G[i][0] = G[i][W+1] = BLACK+WHITE;
    for ( int j = 0; j < W + 2; j++ ) G[0][j] = G[H+1][j] = BLACK+WHITE;
    for ( int i = 1; i <= H; i++ ){
	for ( int j = 1; j <= W; j++ ){
	    cin >> ch;
	    if ( ch == 'B' ) G[i][j] = BLACK;
	    else if ( ch == 'W' ) G[i][j] = WHITE;
	    else G[i][j] = SPACE;
	    T[i][j] = 0;
	}
    }
    
    return true;
}

main(){
    while ( input() ) compute();
}
