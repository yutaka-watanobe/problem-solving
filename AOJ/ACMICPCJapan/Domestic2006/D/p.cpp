// DFS (exhaustive search)
#include<iostream>
#include<algorithm>

using namespace std;

#define MAX 20
#define LIMIT 10
#define SPACE '0'
#define OBSTACLE '1'
#define START '2'
#define GOAL '3'
#define OUTSIDE '*'

struct Point{int i, j;};

int W, H, mincost;
Point start, goal;
char G[MAX+2][MAX+2];

void shot( Point pos, Point &next, char &target, int di, int dj ){
    int i = pos.i;
    int j = pos.j;
    while(1){
	i += di; j += dj;
	if ( G[i][j] != SPACE ){
	    next.i = i; next.j = j; target = G[i][j];
	    break;
	}
    }
}

void recursive( Point pos, int cost ){
    cost++;
    if ( cost > LIMIT ) return;
    
    static const int di[4] = {0, -1, 0, 1};
    static const int dj[4] = {1, 0, -1, 0};

    Point next;
    char target;

    for ( int r = 0; r < 4; r++ ){
	if ( G[pos.i + di[r]][pos.j + dj[r]] == OBSTACLE ) continue;

	shot( pos, next, target, di[r], dj[r] );

	if ( target == OUTSIDE ) continue;

	if ( target == GOAL ){
	    mincost = min( mincost, cost );
	    return;
	}

	G[next.i][next.j] = SPACE;
	next.i -= di[r];
	next.j -= dj[r];

	recursive( next, cost );

	next.i += di[r];
	next.j += dj[r];
	G[next.i][next.j] = OBSTACLE;
    }
}

void compute(){
    mincost = INT_MAX;
    recursive( start, 0 );
    cout << (( mincost > LIMIT ) ? -1 : mincost) << endl;
}

bool input(){
    cin >> W >> H;
    if ( W == 0 && H == 0 ) return false;
    for ( int i = 1; i <= H; i++ ){
	for ( int j = 1; j <= W; j++ ){
	    cin >> G[i][j];
	    if ( G[i][j] == '2' ) { start.i = i; start.j = j; G[i][j] = SPACE;}
	    if ( G[i][j] == '3' ) { goal.i = i; goal.j = j; }
	}
    }
    for ( int i = 0; i < H+2; i++ ) G[i][0] = G[i][W+1] = OUTSIDE;
    for ( int j = 0; j < W+2; j++ ) G[0][j] = G[H+1][j] = OUTSIDE;
    return true;
}

main(){
    while ( input() ) compute();
}
