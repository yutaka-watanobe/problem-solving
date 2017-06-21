#include<iostream>
#include<cmath>
using namespace std;
#define LIMIT 30

struct Puzzle{ char cont[9]; int space; };

Puzzle puzzle;
int cost, path[LIMIT];
static const int dx[4] = {-1, 0, 1, 0};
static const int dy[4] = {0, -1, 0, 1};
static const char direction[4] = {'d', 'r', 'u', 'l'};

bool isTarget(){
    for ( int i = 0; i < 8; i++ ){
	if ( puzzle.cont[i] != '1' + i ) return false;
    }
    return true;
}

bool dfs(int depth, int prev){
    if ( isTarget() ) { cost = depth; return true;}
    if ( depth > LIMIT ) return false;

    int px, py, tx, ty;
    Puzzle tmp;
    px = puzzle.space / 3;
    py = puzzle.space % 3;

    for ( int r = 0; r < 4; r++ ){
	tx = px + dx[r];
	ty = py + dy[r];
	if ( max(prev, r) - min(prev, r) == 2 ) continue;
	if ( tx < 0 || ty < 0 || tx >= 3 || ty >= 3 ) continue;
	tmp = puzzle;
	puzzle.cont[px*3+py] = puzzle.cont[tx*3+ty];
	puzzle.cont[tx*3+ty] = 'x';
	puzzle.space = tx*3+ty;
	if ( dfs( depth+1, r ) ) { path[depth] = r; return true;}
	puzzle = tmp; // backtracking
    }
    return false;
}

main(){
    for ( int i = 0; i < 9; i++ ){
	cin >> puzzle.cont[i];
	if ( puzzle.cont[i] == 'x' ) puzzle.space = i;
    }
    if ( dfs(0, -100) ){ 
	for ( int i = 0; i < cost; i++ ) cout << direction[path[i]];
	cout << endl;
    } else {
	cout << "unsolvable" << endl;
    }
}
