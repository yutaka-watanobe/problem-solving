#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<cassert>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )

static const int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
static const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};

class State{
    public:
    char G[5][5]; 
    int py, px, n;
    State(int n=0):n(n){}
    bool operator < ( const State &s) const{
	rep(i, n) rep(j, n){
	    if ( G[i][j] == s.G[i][j] ) continue;
	    return G[i][j] < s.G[i][j];
	}
	return false;
    }
    bool goal(){
	rep(i, n) rep(j, n) if ( G[i][j] == '#' ) return false;
	return true;
    }

    void activate(){
	char tmp[5][5];
	int nx, ny;
	rep(y, n) rep(x, n) tmp[y][x] = '.';
	rep(y, n) rep(x, n){
	    if ( G[y][x] == '@' ) {
		tmp[y][x] = '@';
		continue;
	    }
	    int cnt = 0;
	    rep(d, 8){
		ny = y + dy[d];
		nx = x + dx[d];
		if ( ny < 0 || nx < 0 || ny >= n || nx >= n ) continue;
		if ( G[ny][nx] == '#' || G[ny][nx] == '@' ) cnt++;

	    }
	    if ( G[y][x] == '#'){
		if ( cnt == 2 || cnt == 3 ) tmp[y][x] = '#';
	    } else {
		if ( cnt == 3 ) tmp[y][x] = '#';
	    }
	}
	rep(y, n) rep(x, n) G[y][x] = tmp[y][x];
    }
};

int bfs( int n, State source ){
    queue<State> Q;
    map<State, int> D;
    set<State> V;
    
    Q.push(source);
    D[source] = 0;
    V.insert(source);
    
    State u, v;
    int ny, nx;
    while(!Q.empty() ){
	u = Q.front(); Q.pop();
	if ( u.goal() ) return D[u];
	
	rep(d, 8){
	    ny = u.py + dy[d];
	    nx = u.px + dx[d];
	    if ( ny < 0 || nx < 0 || ny >= n || nx >= n ) continue;
	    if ( u.G[ny][nx] == '#' ) continue;
	    v = u;
	    v.G[u.py][u.px] = '.';
	    v.G[ny][nx] = '@'; v.py = ny; v.px = nx;
	    v.activate();
	    if ( V.insert(v).second ){
		V.insert(v);
		D[v] = D[u] + 1;
		Q.push(v);
	    }
	}
    }
    return -1;
}

main(){
    int n;
    State source;
    while( cin >> n && n ){
	source = State(n);
	rep(y, n) rep(x, n){
	    cin >> source.G[y][x];
	    if ( source.G[y][x] == '@' ){
		source.py = y;
		source.px = x;
	    }
	}
	cout <<  bfs(n, source) << endl;
    }
}
