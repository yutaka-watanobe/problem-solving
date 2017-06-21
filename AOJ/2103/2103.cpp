#include<iostream>
#include<string>
using namespace std;
#define REP(i, n) for ( int i = 0; i < (int)n; i++ )
#define FOR(i, s, e) for ( int i = s; i <= (int)e; i++ )
#define MAX 20



void simulate(){
int W, H;
    char G[MAX+2][MAX+2];
    cin >> H >> W;
    REP(i, H+2) G[i][0] = G[i][W+1] = '#';
    REP(j, W+2) G[0][j] = G[H+1][j] = '#';
    
    int y, x, d;

    FOR(i, 1, H) FOR(j, 1, W){
	cin >> G[i][j];
	if ( G[i][j] == '>' ) { y = i; x = j; d = 0; G[i][j] = '.';}
	if ( G[i][j] == '^' ) { y = i; x = j; d = 1; G[i][j] = '.';}
	if ( G[i][j] == '<' ) { y = i; x = j; d = 2; G[i][j] = '.';}
	if ( G[i][j] == 'v' ) { y = i; x = j; d = 3; G[i][j] = '.';}
    }

    //    FOR(i, 0, H+1){
    //    	FOR(j, 0, W+1) cout << G[i][j];
    //    	cout << endl;
    //    }

    int ncom; cin >> ncom;
    string com; cin >> com;

    static int dy[4] = {0, -1, 0, 1};
    static int dx[4] = {1, 0, -1, 0};

    int py, px;

    for ( int i = 0; i < com.size(); i++ ){
	char c = com[i];
	if ( c == 'U' ) {
	    d = 1;
	    if ( G[y+dy[d]][x+dx[d]] == '.' ) { y += dy[d]; x += dx[d]; }
	} else if ( c == 'D' ){
	    d = 3;
	    if ( G[y+dy[d]][x+dx[d]] == '.' ) { y += dy[d]; x += dx[d]; }
	} else if ( c == 'L' ){
	    d = 2;
	    if ( G[y+dy[d]][x+dx[d]] == '.' ) { y += dy[d]; x += dx[d]; }
	} else if ( c == 'R' ){
	    d = 0;
	    if ( G[y+dy[d]][x+dx[d]] == '.' ) { y += dy[d]; x += dx[d]; }
	} else if ( c == 'S' ){
	    py = y;
	    px = x;
	    while(1){
		py += dy[d];
		px += dx[d];
		if ( G[py][px] == '#' ) break;
		if ( G[py][px] == '*' ) {
		    G[py][px] = '.';
		    break;
		}
	    }
	}
    }

    char dir;
    if ( d == 0 ) dir = '>';
    if ( d == 1 ) dir = '^';
    if ( d == 2 ) dir = '<';
    if ( d == 3 ) dir = 'v';
    G[y][x] = dir;

    FOR(i, 1, H){
    	FOR(j, 1, W) cout << G[i][j];
    	cout << endl;
    }
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	if ( i ) cout << endl;
	simulate();
    }
    return 0;
}
