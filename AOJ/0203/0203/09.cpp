#include<iostream>
using namespace std;
#define rep(i,s,e) for ( int i = s; i <= e; i++)
#define MAX 15
#define TREE 1
#define JUMP 2
#define SNOW 0
int X, Y;
int G[MAX+2][MAX+2];

int compute(){
    int T[MAX+2][MAX+2];
    rep(y,0,Y+1) rep(x,0,X+1) T[y][x] = 0;
    // from first
    rep(x,1,X){
	if ( G[0][x] == TREE || G[0][x] == JUMP ) continue;
	int s = -1, t = 1;
	if ( 0 == Y-1 ) s = t = 0;
	rep(dx,s,t){ // G[0][x] == SNOW
	    if ( G[1][x+dx] == SNOW ) T[1][x+dx]++;
	    if ( G[1][x+dx] == JUMP && dx == 0 ) T[1][x+dx]++;
	}
    }

    rep(y,1,Y-1) rep(x,1,X){
	if ( G[y][x] == SNOW ){
	    int s = -1, t = 1;
	    if ( y == Y-1 ) s = t = 0;
	    rep(dx,s,t){
		if ( G[y+1][x+dx] == SNOW ) T[y+1][x+dx] += T[y][x];
		if ( G[y+1][x+dx] == JUMP && dx == 0 ) T[y+1][x+dx] += T[y][x];
	    }
	} else if ( G[y][x] == JUMP ){
	    if ( G[y+2][x] != TREE ) T[y+2][x] += T[y][x];
	}
    }

    int sum = 0;
    rep(y,Y,Y+1) rep(x,1,X) sum += T[y][x];
    return sum;
}

main(){
    while( cin >> X >> Y && X && Y ){
	rep(y,0,Y-1) rep(x,0,X+1) G[y][x] = TREE;
	rep(y,Y,Y+1) rep(x,0,X+1) G[y][x] = SNOW;
	rep(y,0,Y-1) rep(x,1,X) cin >> G[y][x];
	cout << compute() << endl;
    }
}
