#include<iostream>
using namespace std;

#define REP(i, n) for ( int i = 0; i < n; i++ )
#define MAX 15
#define INFTY (1<<21)

int row, col, scol;
char C[MAX][MAX];
int D[MAX][MAX];

void compute(){
    REP(i, row) REP(j, col) D[i][j] = INFTY;

    int y, x, ny, nx; // i, j
    y = 0; x = scol;
    D[y][x] = 0;
    
    while(1){
	nx = x;
	ny = y;
	if ( C[ny][nx] == 'E' ) nx++;
	else if ( C[ny][nx] == 'N' ) ny--;
	else if ( C[ny][nx] == 'W' ) nx--;
	else if ( C[ny][nx] == 'S' ) ny++;

	if ( nx < 0 || ny < 0 || ny >= row || nx >= col ){
	    cout << D[y][x]+1 << " step(s) to exit" << endl;
	    break;
	} else if ( D[ny][nx] != INFTY ){
	    cout << D[ny][nx] << " step(s) before a loop of " << D[y][x]-D[ny][nx]+1 << " step(s)" << endl; 
	    break;
	}

	D[ny][nx] = D[y][x] + 1;
	y = ny;
	x = nx;
    }
}

int main(){
    while( cin >> row >> col >> scol ){
	if ( row == 0 && col == 0 && scol == 0 ) break;
	scol--;
	REP(i, row) REP(j, col) cin >> C[i][j];
	compute();
    }
}
