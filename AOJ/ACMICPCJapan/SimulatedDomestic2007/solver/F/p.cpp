// Problem F: Karakuri Doll
// @author yutaka
#include<iostream>
#define WMAX 64
#define HMAX 16

using namespace std;

class State{
    public:
    int toX, toY, toD; // to
    int frX, frY, frD; // from
    State(){}
};

static const int dx[4] = {0, -1, 0, 1};
static const int dy[4] = {1, 0, -1, 0};

int W, H;
char G[HMAX][WMAX];
bool visited[HMAX][WMAX][4][HMAX][WMAX][4];
State start, goal;

int getSpaceDirection( int x, int y ){
    for ( int r = 0; r < 4; r++ )
	if ( G[x+dx[r]][y+dy[r]] != '#' ) return r;
}

int getOposite( int r ){
    return (r+2)%4;
}

void turnRight( int &r ){
    r--;
    if ( r < 0 ) r = 3;
}

void turnLeft( int &r ){
    r = (r+1)%4;
}

void move( int &x, int &y, int r ){
    while ( G[x+dx[r]][y+dy[r]] != '#' ) { x += dx[r]; y += dy[r]; }
}

bool findSource( int &x, int &y, int r, int p){
    while (1){
	if ( G[x][y] == '#' ) return false;
	if ( G[x+dx[p]][y+dy[p]] == '#' ) return true;
	x += dx[r]; y += dy[r];
    }
}

bool check( State s, State g ){
    if ( s.toX == g.toX && s.toY == g.toY &&
	 s.frX == g.frX && s.frY == g.frY && s.frD == g.frD ) return true;
    return false;
}

bool recursive2( State u ){
    if ( check( u, goal)  ) return true;
    visited[u.toX][u.toY][u.toD][u.frX][u.frY][u.frD] = true;

    State v;
    int r;
    // next: right
    v = u;
    turnRight( v.toD );
    move( v.toX, v.toY, v.toD );
    r = getOposite(v.frD);
    turnRight( v.frD );
    while ( findSource( v.frX, v.frY, r, v.frD ) ){
	if ( !visited[v.toX][v.toY][v.toD][v.frX][v.frY][v.frD] && recursive2( v ) ) return true;
	v.frX += dx[r];	v.frY += dy[r];
    }

    // next: left
    v = u;
    turnLeft( v.toD );
    move( v.toX, v.toY, v.toD );
    r = getOposite(v.frD);
    turnLeft( v.frD );
    while ( findSource( v.frX, v.frY, r, v.frD ) ){
	if ( !visited[v.toX][v.toY][v.toD][v.frX][v.frY][v.frD] && recursive2( v ) ) return true;
	v.frX += dx[r];	v.frY += dy[r];
    }
    
    return false;
}

void init(){
    memset(visited, 0, sizeof(bool)*WMAX*WMAX*HMAX*HMAX*4*4);
}

bool recursive1( State u ){
    if ( u.toX == goal.toX && u.toY == goal.toY ) return true;
    visited[u.toX][u.toY][u.toD][0][0][0] = true;
    State v;
    // to right
    v = u;
    turnRight(v.toD);
    move(v.toX, v.toY, v.toD );
    if ( !visited[v.toX][v.toY][v.toD][0][0][0] && recursive1(v) ) return true;
    // to left
    v = u;
    turnLeft(v.toD);
    move(v.toX, v.toY, v.toD );
    if ( !visited[v.toX][v.toY][v.toD][0][0][0] && recursive1(v) ) return true;

    return false;
}

int compute(){
    start.toD = getSpaceDirection(start.toX, start.toY);
    start.frD = getOposite(getSpaceDirection(start.toX, start.toY) );
    move(start.toX, start.toY, start.toD);

    goal.toD = getOposite(getSpaceDirection(goal.toX, goal.toY) );
    goal.frD = getSpaceDirection(goal.toX, goal.toY);
    move(goal.frX, goal.frY, goal.frD);

    // to - from
    init();
    for ( int r = 0; r < 4; r++ ){
	if ( recursive2( start ) ) return 0;
	turnLeft(start.frD);
    }

    // to
    init();
    if ( recursive1( start ) ) return 1;

    return 2;
}

bool input(){
    cin >> W >> H;
    if ( W == 0 && H == 0 ) return false;
    for ( int i = 0; i < H; i++ ){
	for ( int j = 0; j < W; j++ ) {
	    cin >> G[i][j];
	    if ( G[i][j] == 'K' ) { start.toX = start.frX = i; start.toY = start.frY = j;}
	    if ( G[i][j] == 'M' ) { goal.toX = goal.frX = i; goal.toY = goal.frY = j;}
	}
    }
    return true;
}

main(){
    while ( input() ) {
	int judge = compute();
	if ( judge == 0 ) cout << "He can accomplish his mission." << endl;
	else if ( judge == 1 ) cout << "He cannot return to the kitchen." << endl;
	else cout << "He cannot bring tea to his master." << endl;
    }
}

