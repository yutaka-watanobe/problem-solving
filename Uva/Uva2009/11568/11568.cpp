#include<iostream>
#include<stdio.h>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
#include<cassert>

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
    string path;
    State(){}
    State(int x, int y, int r1x, int r1y, int r1d, int r2x, int r2y, int r2d, string path):
    x(x), y(y), r1x(r1x), r1y(r1y), r1d(r1d), r2x(r2x), r2y(r2y), r2d(r2d), path(path){
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
    string path;
    PQState(){}
    PQState(State state, int cost, string path): state(state), cost(cost), path(path){}

    bool operator < ( const PQState &t ) const {
	if ( cost == t.cost ) return path > t.path;
	return cost > t.cost;
    }
};

int N;
char G[MAX][MAX];
int color_row[MAX][MAX];
int color_col[MAX][MAX];

int x, y, Tx, Ty;
Robot R[2];

map<State, bool> V;

State g;
string ans;
int depth;

void rotate( int &r ){
    if ( r == EAST ) r = SOUTH;
    else if ( r == NORTH ) r = EAST;
    else if ( r == WEST ) r = NORTH;
    else if ( r == SOUTH ) r = WEST;
}

void moveRobot( int px, int py, int &rx, int &ry, int &rd ){
    int tmpx = rx;
    int tmpy = ry;
    if ( px == rx && color_col[py][px] == color_col[ry][px] ){
	if ( py < ry ) { rd = NORTH; ry--; }
	else { rd = SOUTH; ry++; }
    } else if ( py == ry &&  color_row[py][px] == color_row[py][rx] ){
	if ( px < rx ) { rd = WEST; rx--; }
	else { rd = EAST; rx++; }
    } else { // normal wondering
	int nx, ny;
	nx = rx + dx[rd];
	ny = ry + dy[rd];
	if ( G[ny][nx] == '#' || ny == Ty && nx == Tx ){
	  int cnt = 0;
	    while( G[ny][nx] == '#' || ny == Ty && nx == Tx ){
		rotate(rd);
		nx = rx + dx[rd];
		ny = ry + dy[rd];
		cnt++;
		if ( cnt >= 4 ) return;
	    }
	    rx = nx;
	    ry = ny;
	} else {
	    rx = nx;
	    ry = ny;
	}

    }
    assert( G[ry][rx] != '#' ); 
    if( G[ry][rx] == '#' ){
	ry = tmpy;
	rx = tmpx;
    }

}

int getMD( int sy, int sx, int ty, int tx ){
  //        return 0;
    return max(sy, ty)-min(sy, ty) + max(sx, tx)-min(sx, tx);
}

void print( int x, int y, int r1x, int r1y, int r1d, int r2x, int r2y, int r2d ){
  for ( int i = 0; i< N; i++ ){
    for ( int j = 0; j < N; j++ ){
      if ( i == r1y && j == r1x ) {
	if ( r1d == EAST ) cout << 'E';
	else if ( r1d == WEST ) cout << 'W';
	else if ( r1d == SOUTH ) cout << 'S';
	else if ( r1d == NORTH ) cout << 'N';
      } else if( i == r2y && j == r2x ) {
	if ( r2d == EAST ) cout << 'E';
	else if ( r2d == WEST ) cout << 'W';
	else if ( r2d == SOUTH ) cout << 'S';
	else if ( r2d == NORTH ) cout << 'N';

      } else if ( i == y && j == x ) cout << 'X';
      else cout << G[i][j];
    }
    cout << endl;
  }
}

