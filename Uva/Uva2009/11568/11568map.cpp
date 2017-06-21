#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

#define MAX 10
#define REP(i, n) for ( int i = 0; i < (int)n; i++ )
#define EAST 0
#define NORTH 1
#define SOUTH 2
#define WEST 3

static const int dx[5] = {1, 0, 0, -1, 0};
static const int dy[5] = {0, -1, 1, 0, 0};

class Robot{
    public:
    int x, y, d;
    Robot(){}
    Robot(int x, int y, int d): x(x), y(y), d(d){}
};

class State{
    public:
    int s[8];
    int x, y, r1x, r1y, r1d, r2x, r2y, r2d;
    State(){}
    State(int x, int y, int r1x, int r1y, int r1d, int r2x, int r2y, int r2d):
    x(x), y(y), r1x(r1x), r1y(r1y), r1d(r1d), r2x(r2x), r2y(r2y), r2d(r2d){
    }

    bool operator < ( const State &t ) const{
	if ( x != t.x ) return x < t.x;
	if ( y != t.y ) return y < t.y;
	if ( r1x != t.r1x ) return r1x < t.r1x;
	if ( r1y != t.r1y ) return r1y < t.r1y;
	if ( r1d != t.r1d ) return r1d < t.r1d;
	if ( r2x != t.r2x ) return r2x < t.r2x;
	if ( r2y != t.r2y ) return r2y < t.r2y;
	if ( r2d != t.r2d ) return r2d < t.r2d;
	return false;
    }
};

class PQState{
    public:
    State state; int cost;
    PQState(){}
    PQState(State state, int cost): state(state), cost(cost){}

    bool operator < ( const PQState &t ) const {
	return cost > t.cost;
    }
};

int N;
char G[MAX][MAX];

int x, y, Tx, Ty;
Robot R[2];

map<State, int> D;
map<State, bool> V;
map<State, State> P;
State g;

void rotate( int &r ){
    if ( r == EAST ) r = SOUTH;
    else if ( r == NORTH ) r = EAST;
    else if ( r == WEST ) r = NORTH;
    else if ( r == SOUTH ) r = WEST;
}

bool noWallV( int px, int sy, int ty ){
    sy++; ty--;
    for ( int i = sy; i <= ty; i++ ){
	if ( G[i][px] == '#' ) return false;
    }
    return true;
}

bool noWallH( int py, int sx, int tx ){
    sx++; tx--;
    for ( int j = sx; j <= tx; j++ ){
	if ( G[py][j] == '#' ) return false;
    }
    return true;
}

void moveRobot( int px, int py, int &rx, int &ry, int &rd ){
    if ( px == rx ){
	if (py < ry ) {
	    if ( noWallV( px, py, ry ) ){ rd = NORTH; ry--; }
	} else {
	    if ( noWallV( px, ry, py ) ){ rd = SOUTH; ry++; }
	}
    } else if ( py == ry ){
	if ( px < rx ) {
	    if ( noWallH( py, px, rx ) ) { rd = WEST; rx--; }
	} else {
	    if ( noWallH( py, rx, px ) ) { rd= EAST; rx++; }
	}
    } else {
      int nx, ny;
	nx = rx + dx[rd];
	ny = ry + dy[rd];
	if ( G[ny][nx] == '#' || ny == Ty && nx == Tx ){
	    while( G[ny][nx] == '#' || ny == Ty && nx == Tx ){
		rotate(rd);
		nx = rx + dx[rd];
		ny = ry + dy[rd];
	    }
	    rx = nx;
	    ry = ny;
	} else {
	    rx = nx;
	    ry = ny;
	}
	/*
	int nx, ny;
	nx = rx + dx[rd];
	ny = ry + dy[rd];
	if ( G[ny][nx] == '#' || ny == Ty && nx == Tx ){
	    rotate(rd);
	} else {
	    rx = nx;
	    ry = ny;
	    }*/
    }
}

int getMD( int sy, int sx, int ty, int tx ){
    return max(sy, ty)-min(sy, ty) + max(sx, tx)-min(sx, tx);
}

int bfs(){
    //queue<State> Q;
    priority_queue<PQState> Q;
    D = map<State, int>();
    V = map<State, bool>();
    P = map<State, State>();

    State s = State(x, y, R[0].x, R[0].y, R[0].d, R[1].x, R[1].y, R[1].d );
    
    D[s] = 0;
    P[s] = State(-1, -1, -1, -1, -1, -1,-1, -1 );
    //Q.push(s);
    Q.push(PQState(s, 0 + getMD(s.y, s.x, Ty, Tx) ));
    
    State u, v;

    int nx, ny;

    while( !Q.empty() ){
	// u = Q.front(); Q.pop();
	PQState ps = Q.top(); Q.pop();
	u = ps.state;
	if ( u.x == Tx && u.y == Ty ) { g = u; return D[u];}
	//		cout << u.x << " " << u.y << endl;
	for ( int d = 0; d < 5; d++ ){
	    nx = u.x + dx[d];
	    ny = u.y + dy[d];
	    if ( G[ny][nx] == '#' || nx == u.r1x && ny == u.r1y || nx == u.r2x && ny == u.r2y ) continue;

	    v = u;
	    v.x = nx;
	    v.y = ny;
	    
	    moveRobot( nx, ny, v.r1x, v.r1y, v.r1d );
	    moveRobot( nx, ny, v.r2x, v.r2y, v.r2d );
	    
	    if ( v.x == v.r1x && v.y == v.r1y || v.x == v.r2x && v.y == v.r2y ) continue;

	    if ( !V[v] ){
		V[v] = true;
		D[v] = D[u] + 1;
		P[v] = u;
		//Q.push(v);
		Q.push(PQState(v, D[v] + getMD(v.y, v.x, Ty, Tx)));
	    }
	}
    }

    return -1;
}

void printPath( State u ){
    State pre = P[u];
    if ( pre.x == -1 ) return;
    printPath(pre);

    if ( pre.x == u.x && pre.y == u.y ) cout << 'X';
    else if ( pre.x < u.x ) cout << 'E';
    else if ( pre.x > u.x ) cout << 'W';
    else if ( pre.y < u.y ) cout << 'S';
    else if ( pre.y > u.y ) cout << 'N';
}

void compute(){
    int cost = bfs();
    if ( cost == -1 ) cout << "You can't escape..." << endl;
    else { printPath(g); cout << endl;}
}

int main(){
    string line;
    while( cin >> N && N){
	getline(cin, line);
	int nrobot = 0;
	for ( int i = 0; i < N; i++ ){
	    getline(cin, line);
	    for ( int j = 0; j < N; j++ ){
		G[i][j] = line[j];
		if ( G[i][j] == 'X' ){
		    y = i; x = j; G[i][j] = ' ';
		} else if ( G[i][j] == 'T' ){
		    Ty = i; Tx = j; G[i][j] = ' ';
		} else if ( G[i][j] == '#' ) {
		} else if ( G[i][j] == ' ' ){

		} else {
		    R[nrobot].y = i;
		    R[nrobot].x = j;
		    G[i][j] = ' ';
		    if ( G[i][j] == 'E' ) R[nrobot].d = EAST;
		    else if ( G[i][j] == 'N' ) R[nrobot].d = NORTH;
		    else if ( G[i][j] == 'S' ) R[nrobot].d = SOUTH;
		    else if ( G[i][j] == 'W' ) R[nrobot].d = WEST;
		    nrobot++;
		}
	    }
	}
	compute();
    }
    return 0;
}
