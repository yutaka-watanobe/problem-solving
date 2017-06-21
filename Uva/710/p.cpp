// Simulation + PFS in Grid
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<queue>
#include<cassert>
#define MAX 80
#define SPACE ' '

using namespace std;

char G[MAX][MAX];

int W, H;

bool inGrid( int x, int y){
    return ( 0 <= x && 0 <= y && x < W+2 && y < H+2 );
}

int bfs( int x1, int y1, int x2, int y2 ){

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    queue<pair<int, int> > q;
    bool visited[ MAX ][ MAX ];
    int d[ MAX ][ MAX ];
    for ( int i = 0; i < H + 2; i++ ){
	for ( int j = 0; j < W + 2; j++ ){
	    d[i][j] = INT_MAX;
	}
    }

    q.push( make_pair(y1, x1));
    d[y1][x1] = 0;

    pair<int, int> u, v;

    int x, y, nx, ny;

    while ( !q.empty() ){
	u = q.front(); q.pop();

	y = u.first;
	x = u.second;

	if ( y == y2 && x == x2 ) return d[y][x];
	
	for ( int r = 0; r < 4; r++ ){
	    nx = x; ny = y;

	    while ( 1 ) {
		nx += dx[r];
		ny += dy[r];
		if ( inGrid(nx, ny) && ( G[ny][nx] == SPACE || ( nx == x2 && ny == y2 ) ) ){
		    if ( d[ny][nx] > d[y][x] + 1 ){
			d[ny][nx] = d[y][x] + 1;
			q.push( make_pair(ny, nx) );
		    }
		} else break;
	    }
	}
    }

    return -1;
}

void work(){
    string line;
    int x1, y1, x2, y2;
    for ( int i = 1; ; i++ ){
	cin >> x1 >> y1 >> x2 >> y2;  getline( cin , line );
	if ( x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 ) break;
	printf("Pair %d: ", i);
	int cost = bfs( x1, y1, x2, y2);
	if ( cost == -1 ) printf("impossible.\n");
	else {
	    printf("%d segments.\n", cost);
	}
    }
}

bool read(){
    string line;
    cin >> W >> H; getline( cin, line );
    if ( W == 0 && H == 0 ) return false;
    
    for ( int i = 0; i < H; i++ ){
	getline( cin, line );
	assert( line.size() == W );
	for ( int j = 0; j < W; j++ ){
	    G[i+1][j+1] = line[j];
	}
    }

    // banpei
    for ( int i = 0; i < H + 2; i++ ) G[i][0] = G[i][W+1] = SPACE;
    for ( int j = 0; j < W + 2; j++ ) G[0][j] = G[H+1][j] = SPACE;
    
    return true;
}

main(){
    for ( int i = 1; read(); i++ ){
	printf("Board #%d:\n", i);
	work();
	printf("\n");
    }
}
