#include<iostream>
#include<cassert>
using namespace std;
#define REP(i, n) for ( int i = 0; i < (int)n; i++ )
#define MAX 100

int H, W;
char G[MAX][MAX];

void compute(){
    int y, x;
    y = x = 0;
    bool V[MAX][MAX];
    REP(i, H) REP(j, W) V[i][j] = false;

    while(1){
	V[y][x] = true;
	if ( G[y][x] == '.' ) {
	    cout << x << " " << y << endl;
	    return;
	}

	if ( G[y][x] == '<' ) x--;
	else if ( G[y][x] == '^' ) y--;
	else if ( G[y][x] == '>' ) x++;
	else if ( G[y][x] == 'v' ) y++;

	assert(!( x < 0 || y < 0 || x >= W || y >= H ));

	if ( V[y][x] ) {
	    cout << "LOOP" << endl; 
	    return;
	}
    }
}

int main(){
    while(1){
	cin >> H >> W;
	if ( H == 0 && W == 0 ) break;
	REP(i, H) REP(j, W) cin >> G[i][j];
	compute();
    }
    return 0;
}

