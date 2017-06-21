#include<iostream>
#include<queue>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
#define MAX 100

class State{
    public:
    int p, b, cost;
    State(int p=0, int b=0, int cost=0):p(p), b(b), cost(cost){}
};

int n, B[MAX][2];

int bfs(){
    bool V[MAX][2];
    queue<State> Q;
    rep(i, n) rep(j, 2) V[i][j] = false;
    int s0 = 0, s1 = 0;
    if ( B[s0][0] == 1 ) while( s0+1 < n && B[s0+1][0] == 1) s0++;
    if ( B[s1][1] == 1 ) while( s1+1 < n && B[s1+1][1] == 1) s1++;
    V[s0][0] = V[s1][1] = true;
    Q.push(State(s0, 0, 0));
    Q.push(State(s1, 1, 0));

    State u, v;
    while(!Q.empty()){
	u = Q.front(); Q.pop();
	if ( u.p == n-1 ) return u.cost;

	for ( int r = 0; r < 3; r++ ){
	    int np = u.p + r;
	    int nb = (u.b + 1)%2;
	    if ( np >= n ) continue;
	    if ( B[np][nb] == 2 ) while( B[np][nb] == 2 ) np--;
	    if ( B[np][nb] == 1 ) while( np+1 < n && B[np+1][nb] == 1 ) np++;
	    if ( V[np][nb] ) continue;
	    V[np][nb] = true;
	    Q.push(State(np, nb, u.cost+1));
	}
    }

    return -1;
}

main(){
    while( cin >> n ){
	if ( n == 0 ) break;
	rep(i, n) cin >> B[i][0];
	rep(i, n) cin >> B[i][1];
	int cost = bfs();
	if ( cost < 0 ) cout << "NA" << endl;
	else cout << cost << endl;
    }
}
