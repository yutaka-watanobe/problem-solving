#include<iostream>
#include<cassert>
#define WMAX 64
#define HMAX 16

using namespace std;

class State{
    public:
    int toX, toY, toD; // to
    int frX, frY, frD; // from
    State(){}
    
    bool operator == ( const State &s ) const{
	return ( toX == s.toX && toY == s.toY && toD == s.toD &&
		 frX == s.frX && frY == s.frY && frD == s.frD );
    }

    void print(){
	cout << toX << " " << toY << " " << toD << endl;
	cout << frX << " " << frY << " " << frD << endl;
	cout << endl;
    }

};

static const int dx[4] = {0, -1, 0, 1};
static const int dy[4] = {1, 0, -1, 0};

int W, H;
char G[HMAX][WMAX];
bool visited[HMAX][WMAX][4][HMAX][WMAX][4];
State start, goal;
pair<int, int> posM, posK;

int getSpaceDirection( int x, int y ){
    for ( int r = 0; r < 4; r++ )
	if ( G[x+dx[r]][y+dy[r]] != '#' ) return r;
    assert(false);
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
    //    u.print();
    
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
	if ( !visited[v.toX][v.toY][v.toD][v.frX][v.frY][v.frD] ) {
	    if ( recursive2( v ) ) return true;
	}
	v.frX += dx[r];	v.frY += dy[r];
    }

    // next: left
    v = u;
    turnLeft( v.toD );
    move( v.toX, v.toY, v.toD );
    r = getOposite(v.frD);
    turnLeft( v.frD );
    while ( findSource( v.frX, v.frY, r, v.frD ) ){
	if ( !visited[v.toX][v.toY][v.toD][v.frX][v.frY][v.frD] ) {
	    if ( recursive2( v ) ) return true;
	}
	v.frX += dx[r];	v.frY += dy[r];
    }

    
    return false;
}

void init(){
    //    memset(visited, 0, sizeof(bool)*WMAX*WMAX*HMAX*HMAX*4*4);

    for ( int w1 = 0; w1 < W; w1++ )
	for ( int w2 = 0; w2 < W; w2++ )
	    for ( int h1 = 0; h1 < H; h1++ )
		for ( int h2 = 0; h2 < H; h2++ )
		    for ( int r1 = 0; r1 < 4; r1++ )
			for (int r2 = 0; r2 < 4; r2++ ) visited[h1][w1][r1][h2][w2][r2] = false;

}

bool recursive1( State u ){
    if ( u.toX == posM.first && u.toY == posM.second ) return true;
    visited[u.toX][u.toY][u.toD][0][0][0] = true;
    State v;
    // to right
    v = u;
    turnRight(v.toD);
    move(v.toX, v.toY, v.toD );
    if ( !visited[v.toX][v.toY][v.toD][0][0][0] )
	if ( recursive1(v) ) return true;
    // to left
    v = u;
    turnLeft(v.toD);
    move(v.toX, v.toY, v.toD );
    if ( !visited[v.toX][v.toY][v.toD][0][0][0] )
	if ( recursive1(v) ) return true;

    return false;
}

int compute(){
    start = State();
    goal = State();
    // to from
    start.toX = posK.first; start.toY = posK.second; start.toD = getSpaceDirection(posK.first, posK.second);
    start.frX = posK.first; start.frY = posK.second; start.frD = getOposite(getSpaceDirection(posK.first, posK.second) );
    move(start.toX, start.toY, start.toD);

    goal.toX = posM.first; goal.toY = posM.second; goal.toD = getOposite(getSpaceDirection(posM.first, posM.second) );
    goal.frX = posM.first; goal.frY = posM.second; goal.frD = getSpaceDirection(posM.first, posM.second);
    move(goal.frX, goal.frY, goal.frD);

    init();

    for ( int r = 0; r < 4; r++ ){
	if ( recursive2( start ) ) return 0;
	turnLeft(start.frD);
    }

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
	    if ( G[i][j] == 'M' ) { posM.first = i; posM.second = j;}
	    if ( G[i][j] == 'K' ) { posK.first = i; posK.second = j;}
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

