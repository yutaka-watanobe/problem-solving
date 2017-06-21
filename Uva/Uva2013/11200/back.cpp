#include<iostream>
#include<stdio.h>
#include<cassert>
using namespace std;
#define MAX 500
#define WALL 'X'
#define POS_UP 0
#define POS_DOWN 1
#define FROM_E 0
#define FROM_N 1
#define FROM_W 2
#define FROM_S 3

char G[MAX+2][MAX+2]; // grid
int W, H;

void input(){
    cin >> W >> H;
    for ( int i = 0; i < H + 2; i++ ) G[i][0] = G[i][W+1] = WALL;
    for ( int j = 0; j < W + 2; j++ ) {G[0][j] = WALL; G[H+1][j] =  ' ' ;}

    char ch; scanf("%c", &ch);
    for ( int i = 1; i <= H; i++ ){
	for ( int j = 1; j <= W; j++ ) {
	    scanf("%c", &G[i][j]);
	}
	scanf("%c", &ch);
    }
}

bool dfs( int i, int j, int pos, int from ){
    if ( i == H + 1 ) return true;

    if ( G[i][j] == '/' ){
	if ( pos == POS_UP ){
	    if ( G[i-1][j] != WALL && from != FROM_N && dfs(i-1, j, POS_DOWN, FROM_S) ) return true;
	    if ( G[i][j-1] != WALL ){
		if ( G[i][j-1] == '/' && from != FROM_W && dfs(i, j-1, POS_DOWN, FROM_E )) return true;
		else if ( G[i][j-1] == '\\' && from != FROM_W && dfs(i, j-1, POS_UP, FROM_E )) return true;
	    }
	} else if ( pos == POS_DOWN ){
	    if ( G[i+1][j] != WALL && from != FROM_S && dfs(i+1, j, POS_UP, FROM_N ) ) return true;
	    if ( G[i][j+1] != WALL ){
		if ( G[i][j+1] == '/' && from != FROM_E && dfs(i, j+1, POS_UP, FROM_W ) ) return true;
		else if ( G[i][j+1] == '\\' && from != FROM_E && dfs( i, j+1, POS_DOWN, FROM_W )) return true;
	    }
	}
    } else if ( G[i][j] == '\\' ){
	if ( pos == POS_UP ){
	    if ( G[i-1][j] != WALL && from != FROM_N && dfs(i-1, j, POS_DOWN, FROM_S) ) return true;
	    if ( G[i][j+1] != WALL ){
		if ( G[i][j+1] == '/' && from != FROM_E && dfs(i, j+1, POS_UP, FROM_W )) return true;
		else if ( G[i][j+1] == '\\' && from != FROM_E && dfs(i, j+1, POS_DOWN, FROM_W)) return true;
	    }
	} else if ( pos == POS_DOWN ){
	    if ( G[i+1][j] != WALL && from != FROM_S && dfs(i+1, j, POS_UP, FROM_N ) ) return true;
	    if ( G[i][j-1] != WALL ){
		if ( G[i][j-1] == '/' && from != FROM_W && dfs(i, j-1, POS_DOWN, FROM_E ) ) return true;
		else if ( G[i][j-1] == '\\' && from != FROM_W && dfs( i, j-1, POS_UP, FROM_E )) return true;
	    }
	}
    }
    
    return false;
}

void compute(){
    int count = 0;
    for ( int j = 1; j <= W; j++ ) {
	if ( dfs (1, j, POS_UP, FROM_N) ) count++;
    }
    printf("%d\n", count);
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	input();
	compute();
    }
}
