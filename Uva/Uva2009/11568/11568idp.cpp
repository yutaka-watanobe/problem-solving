#include<iostream>
#include<string>
#include<cassert>
using namespace std;
#define rep(i, n) for ( int i = 0; i <(int)n; i++)

#define MAX 10
#define EAST 0
#define NORTH 1
#define SOUTH 2
#define WEST 3
#define LIMIT 10

static const int dy[5] = {0, -1, 1, 0, 0};
static const int dx[5] = {1, 0, 0, -1, 0};

struct Robot{
    int y, x, d;
};

char G[MAX][MAX];
int color_row[MAX][MAX];
int color_col[MAX][MAX];

int N, ty, tx;
int limit;

void rotate( int &d ){
    if ( d == EAST ) d = SOUTH;
    else if ( d == NORTH ) d = EAST;
    else if ( d == SOUTH ) d = WEST;
    else if ( d == WEST ) d = NORTH;
}

void moveRobot( int py, int px, Robot &r ){
    assert( !( py == r.y && px == r.x ));
    int ny, nx;
    if ( py == r.y && color_row[py][px] == color_row[py][r.x] ){
	if ( px < r.x ) { r.d = WEST; r.x--; }
	else { r.d = EAST; r.x++; }
    } else if ( px == r.x && color_col[py][px] == color_col[r.y][px] ){
	if ( py < r.y ) { r.d = NORTH; r.y--; }
	else { r.d = SOUTH; r.d++; }
    } else { // normal wondering
	ny = r.y + dy[r.d];
	nx = r.x + dx[r.d];
	if ( G[ny][nx] == '#' || ny == ty && nx == tx ) {
	    int cnt = 0;
	    while ( G[ny][nx] == '#' || ny == ty && nx == tx ) {
		rotate(r.d);
		ny = r.y + dy[r.d];
		nx = r.x + dx[r.d];
		cnt++;
		if ( cnt > 4 ) break;
	    }
	    r.y = ny;
	    r.x = nx;
	} else {
	    r.y = ny;
	    r.x = nx;
	}
    }
}

int getMD( int py, int px ){
    return max(py, ty)-min(py, ty) + max(px, tx)-min(px, tx);
}

bool dfs(int depth,  int py, int px, Robot R[2] ){
    if ( py == ty && px == tx ){
	cout << depth;
	return true;
    }
    if ( depth > limit + getMD(py, px)) return false;

    int ny, nx;
    Robot tmp[2];

    for ( int r = 0; r < 5; r++ ){
	ny = py + dy[r];
	nx = px + dx[r];
	if ( G[ny][nx] == '#' || R[0].y == ny && R[0].x == nx || R[1].y == ny && R[1].x == nx ) continue;

	tmp[0] = R[0]; tmp[1] = R[1];

	moveRobot( ny, nx, tmp[0] );
	moveRobot( ny, nx, tmp[1] );

	if ( py == tmp[0].y && px == tmp[0].x || py == tmp[1].y && px == tmp[1].x ) continue;

	if ( dfs( depth + 1, ny, nx, tmp) ) return true;
    }
    return false;
}

void compute(int py, int px, Robot R[2]){
    for ( limit = 0; limit <= LIMIT; limit++ ){
	if ( dfs(0, py, px, R) ){
	    cout << endl;
	    return;
	}
    }
    cout << "You can't escape..." << endl;
}

void setColor(){
    rep(y, N){
	int color = 0;
	rep(x, N){
	    if ( G[y][x] == '#' || y == ty && x == tx) { color_row[y][x] = -1; color++; }
	    else color_row[y][x] = color;
	}
    }
    rep(x, N){
	int color = 0;
	rep(y, N){
	    if ( G[y][x] == '#' || y == ty && x == ty ){ color_col[y][x] = -1; color++;}
	    else color_col[y][x] = color;
	}
    }
    G[ty][tx] = -1;
}

int main(){
    Robot R[2];
    int px, py, nrobot;
    while( cin >> N && N ){
	string line;
	getline(cin, line);
	nrobot = 0;
	rep(y, N) {
	    getline(cin, line);
	    rep(x, N){
		G[y][x] = line[x];
		if ( G[y][x] == 'X' ){
		    py = y; px = x;
		} else if ( G[y][x] == 'T' ){
		    ty = y; tx = x;
		    G[y][x] = ' ';
		} else if ( G[y][x] == 'E' ){
		    R[nrobot].y = y;
		    R[nrobot].x = x;
		    R[nrobot++].d = EAST;
		    G[y][x] = ' ';
		} else if ( G[y][x] == 'N' ){
		    R[nrobot].y = y;
		    R[nrobot].x = x;
		    R[nrobot++].d = NORTH;
		    G[y][x] = ' ';
		} else if ( G[y][x] == 'S' ){
		    R[nrobot].y = y;
		    R[nrobot].x = x;
		    R[nrobot++].d = SOUTH;
		    G[y][x] = ' ';
		} else if ( G[y][x] == 'W' ){
		    R[nrobot].y = y;
		    R[nrobot].x = x;
		    R[nrobot++].d = WEST;
		    G[y][x] = ' ';
		}
	    }
	}
	assert(nrobot==2);
	setColor();
	compute(py, px, R);
    }
    return 0;
}
