#include<iostream>
#include<stdio.h>
#include<queue>
#include<map>
using namespace std;

class Gap{
    public:
    short buffer[4][8];
    short pos[50];
    short space[4];

    Gap(){}

    bool solved(){
	for ( int i = 0; i < 4; i++ ){
	    for ( int j = 1; j < 7; j++ ){
		if ( buffer[i][j] != (i+1)*10 + (j+1) ) return false;
	    }
	}
	return true;
    }

    bool operator < ( const Gap &g ) const{
	for ( int i = 0; i < 4; i++ ){
	    for ( int j = 0; j < 8; j++ ){
		if ( buffer[i][j] == g.buffer[i][j] ) continue;
		return buffer[i][j] < g.buffer[i][j];
	    }
	}
	return false;
    }
};

Gap initial;

int bfs(){
    queue<Gap> Q;
    map<Gap, bool> visited;
    map<Gap, int> cost;

    Q.push(initial);
    cost[initial] = 0;
    visited[initial] = true;

    Gap u, v;

    while( !Q.empty() ){
	u = Q.front(); Q.pop();
	if ( u.solved() ) return cost[u];

	int si, sj, target;
	for ( int s = 0; s < 4; s++ ){
	    si = u.space[s]/8; sj = u.space[s]%8;
	    if ( u.buffer[si][sj-1] == 0 || u.buffer[si][sj-1]%10 == 7 ) continue;

	    target = u.buffer[si][sj-1] + 1;
	    v = u;
	    v.buffer[si][sj] = target;
	    v.buffer[v.pos[target]/8][v.pos[target]%8] = 0;
	    v.space[s] = v.pos[target];
	    v.pos[target] = si*8 + sj;

	    if ( !visited[v] ){
		visited[v] = true;
		cost[v] = cost[u] + 1;
		Q.push(v);
	    }
	}
    }

    return -1;
}

void compute(){
    for ( int i = 0; i < 4; i++ ){
	int v = 10*(i+1) + 1;
	initial.buffer[i][0] = v;
	initial.space[i] = initial.pos[v];
	initial.buffer[initial.pos[v]/8][initial.pos[v]%8] = 0;
	initial.pos[v] = i*8;
    }
    cout << bfs() << endl;
}

void input(){
    int x;
    for ( int i = 0; i < 4; i++ ){
	for ( int j = 1; j < 8; j++ ){
	    cin >> x;
	    initial.buffer[i][j] = x;
	    initial.pos[x] = i*8 + j;
	}
    }
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	input();
	compute();
    }
}