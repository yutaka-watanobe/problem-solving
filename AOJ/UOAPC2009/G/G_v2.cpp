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

class Seg{
    public:
    Point P[2];
    bool finished;
    Seg(){}
    Seg( Point p1, Point p2 ){
	P[0] = p1; P[1] = p2;
	finished = false;
    }
};

char G[MAX][MAX], in[MAX][MAX];
Point C[CMAX];
Point P[PMAX];

int PT[MAX][MAX];

int H, W, ncity, nsource;

Seg S[CMAX];
int nseg;
int limit;

int initialW;

// for dfs
int sy, sx, ty, tx;

void print(){
    rep(i, H){
	rep(j, W){
	    cout << G[i][j];
	}
	cout << endl;
    }
}

// 0 nothing
// 1 only one P
// 2 W or morethan 2 P
int canGo( int i, int j, int from, int &d ){
    int np = 0;
    for ( int r = 0; r < 4; r++ ){
	if ( r == from ) continue;
	char ch = G[i + dy[r]][j + dx[r]];
	if ( ch == 'P' ) { np++; d = r; }
	if ( ch == 'W') return 2;
    }
    if ( np >= 2 ) return 2;
    if ( np == 1 ) return 1;
    return 0;
}

int getDist( Point p1, Point p2 ){
    return max(p1.y, p2.y)-min(p1.y,p2.y) + max(p1.x, p2.x)-min(p1.x, p2.x);
}

int getMD(){
    int md = 0;
    for ( int s = 0; s < nseg; s++ ){
	if ( S[s].finished ) continue;

	int d = 100;
	for ( int t = 0; t < nseg; t++ ){
	    if ( s == t || S[t].finished ) continue;

	    d = min(d, getDist(S[s].P[0], S[t].P[0])); 
	    d = min(d, getDist(S[s].P[0], S[t].P[1]));
	    d = min(d, getDist(S[s].P[1], S[t].P[0]));
	    d = min(d, getDist(S[s].P[1], S[t].P[1]));
	}

	for ( int p = 0; p < nsource; p++ ){
	    d = min(d, getDist(S[s].P[0], P[p])); 
	    d = min(d, getDist(S[s].P[1], P[p]));
	}
	d/=2;
	md+=d;

    }
    //    return 0;
    //        cout << md << endl;
    return md;
}

bool rec( int depth, int remain ){
    //        print();
    if ( remain == 0 ) return true;
    if ( depth + remain > limit ) return false;
    //    if ( depth + getMD() > limit ) return false;
    int ni, nj;
    char tmp;
    int ty, tx;

    for ( int s = 0; s < nseg; s++ ){
	if ( S[s].finished ) continue;
	for ( int p = 0; p < 2; p++ ){
	    Point u = S[s].P[p];
	    for ( int r = 0; r < 4; r++ ){
		ni = u.y + dy[r]; nj = u.x + dx[r];
		if ( G[ni][nj] != '.' ) continue;
		int d;
		int state = canGo(ni, nj, (r+2)%4, d);
		if ( state == 2 ) continue;
		int nremain = remain;
		G[ni][nj] = 'W';
		S[s].P[p].y = ni;
		S[s].P[p].x = nj;

		int pi;
		if ( state == 1 ){
		    assert(G[ni+dy[d]][nj+dx[d]] == 'P' );
		    pi = PT[ni+dy[d]][nj+dx[d]];
		    
		    G[ni+dy[d]][nj+dx[d]] = 'W'; // P -> W
		    G[S[s].P[(p+1)%2].y][S[s].P[(p+1)%2].x] = 'P'; // W -> P;

		    P[pi] = Point(S[s].P[(p+1)%2].y, S[s].P[(p+1)%2].x);
		    PT[S[s].P[(p+1)%2].y][S[s].P[(p+1)%2].x] = pi;

		    nremain--;
		    S[s].finished = true;
		}
		if ( rec( depth+1, nremain ) ) return true;

		G[ni][nj] = '.';
		S[s].P[p].y = u.y;
		S[s].P[p].x = u.x;
		if ( state == 1 ){
		    G[ni+dy[d]][nj+dx[d]] = 'P'; // W -> P
		    G[S[s].P[(p+1)%2].y][S[s].P[(p+1)%2].x] = 'W'; // P -> W;
		    S[s].finished = false;
		    P[pi] = Point(ni+dy[d], nj+dx[d]);
		    PT[ni+dy[d]][nj+dx[d]] = pi;
		}


	    }
	    //	    return false;
	    if ( in[u.y][u.x] == '.' ) return false;
	}
    }
    return false;
}

void idp(){
    // initail process
    int ns = nseg;
    for ( int s = 0; s < ns; s++ ){
	int n = 0;
	for ( int p = 0; p < 2; p++ ){
	    for ( int r = 0; r < 4; r++ ){
		if ( G[S[s].P[p].y+dy[r]][S[s].P[p].x+dx[r]] == 'P' ){
		    G[S[s].P[p].y+dy[r]][S[s].P[p].x+dx[r]] = 'W';
		    G[S[s].P[p].y][S[s].P[p].x] = 'P';
		    n++;
		    S[s].finished = true;
		    nseg--;
		}
	    }
	}
	assert( n <= 1 );
    }


    for ( limit = 0; limit <= LIMIT; limit++ ){
	//	cout << "limit = " << limit << endl;
	if ( rec( 0, nseg ) ){
	    cout << limit + initialW << endl;
	    return ;
	}
    }
    assert( false );
}

void dfs( int y, int x){
    G[y][x] = 'W';
    initialW++;
    int np = 0;
    rep(r, 4) {
	char ch = G[y+dy[r]][x+dx[r]];
	if ( G[y+dy[r]][x+dx[r]] == '*' ) {
	    dfs(y+dy[r], x+dx[r]);
	}
	if ( ch == '.' || ch == 'P' || ch == '#' ) np++;
    }
    if ( np >= 3 ){
	if ( sy == -1 ){ 
	    sy = y; sx = x;
	    ty = y; tx = x;
	} else {
	    ty = y; tx = x;
	}
    }
}

void makeSeg(){
    nseg = 0;
    initialW = 0;
    rep(i, H+2) rep(j, W+2){
	if ( G[i][j] == '*'){
	    sy = -1;
	    dfs(i, j);
	    S[nseg++] = Seg(Point(sy, sx), Point(ty, tx));
	}
    }
        return;
    print();

    cout << "initial seg" << endl;
    for ( int i = 0; i < nseg; i++ ){
	Point p1 = S[i].P[0];
	Point p2 = S[i].P[1];
	cout << "(" << p1.y << "," << p1.x << ")";
	cout << "(" << p2.y << "," << p2.x << ")" << endl;
    }
}

void compute(){
    makeSeg();
    idp();
}

int main(){
    while( cin >> H >> W && H ){
	ncity = 0;
	nsource = 0;
	for ( int i = 0; i < H; i++ ){
	    for ( int j = 0; j < W; j++ ){
		cin >> G[i][j];
		in[i][j] = G[i][j];
		if ( G[i][j] == '*' ) {
		    C[ncity++] = Point(i, j);
		} else if ( G[i][j] == 'P' ){
		    P[nsource++] = Point(i, j);
		    PT[i][j] = nsource-1;
		}
	    }
	}
	compute();
    }
    return 0;
}
