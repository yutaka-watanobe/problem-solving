#include<iostream>
#include<cmath>
using namespace std;
#define LIMIT 30

struct Puzzle{ char cont[9]; int space; };

Puzzle puzzle;
int limit, path[LIMIT], MD[9][9];
static const int dx[4] = {-1, 0, 1, 0};
static const int dy[4] = {0, -1, 0, 1};
static const char direction[4] = {'d', 'r', 'u', 'l'};

int getHeuristic(){
    int sum = 0;
    for ( int i = 0; i < 9; i++ ){
	if ( puzzle.cont[i] == 'x' ) continue;
	sum += MD[i][puzzle.cont[i]-'1'];
    }
    return sum;
}

bool isTarget(){
    for ( int i = 0; i < 8; i++ ){
	if ( puzzle.cont[i] != '1' + i ) return false;
    }
    return true;
}

bool dfs(int depth, int prev){
    if ( isTarget() ) return true;
    if ( depth + getHeuristic() > limit ) return false;

    int px, py, tx, ty;
    Puzzle tmp;
    px = puzzle.space / 3;
    py = puzzle.space % 3;

    for ( int r = 0; r < 4; r++ ){
	tx = px + dx[r];
	ty = py + dy[r];
	if ( max(prev, r)-min(prev, r) == 2 ) continue;
	if ( tx < 0 || ty < 0 || tx >= 3 || ty >= 3 ) continue;
	tmp = puzzle;
	puzzle.cont[px*3+py] = puzzle.cont[tx*3+ty];
	puzzle.cont[tx*3+ty] = 'x';
	puzzle.space = tx*3+ty;
	if ( dfs( depth+1, r ) ) { path[depth] = r; return true;}
	puzzle = tmp;
    }
    return false;
}

void solve(){
    for ( limit = getHeuristic(); limit <= LIMIT; limit += 2 ){
	if ( dfs(0, -100) ){
	    for ( int i = 0; i < limit; i++ ) cout << direction[path[i]];
	    cout << endl;
	    return;
	}
    }
    cout << "unsolvable" << endl;
}

void input(){
    for ( int i = 0; i < 9; i++ ){
	cin >> puzzle.cont[i]; cout << puzzle.cont[i] << " ";
	if ( puzzle.cont[i] == 'x' ) puzzle.space = i;
    }
    cout << endl;
}

main(){
    for ( int i = 0; i < 9; i++ ){
	for ( int j = 0; j < 9; j++ ){
	    MD[i][j] = abs(i/3-j/3) + abs(i%3-j%3);
	}
    }
    input();
    solve();
}
