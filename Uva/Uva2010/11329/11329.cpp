#include<iostream>
#include<queue>
#include<map>
using namespace std;

#define N 4
#define TOP 0
#define FRONT 1
#define RIGHT 2
#define BOTTOM 3
#define BACK 4
#define LEFT 5

class State{
    public:
    int pos;
    bool face[6], grid[16];

    State(int pos=0):pos(pos){
	for ( int i = 0; i < 6; i++ ) face[i] = false;
	for ( int i = 0; i < 16; i++ ) grid[i] = false; 
    }
    
    void rollBack(){
	bool tmp = face[TOP];
	face[TOP] = face[FRONT]; face[FRONT] = face[BOTTOM]; face[BOTTOM] = face[BACK];
	face[BACK] = tmp;
    }
    void rollFront(){
	for ( int i = 0; i < 3; i++ ) rollBack();
    }
    void rollRight(){
	bool tmp = face[TOP];
	face[TOP] = face[LEFT]; face[LEFT] = face[BOTTOM]; face[BOTTOM] = face[RIGHT];
	face[RIGHT] = tmp;
    }
    void rollLeft(){
	for ( int i = 0; i < 3; i++ ) rollRight();
    }

    bool check(){
	for ( int i = 0; i < 6; i++ ) if ( !face[i] ) return false;
	return true;
    }

    bool operator < ( const State &s ) const{
	if ( pos == s.pos ){
	    for ( int i = 0; i < 6; i++ ){
		if ( face[i] == s.face[i] ) continue;
		return face[i] < s.face[i];
	    }
	    for ( int i = 0; i < 16; i++ ){
		if ( grid[i] == s.grid[i] ) continue;
		return grid[i] < s.grid[i];
	    }
	} else {
	    return pos < s.pos;
	}
	return false;
    }
};

void update(queue<State> &Q, State &u, State &v, map<State, bool> &visited, map<State, int> &cost, bool &ans){
    
    if ( v.grid[v.pos] || v.face[BOTTOM] ) {
	if ( v.grid[v.pos] && !v.face[BOTTOM]){
	    v.grid[v.pos] = false;
	    v.face[BOTTOM] = true;
	    ans =  v.check();
	} else if ( !v.grid[v.pos] && v.face[BOTTOM] ) {
	    v.grid[v.pos] = true;
	    v.face[BOTTOM] = false;
	}
    }
    
    if ( !visited[v] ){
	visited[v] = true;
	cost[v] = cost[u]+1;
	Q.push(v);
    }
}

int bfs(State s){
    queue<State> Q;
    map<State, bool> visited;
    map<State, int> cost;

    Q.push(s);
    visited[s] = true;
    cost[s] = 0;

    int pi, pj;
    State u, v;
    bool ans;

    while( !Q.empty() ){
	u = Q.front(); Q.pop();
	pi = u.pos/N;
	pj = u.pos%N;

	// to north
	v = u;
	if ( pi > 0 && !u.face[BACK] ){
	    v.pos = (pi-1)*N + pj;
	    v.rollBack();
	    update(Q, u, v, visited, cost, ans);
	    if ( ans ) return cost[u] + 1;
	}
	// to south
	v = u;
	if ( pi < N-1 && !u.face[FRONT]){
	    v.pos = (pi+1)*N + pj;
	    v.rollFront();
	    update(Q, u, v, visited, cost, ans);
	    if ( ans ) return cost[u] + 1;
	}
	// to east
	v = u;
	if ( pj < N-1 && !u.face[RIGHT]){
	    v.pos = pi*N + pj+1;
	    v.rollRight();
	    update(Q, u, v, visited, cost, ans);
	    if ( ans ) return cost[u] + 1;
	} 
	// to west
	v = u;
	if ( pj > 0 && !u.face[LEFT]){
	    v.pos = pi*N + pj-1;
	    v.rollLeft();
	    update(Q, u, v, visited, cost, ans);
	    if ( ans ) return cost[u] + 1;
	}
    }

    return -1;

}

void compute(){
    int pos;
    char ch;
    State s = State();

    for ( int i = 0; i < N; i++ ){
	for ( int j = 0; j < N; j++ ){
	    cin >> ch;
	    if ( ch == 'D' ){
		s.pos = i*N + j;
		s.grid[i*N+j] = false;
	    } else if ( ch == 'X' ){
		s.grid[i*N+j] = true;
	    } else {
		s.grid[i*N+j] = false;
	    }
	}
    }

    int cost = bfs(s);
    if ( cost == -1 ) cout << "impossible" << endl;
    else cout << cost << endl;
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) compute();
}

