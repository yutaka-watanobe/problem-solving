// 11198:Dancing Digits:2.5:BFS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

static bool PT[16] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0};

int abs(int x){
    if ( x < 0 ) return x*(-1);
    return x;
}

class State{
    public:
    int T[8], cost;
    
    State(){ cost = 0;}
    bool operator < ( const State &s) const{
	for ( int i = 0; i < 8; i++ ){
	    if ( T[i] == s.T[i] ) continue;
	    return T[i] < s.T[i];
	}
	return false;
    }
    bool solved(){
	for ( int i = 0; i < 8; i++ ){
	    if ( i+1 != abs(T[i]) ) return false;
	}
	return true;
    }
};

bool canDance(int a, int b){
    if ( a*b > 0 ) return false;
    a = abs(a);
    b = abs(b);
    return PT[a + b];
}

void move(int s, int t, State u, State v, queue<State> &Q, map<State, bool> &V){
    if ( t < 0 || t >= 8 || s == t) return;

    v = u;
    int tmp = v.T[s];
    if ( t <= s ){
	for ( int i = s; i >= t+1; i-- ) v.T[i] = v.T[i-1];
	v.T[t] = tmp;
    } else {
	for ( int i = s; i <= t-1; i++ ) v.T[i] = v.T[i+1];
	v.T[t] = tmp;
    }

    if ( !V[v] ){
	v.cost = u.cost + 1;
	V[v] = true;
	Q.push(v);
    }
}

int bfs(int T[8] ){
    State init = State();
    queue<State> Q;
    map<State, bool> V;

    rep(i, 8) init.T[i] = T[i];

    Q.push(init);
    V[init] = true;

    State u, v;
    while( !Q.empty() ){
	u = Q.front(); Q.pop();
	if ( u.solved() ) return u.cost;

	for ( int i = 0; i < 8; i++ ){
	    for ( int l = i-1; l >= 0; l-- ){
		if ( !canDance(u.T[l], u.T[i]) ) continue;
		move(i, l+1, u, v, Q, V);
		move(i, l, u, v, Q, V);
	    }
	    for ( int r = i+1; r < 8; r++ ){
		if ( !canDance(u.T[r], u.T[i]) ) continue;
		move(i, r-1, u, v, Q, V);
		move(i, r, u, v, Q, V);
	    }
	}
    }

    return -1;
}

main(){
    int T[8];
    int tcase = 1;
    while(1){
	cin >> T[0];
	if ( T[0] == 0 ) break;
	for ( int i = 1; i < 8; i++ ) cin >> T[i];
	cout << "Case " << tcase << ": " << bfs(T) << endl;
	tcase++;
    }
}
