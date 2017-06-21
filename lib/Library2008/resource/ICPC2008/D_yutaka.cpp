#include<iostream>
#include<queue>
using namespace std;
#define MAX 30
static const int STR = 0;
static const int RIGHT = 1;
static const int BACK = 2;
static const int LEFT = 3;
static const int HALT = 4;
static const int di[4] = {0, -1, 0, 1};
static const int dj[4] = {1, 0, -1, 0};

class Robot{
    public:
    int i, j, k, cost;
    Robot(){}
    Robot( int i, int j, int k, int cost ): i(i), j(j), k(k), cost(cost){}

    void move( int com, int c ){
	if ( com == LEFT ) k = (k+1)%4;
	if ( com == RIGHT ) k = (k+3)%4;
	if ( com == BACK ) k = (k+2)%4;
	i += di[k]; j += dj[k];
	cost += c;
    }

    bool operator < ( const Robot &s ) const{
	return cost > s.cost;
    }
};

int W, H, G[MAX][MAX], C[4];

bool valid( Robot r ){
    return ( 0 <= r.i && 0 <= r.j && r.i < H && r.j < W );
}

int dijkstra(){
    bool V[MAX][MAX][4];
    for ( int i = 0; i < H; i++ ){
	for ( int j = 0; j < W; j++ ) {
	    for ( int k = 0; k < 4; k++ ) V[i][j][k] = false;
	} 
    }
    priority_queue<Robot> PQ;
    PQ.push(Robot(0, 0, 0, 0)); // i, j, direction, cost
    Robot u, v; // current node, next node

    while(!PQ.empty()){
	u = PQ.top(); PQ.pop();
	if ( u.i == H-1 && u.j == W-1 ) return u.cost;
	V[u.i][u.j][u.k] = true;
	v = u;
	v.move(G[u.i][u.j], 0);
	if ( G[u.i][u.j] != HALT && valid(v) && !V[v.i][v.j][v.k] ) PQ.push( v );
	for ( int com = 0; com < 4; com++ ){
	    v = u;
	    v.move(com, C[com]);
	    if ( valid(v) && !V[v.i][v.j][v.k] ) PQ.push( v );
	}
    }
}

main(){
    while( cin >> W >> H && ( W && H) ){
	for ( int i = 0; i < H; i++ ){
	    for ( int j = 0; j < W; j++ ) cin >> G[i][j];
	}
	for ( int i = 0; i < 4; i++ ) cin >> C[i];
	cout << dijkstra() << endl;
    }
}
