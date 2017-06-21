#include<iostream>
#include<queue>
#include<map>
using namespace std;
#define MAX 14

class State{
    public:
    bool used[MAX];
    int n, size, cost, remain;
    State( int n=0, int size=0):n(n), size(size){
	for ( int i = 0; i < n; i++ ) used[i] = false;
	cost = 0;
	remain = n;
    }

    bool operator < ( const State &s) const{
	if ( size != s.size ) return size < s.size;
	for ( int i = 0; i < n; i++ ){
	    if ( used[i] == s.used[i] ) continue;
	    return used[i] < s.used[i];
	}
	return false;
    }
};

int n, m;
pair<int, int> F[MAX];


void rec(State &u, State &v, int pos, int fsize, queue<State> &Q, map<State, bool> &visited){
    if ( pos == n ){
	v.size += fsize;
	if ( !visited[v] ){
	    visited[v] = true;
	    v.cost = u.cost + 1;
	    Q.push(v);
	}
	return;
    }

    if ( !v.used[pos] && v.size >= F[pos].second) {
	State vv = v;
	vv.used[pos] = true;
	vv.remain--;
	vv.size -= F[pos].second;
	rec(u, vv, pos+1, fsize + F[pos].first, Q, visited );
    }

    rec(u, v, pos+1, fsize, Q, visited);
}

int bfs(){
    State s = State(n, m);
    queue<State> Q;
    map<State, bool> visited;
    
    Q.push(s);
    visited[s] = true;

    State u, v;
    while( !Q.empty() ){
	u = Q.front(); Q.pop();
	if ( u.remain == 0 ) return u.cost;
	rec(u, u, 0, 0, Q, visited);
	
    }

    return -1;
}

void compute(){
    int cost = bfs();
    if ( cost < 0 ) cout << "Impossible" << endl;
    else cout << cost << endl;
}

main(){
    while( cin >> n >> m && n ){
	for ( int i = 0; i < n; i++ ) cin >> F[i].first >> F[i].second;
	compute();
    }
}
