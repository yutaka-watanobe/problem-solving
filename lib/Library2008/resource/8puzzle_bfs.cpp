#include<iostream>
#include<cmath>
#include<string>
#include<map>
#include<queue>
using namespace std;
#define LIMIT 30

struct Puzzle{
    char cont[9];
    int space;
    string path;
    bool operator < ( const Puzzle &p ) const{
	for ( int i = 0; i < 9; i++ ){
	    if ( cont[i] == p.cont[i] ) continue;
	    return cont[i] > p.cont[i];
	}
	return false;
    }
};

int limit;
static const int dx[4] = {-1, 0, 1, 0};
static const int dy[4] = {0, -1, 0, 1};
static const char direction[4] = {'d', 'r', 'u', 'l'};

bool isTarget(Puzzle puzzle){
    for ( int i = 0; i < 8; i++ ){
	if ( puzzle.cont[i] != '1' + i ) return false;
    }
    return true;
}

void bfs(Puzzle s){
    queue<Puzzle> Q;
    map<Puzzle, bool> V;
    Puzzle u, v;
    s.path = "";
    Q.push(s);
    V[s] = true;

    while( !Q.empty() ){
	u = Q.front(); Q.pop();
	if ( isTarget(u) ){
	    cout << u.path << endl;
	    return;
	} else if ( u.path.size() > LIMIT ) break;

	int sx, sy, tx, ty;
	sx = u.space/3;
	sy = u.space%3;

	for ( int r = 0; r < 4; r++ ){
	    tx = sx + dx[r];
	    ty = sy + dy[r];
	    if ( tx < 0 || ty < 0 || tx >= 3 || ty >= 3 ) continue;
	    v = u;
	    v.cont[u.space] = u.cont[tx*3+ty];
	    v.cont[tx*3+ty] = 'x';
	    v.space = tx*3+ty;
	    if ( !V[v] ){
		V[v] = true;
		v.path += direction[r];
		Q.push(v);
	    }
	}
    }
    cout << "unsolvable" << endl;
}

main(){
    Puzzle in;
    for ( int i = 0; i < 9; i++ ){
	cin >> in.cont[i];
	if ( in.cont[i] == 'x' ) {
	    in.space = i;
	}
    }
    
    bfs(in);
}
