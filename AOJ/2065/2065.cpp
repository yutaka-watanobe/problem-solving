#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cassert>

using namespace std;
#define MAX 30
#define LIMIT 10

static const int STOP = 4;
static const int dx[4] = {1, 0, -1, 0};
static const int dy[4] = {0, -1, 0, 1};

class State{
    public:
    int y, x, dir, nman, from;
    set<int> M;
    State(){from = -1;}
    
    bool operator < ( const State &s ) const{
	if ( y != s.y ) return y < s.y;
	if ( x != s.x ) return x < s.x;
	if ( dir != s.dir ) return dir < s.dir;
	if ( nman != s.nman ) return nman < s.nman;
	set<int>::iterator it1, it2;
	for ( it1 = M.begin(), it2 = s.M.begin(); it1 != M.end(); it1++, it2++ ){
	    if ( *it1 == *it2 ) continue;
	    return *it1 < *it2;
	}
	return 0;
    }
};

char G[MAX][MAX];
bool visited[MAX][MAX];

int H, W;
int limit;

int getDirection( int d ){ 
    return (d+2)%4; // oposite direction
}

bool dfs( State u, map<State, bool> V ){
    if ( G[u.y][u.x] == '>' ) return true;
    if ( u.nman > limit ) return false;
    
    if ( V[u] ) return false;
    V[u] = true;
    
    visited[u.y][u.x] = true;

    int ny, nx;
    char tmp;

    State v;

    if ( u.dir == STOP ){
	for ( int d = 0; d < 4; d++ ){
	    ny = u.y + dy[d];
	    nx = u.x + dx[d];
	    if ( G[ny][nx] == '#' ){
		v = u;
		v.dir = getDirection(d);
		if ( v.dir != v.from &&  dfs( v, V ) ) return true;
	    } else if ( (G[ny][nx] == '_' ) && !visited[ny][nx]) {
		tmp = G[ny][nx];
		G[ny][nx] = '#';
		v = u;
		v.dir = getDirection(d);
		v.nman++;
		v.M.insert(ny*W+nx);
		if ( v.dir != v.from && dfs(v, V) ) return true;
		G[ny][nx] = tmp;
	    }
	}
    } else {
	ny = u.y + dy[u.dir];
	nx = u.x + dx[u.dir];
	if ( G[ny][nx] == '#'){
	    v = u;
	    v.dir = STOP;
	    v.from = getDirection(u.dir);
	    if ( dfs(v, V) ) return true;
	} else if ( G[ny][nx] == '_' || G[ny][nx] == '>' || G[ny][nx] == '^' ){
	    // no place
	    if ( G[ny][nx] == '_' || G[ny][nx] == '>'){
		v = u;
		v.y = ny;
		v.x = nx;
		if ( G[v.y][v.x] == '>' ) return true;
		if (  dfs(v, V) ) return true;
	    }
	    // place and stop
	    if ( G[ny][nx] == '_' && !visited[ny][nx]){
		v = u;
		v.dir = STOP;
		v.from = getDirection(u.dir);
		v.nman++;
		v.M.insert(ny*W+nx);
		tmp = G[ny][nx];
		G[ny][nx] = '#';
		if (  dfs(v, V) ) return true;
		G[ny][nx] = tmp;
	    }
	} else {
	    assert(false);
	}
    }

    visited[u.y][u.x] = false;
    return false;
}

void compute(int y, int x){
    for ( limit = 0; limit <= LIMIT; limit++ ){
	State state;
	state.y = y;
	state.x = x;
	state.dir = STOP;
	state.nman = 0;
	state.from = -1;
	for ( int i = 0; i < H; i++ ){
	    for ( int j = 0; j < W; j++ ) visited[i][j] = false;
	}

	if ( dfs(state, map<State, bool>()) ) {
	    cout << limit << endl; return;
	}
    }
}

int main(){
    int tcase; cin >> tcase;
    int y, x, dir;
    for ( int i = 0; i < tcase; i++ ){
	cin >> H >> W;
	for ( int i = 0; i < H; i++ ){
	    for ( int j = 0; j < W; j++ ){
		cin >> G[i][j];
		if ( G[i][j] == 'A' ){
		    G[i][j] = '_'; y = i; x = j;
		}
	    }
	}
	compute(y, x);
    }
    return 0;
}
