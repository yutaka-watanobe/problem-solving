#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )

class Cube{
    public:
    string f, order;
    int y, x, p, c;
    Cube(int y=0, int x=0, string o=""):y(y), x(x), order(o){
	f = "rmbygc"; rep(i, 6) p = 0; c = 0;
    }
    void roll_y(){ roll(0, 2, 5, 3);}
    void roll_x(){ roll(0, 1, 5, 4);}
    void roll(int i, int j, int k, int l){
	char t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
    }
    void rolld(int r){
	if ( r == 0 ) rep(i, 3) roll_y();
	else if ( r == 1 ) roll_x();
	else if ( r == 2 ) roll_y();
	else rep(i, 3) roll_x();
    }
    bool operator < ( const Cube &c) const{
	if ( x != c.x ) return x < c.x;
	if ( y != c.y ) return y < c.y;
	if ( p != c.p ) return p < c.p;
	if ( f != c.f ) return f < c.f;
	return false;
    }
};

#define MAX 32
int W, H;
char G[MAX][MAX];

int bfs(Cube s){
    queue<Cube> Q;
    set<Cube> V;
    Q.push(s);
    V.insert(s);

    static const int dy[4] = {0, -1, 0, 1};
    static const int dx[4] = {1, 0, -1, 0};

    Cube u, v;
    int ny, nx;
    while(!Q.empty()){
	u = Q.front(); Q.pop();
	if ( u.p == 6 ) return u.c;
	rep(r, 4){
	    ny = u.y + dy[r];
	    nx = u.x + dx[r];
	    if ( G[ny][nx] == 'k' ) continue;
	    v = u;
	    v.rolld(r);
	    if ( G[ny][nx] == 'w' || G[ny][nx] == u.order[u.p] && v.f[0] == G[ny][nx]){
		v.c++;
		v.y = ny;
		v.x = nx;
		if ( G[ny][nx] != 'w' ) v.p++;
		if ( V.find(v) == V.end() ) {
		    V.insert(v);
		    Q.push(v);
		}
	    }
	}
    }
    return -1;
}

main(){
    Cube init;
    int y, x;
    string order;
    while( cin >> W >> H && W ){
	rep(i, H+2) rep(j, W+2) G[i][j] = 'k';
	for ( int i = 1; i <= H; i++ ){
	    for ( int j = 1; j <= W; j++ ){
		cin >> G[i][j];
		if ( G[i][j] == '#' ) {
		    G[i][j] = 'w';
		    y = i; x = j;
		}
	    }
	}
	cin >> order;
	Cube init = Cube(y, x, order);
	int cost = bfs(init);
	if ( cost == -1 ) cout << "unreachable" << endl;
	else cout << cost << endl;
    }
}
