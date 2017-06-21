#include<iostream>
using namespace std;
#define MAX 100
#define REP(i,e) for( int i = 1; i <= (int)e; i++ )

int H, W, Q;
char G[MAX+2][MAX+2];

int search( int r, int c){
    int width = 1;
    char target = G[r][c];
    while(1){
	for ( int i = r; i < r+width; i++ ){
	    if ( G[i][c] != target || G[i][c+width-1] != target ) return width - 2;
	}
	for ( int j = c; j < c+width; j++ ){
	    if ( G[r][j] != target || G[r+width-1][j] != target ) return width - 2;
	}
	r--; c--;
	width += 2;
    }
}

void compute(){
    int r, c;
    cout << H << " " << W << " " << Q << endl;
    REP(i, Q) {
	cin >> r >> c;
	cout << search(r+1, c+1) << endl;
    }
}

void input(){
    cin >> H >> W >> Q;
    REP(i, H) REP(j, W) cin >> G[i][j];
    for ( int i = 0; i < H+2; i++ ) G[i][0] = G[i][W+1] = ' ';
    for ( int j = 0; j < W+2; j++ ) G[0][j] = G[H+1][j] = ' ';
}

main(){
    int tcase;  cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	input();
	compute();
    }
}