int bfs(){
    //queue<State> Q;
    priority_queue<PQState> Q;

    V = map<State, bool>();

    State s = State(x, y, R[0].x, R[0].y, R[0].d, R[1].x, R[1].y, R[1].d, "" );

    V[s] = true;
    //Q.push(s);
    Q.push(PQState(s, 0 + getMD(s.y, s.x, Ty, Tx), "" ));

    State u, v;

    int nx, ny;
    depth = 1000;

    string path;

    while( !Q.empty() ){
	//u = Q.front(); Q.pop();
	PQState ps = Q.top(); Q.pop();
	u = ps.state;

	//if ( u.x == Tx && u.y == Ty ) { g = u; return D[u];}
	
	int cost = u.path.size();
	//	if ( cost > depth ) continue;
	if ( cost > depth ) return depth;

	assert( u.path == ps.path );

	if ( u.x == Tx && u.y == Ty ) { 
	    if ( depth > cost ){
		depth = cost;
		ans = ps.path;
	    } else if ( depth == cost ){
	      if ( ans > ps.path ) ans = ps.path;
	    }
	    continue;
	}


	//		cout << u.x << " " << u.y << endl;
	for ( int d = 0; d < 5; d++ ){
	    nx = u.x + dx[d];
	    ny = u.y + dy[d];
	    if ( G[ny][nx] == '#' || nx == u.r1x && ny == u.r1y || nx == u.r2x && ny == u.r2y ) continue;

	    v = u;
	    v.x = nx;
	    v.y = ny;
	    
	    //print( v.x, v.y, v.r1x, v.r1y, v.r1d, v.r2x, v.r2y, v.r2d );
	    moveRobot( v.x, v.y, v.r1x, v.r1y, v.r1d );
	    moveRobot( v.x, v.y, v.r2x, v.r2y, v.r2d );
	    //cout << "v" << endl;
	    //print( v.x, v.y, v.r1x, v.r1y, v.r1d, v.r2x, v.r2y, v.r2d );

	    
	    if ( !(v.x == Tx && v.y == Ty)  && (v.x == v.r1x && v.y == v.r1y || v.x == v.r2x && v.y == v.r2y) ) continue;

	    if ( !V[v] ){
		V[v] = true;
		//Q.push(v);

		if ( d == EAST ) v.path += 'E';
		else if ( d == WEST ) v.path += 'W';
		else if ( d == NORTH ) v.path += 'N';
		else if ( d == SOUTH ) v.path += 'S';
		else if ( d == 4 ) v.path += 'X';

		Q.push(PQState(v, v.path.size() + getMD(v.y, v.x, Ty, Tx), v.path));
	    }
	}
    }

    if ( depth == 1000 )     return -1;
    else return depth;
}



void compute(){
    int cost = bfs();
    if ( cost == -1 ) cout << "You can't escape..." << endl;
    else cout << ans << endl;
    //else { printPath(g); cout << endl;}
    
    //    cout << g.r1x << "," << g.r1y << endl;
}

void setColor(){
    REP(y, N) REP(x, N) { color_row[y][x] = color_col[y][x] = -1; }
    REP(y, N){
	int color = 0;
	REP(x, N) {
	    if ( G[y][x] == '#'|| y == Ty && x == Tx ){
		color_row[y][x] = -1; color++;
	    } else color_row[y][x] = color;
	}
    }
    REP(x, N){
	int color = 0;
	REP(y, N) {
	    if ( G[y][x] == '#'|| y == Ty && x == Tx ){
		color_col[y][x] = -1; color++;
	    } else color_col[y][x] = color;
	}
    }
    /*
    REP(y, N) {
	REP(x, N){
	  printf("%3d", color_col[y][x] );
	}
	cout << endl;
	}*/

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
		    if ( G[i][j] == 'E' ) R[nrobot].d = EAST;
		    else if ( G[i][j] == 'N' ) R[nrobot].d = NORTH;
		    else if ( G[i][j] == 'S' ) R[nrobot].d = SOUTH;
		    else if ( G[i][j] == 'W' ) R[nrobot].d = WEST;
		    G[i][j] = ' ';

		    nrobot++;
		}
	    }
	}
	assert( nrobot == 2 );
	setColor();
	compute();
    }
    return 0;
}
