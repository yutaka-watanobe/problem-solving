#include<iostream>
#include<queue>
#include<algorithm>
#define rep(i,b,e) for ( int i = b; i <= e; i++ )
using namespace std;

#define MAX 1000
#define INFTY (1<<21)
int n, C[MAX+1][MAX+1], T[MAX+1][MAX+1];

class State{
    public:
    int p, e;
    State( int p = 0, int e = 0 ): p(p), e(e){}
    bool operator < ( const State &s ) const{
	return e > s.e;
    }
};

int dijkstra( int s, int t, int type ){
    priority_queue<State> PQ;
    bool visited[MAX+1];
    int d[MAX+1];
    rep(i,1,n){
	visited[i] = false;
	d[i] = INFTY;
    }
    PQ.push(State(s, 0));
    d[s] = 0;
    State u;
    while( !PQ.empty() ){
	u = PQ.top(); PQ.pop();
	if ( u.p == t ) return u.e;
	visited[u.p] = true;
	rep(v,1,n){
	    if ( C[u.p][v] == INFTY || visited[v] ) continue;
	    if ( type == 0 ){
		if ( d[v] > d[u.p] + C[u.p][v] ){
		    d[v] = d[u.p] + C[u.p][v];
		    PQ.push(State(v, d[v]));
		} 
	    } else {
		if ( d[v] > d[u.p] + T[u.p][v] ){
		    d[v] = d[u.p] + T[u.p][v];
		    PQ.push(State(v, d[v]));
		} 
	    }
	}
    }
    return -1;
}

main(){
    int k, s, t, cost, tm, q, r;
    while(1){
	scanf("%d %d", &k, &n);
	if ( n == 0 && k == 0 ) break;
	rep(i,1,n) rep(j,1,n) { C[i][j] = T[i][j] = INFTY; }
	rep(i,1,k){
	    scanf("%d %d %d %d", &s, &t, &cost, &tm);
	    C[s][t] = C[t][s] = cost;
	    T[s][t] = T[t][s] = tm;
	}
	scanf("%d", &q);
	rep(i,1,q){
	    scanf("%d %d %d", &s, &t, &r);
	    cout << dijkstra(s, t, r) << endl;
	}
    }
}
