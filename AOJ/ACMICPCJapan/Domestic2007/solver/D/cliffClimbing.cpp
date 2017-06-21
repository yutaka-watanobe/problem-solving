#include<iostream>
#include<queue>
using namespace std;
#define HMAX 60
#define WMAX 30
#define LEFT 0
#define RIGHT 1
#define INFTY (1<<21)

class State{
    public:
    int i, j, f, c; // i, j, foot, cost
    State(){}
    State( int i, int j, int f, int c ): i(i), j(j), f(f), c(c){}
    
    bool operator < ( const State &s ) const{
	return c > s.c;
    }
};

int H, W;
char C[HMAX][WMAX]; //cliff
priority_queue<State> PQ;
int D[HMAX][WMAX][2];
bool visited[HMAX][WMAX][2];

bool isOutside( int i, int j ){
    return ( i < 0 || j < 0 || H <= i || W <= j);
}

int dijkstra(){
    static const int di[2][9] = {{-2, -1, -1, 0, 0, 0, 1, 1, 2},
				 {-2, -1, -1, 0, 0, 0, 1, 1, 2}};
    static const int dj[2][9] = {{-1, -2, -1, -3, -2, -1, -2, -1, -1},
				 {1, 1, 2, 1, 2, 3, 1, 2, 1}};
    State u, v;
    int ni, nj, nf;

    while ( !PQ.empty() ){
	u = PQ.top(); PQ.pop();
	if ( C[u.i][u.j] == 'T' ) return D[u.i][u.j][u.f];
	visited[u.i][u.j][u.f] = true;
	
	for ( int r = 0; r < 9; r++ ){
	    nf = (u.f + 1)%2;
	    ni = u.i + di[nf][r]; nj = u.j + dj[nf][r];
	    if ( isOutside( ni, nj ) || 
		 C[ni][nj] == 'X' || visited[ni][nj][nf] ) continue;
	    int cost = D[u.i][u.j][u.f] + ((C[ni][nj]=='T')?0:(C[ni][nj]-'0'));
	    if ( cost < D[ni][nj][nf] ){
		D[ni][nj][nf] = cost;
		PQ.push( State(ni, nj, nf, cost) );
	    }
	}
    }

    return -1;
}

bool initialize(){
    cin >> W >> H;
    if ( W == 0 && H == 0 ) return false;
    PQ = priority_queue<State>();
    for ( int i = 0; i < H; i++ ){
	for ( int j = 0; j < W; j++ ){
	    cin >> C[i][j];
	    if ( C[i][j] == 'S' ){
		PQ.push( State( i, j, LEFT, 0) );
		PQ.push( State( i, j, RIGHT, 0) );
		D[i][j][LEFT] = D[i][j][RIGHT] = 0;
	    } else {
		D[i][j][LEFT] = D[i][j][RIGHT] = INFTY;
	    }
	    visited[i][j][0] = visited[i][j][1] = false;
	}
    }
    return true;
}

main(){
    while ( initialize() ) cout << dijkstra() << endl;
}
