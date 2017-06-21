#include<iostream>
#include<queue>
#include<cassert>

#define rep(i, n) for ( int i = 0; i < n; i++ )
using namespace std;
#define MAX 10
#define PMAX 10
#define CMAX 10
#define LIMIT 50

static const int dy[4] = {0, -1, 0, 1};
static const int dx[4] = {1, 0, -1, 0};

class Point{
    public: 
    int y, x;
    Point(){}
    Point ( int y, int x ): y(y), x(x){}
};

char G[MAX][MAX], in[MAX][MAX];
Point C[CMAX];
Point P[PMAX];
int limit;
int H, W, ncity, nsource;

bool rec( int);

void print(){
    rep(i, H){
	rep(j, W){
	    cout << G[i][j];
	}
	cout << endl;
    }
}

bool canGo( int y, int x, int from ){
    int np = 0;
    for ( int r = 0; r < 4; r++ ){
	if ( r == from ) continue;
	char ch = G[y + dy[r]][x + dx[r]];
	if ( ch == 'P'|| ch == '*' ) np++;
	if ( ch == 'W') return false;
    }
    if ( np >= 2 ) return false;
    return true;
}

bool dfs( int y, int x, int depth, int sy, int sx ){
    //                    print();
    if ( depth > limit ) return false;

    char tmp;

    int ny, nx;
    for ( int r = 0; r < 4; r++ ){
	ny = y + dy[r];
	nx = x + dx[r];
	//if ( G[ny][nx] == 'P' || G[ny][nx] == '*' ) {
	if ( G[ny][nx] == 'P' ) {
	    tmp = G[ny][nx];
	    if ( tmp == 'P' ){
		G[ny][nx] = 'W';
		G[sy][sx] = 'P';
		if ( rec( depth ) ) return true;
		G[ny][nx] = 'P';
		G[sy][sx] = 'W';
		return false;
	    }


	    G[ny][nx] = 'W';
	    if( dfs( ny, nx, depth+1, sy, sx ) ) return true;
	    G[ny][nx] = tmp;
	    return false;
	}
    }

    for ( int r = 0; r < 4; r++ ){
	ny = y + dy[r];
	nx = x + dx[r];
	if ( G[ny][nx] == 'W' || G[ny][nx] == '#' ) continue;
	if ( !canGo(ny, nx, (r+2)%4 )) continue;
	tmp = G[ny][nx];
	if ( tmp == 'P' ){
		G[ny][nx] = 'W';
		G[sy][sx] = 'P';
		if ( rec( depth+1 ) ) return true;
		G[ny][nx] = 'P';
		G[sy][sx] = 'W';
		return false;
	    }

	G[ny][nx] = 'W';
	if ( dfs( ny, nx, depth+1, sy, sx) ) return true;
	G[ny][nx] = tmp;
    }

    return false;
}

bool rec(int depth){
    rep(i, H) rep(j, W){
	if ( G[i][j] != '*' ) continue;
	G[i][j] = 'W';
	if ( dfs( i, j, depth+1, i, j ) ) return true;
	G[i][j] = '*';
	return false;
    }
    return true;
}

void compute(){
    for ( limit = 0; limit <= LIMIT; limit++ ){
	if ( rec(0) ){
	    cout << limit << endl; return;
	}
    }
    //    assert(false);
}

int main(){
    int tcase = 0;
    while( cin >> H >> W && H ){
	tcase++;
	ncity = 0;
	nsource = 0;
	rep(i, H) rep(j, W){
	  cin >> G[i][j];
	  in[i][j] = G[i][j];
	  if ( G[i][j] == '*' ) {
	    C[ncity++] = Point(i, j);
	  } else if ( G[i][j] == 'P' ){
	    P[nsource++] = Point(i, j);
	    //	    PT[i][j] = nsource-1;
	  }
	}
	//	if ( tcase == 33 ) print();
	compute();
    }
    return 0;
}
