#include<iostream>
#include<queue>
#include<map>
#include<cassert>
#define rep(i, n) for ( int i = 0; i < (int)n; i++ )
using namespace std;
#define MAX 30

int W, H;
char G[MAX][MAX];
int si, sj;

class State{
    public:
    int S[26], y, x;
    State(){}
    State(int y, int x): y(y), x(x){
	rep(i, 26) S[i] = 0;
    }

    void set( char ch ){
	if( 'a' <= ch && ch <= 'z' ){
	    S[ch-'a'] = (S[ch-'a']+1)%2;
	}
    }

    bool operator < ( const State &s ) const{
	if ( x != s.x ) return x < s.x;
	if ( y != s.y ) return y < s.y;
	for ( int i = 0; i < 26; i++ ){
	    if ( S[i] != s.S[i] ) return S[i] < s.S[i];
	}
	return false;
    }
};

bool possible( State u, char ch ){
    if ( ch == '#' ) return false;
    if ( ch == '<' || ch == '@' || ch == '.' ) return true;
    if ( 'a' <= ch && ch <= 'z' ) return true;
    assert( 'A' <= ch && ch <= 'Z' );
    return u.S[ch - 'A'] == 1;
}


int bfs( int si, int sj ){
    queue<State> Q;
    State s = State(si, sj);
    Q.push(s);
    map<State, bool> visited;
    map<State, int> D;
    D[s] = 0;

    State u, v;
    
    static const int dy[4] = {0, -1, 0, 1};
    static const int dx[4] = {1, 0, -1, 0};

    while( !Q.empty() ){
	u = Q.front(); Q.pop();
	if ( G[u.y][u.x] == '<' ) return D[u];
	int nx, ny;
	for ( int r = 0; r < 4; r++ ){
	    ny = u.y + dy[r];
	    nx = u.x + dx[r];
	    if ( possible( u, G[ny][nx] ) ){
		State v = u;
		v.y = ny;
		v.x = nx;
		v.set(G[ny][nx]);
		if (  D[v] == 0) {
		    D[v] = D[u]  + 1;
		    Q.push(v);
		}
	    }
	}
    }

    return -1;
}

int main(){
    while( cin >> W >> H && W ){
	rep(i, H) rep(j, W){
	    cin >> G[i][j];
	    if ( G[i][j] == '@' ) { si = i; sj = j; };
	}
	cout << bfs( si, sj ) << endl;
    }

    return 0;
}
