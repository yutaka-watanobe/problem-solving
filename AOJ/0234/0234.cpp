#include<iostream>
#include<queue>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n ;i++ )
#define MAX 100

int H, W;
int dy[3] = {0, 0, 1};
int dx[3] = {1, -1,0};

class State{
    public:
    int l, r, y, x, o;
    State(int y=0, int x=0, int o=0):y(y), x(x), o(o){
	reset();
    }
    
    void reset(){ l = W; r = -1; }
    void visit(int j){
	l = min(l, j);
	r = max(r, j);
    }
    bool visited(int j){
	return l <= j && j <= r;
    }

    bool operator < ( const State &s) const{
	if ( o != s.o ) return o < s.o;
	if ( l != s.l ) return l < s.l;
	if ( r != s.r ) return r < s.r;
	if ( y != s.y ) return y < s.y;
	if ( x != s.x ) return x < s.x;
	return false;
    }
};

class QState{
    public:
    State state;
    int cost;
    QState(){}
    QState(State state, int cost): state(state), cost(cost){}
    bool operator < ( const QState &s) const{
	return cost > s.cost;
    }
};

int F, M, O, C[MAX][MAX];
int maxs;

int dijkstra(){
    if ( O == 0 ) return -1;
    int ncost;

    priority_queue<QState> PQ;
    set<State> visited;

    maxs = 0;

    rep(j, W){
	State source = State(0, j, O);
	source.visit(j);
	source.o--;
	if ( source.o == 0 ) continue;

	if ( C[0][j] >= 0 ){
	    source.o = min(M, source.o + C[0][j]);
	    ncost = 0;
	} else {
	    ncost = C[0][j]*(-1);
	}
	visited.insert(source);

	PQ.push(QState(source, ncost));
    }

    QState u, v;
    int nx, ny;
    while(!PQ.empty()){
	u = PQ.top(); PQ.pop();
	if ( u.cost > F ) continue;
	if ( u.state.y == H-1) return u.cost;

	rep(r, 3){
	    nx = u.state.x + dx[r];
	    ny = u.state.y + dy[r];
	    if ( nx < 0 || ny < 0 || nx >= W || ny >= H ) continue;
	    
	    v = u;
	    v.state.o--;
	    if ( v.state.o == 0 ) continue;
	    v.state.x = nx;
	    v.state.y = ny;

	    if ( r == 2 ) v.state.reset();

	    if ( !v.state.visited(nx) ){
		if ( C[ny][nx] >= 0 ){
		    v.state.o = min(M, v.state.o + C[ny][nx]);
		    v.state.visit(nx);
		} else if ( C[ny][nx] < 0 ){
		    v.cost = u.cost + (C[ny][nx]*(-1));
		    v.state.visit(nx);
		}
	    }

	    if( visited.find(v.state) == visited.end()){
		visited.insert(v.state);
		PQ.push(v);
	    }
	}
    }

    return -1;
}

main(){
    while( cin >> W >> H && W && H ){
	cin >> F >> M >> O;
	rep(i, H) rep(j, W) cin >> C[i][j];
	int cost = dijkstra();
	if ( cost < 0 || F < cost) cout << "NA" << endl;
	else cout << cost << endl;
    }
}





