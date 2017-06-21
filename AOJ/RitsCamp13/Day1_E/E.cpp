#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define rep(i, e) for ( int i = 0; i < (int)e; i++ )
#define MAX 50
#define MAXK 10
#define MAXL 7
#define INFTY (1<<21)

class Edge{
    public:
    int v, cost;
    Edge(){}
    Edge( int v, int cost): v(v), cost(cost){}
};

class State{
    public:
	int u, b, cost;
    State(){}
    State(int u, int b, int cost):u(u), b(b), cost(cost){}

    bool operator < ( const State &s) const{
	if ( cost == s.cost ) {
	    if ( u == s.u ){
		return b == s.b;
	    } else {
		return u > s.u;
	    }
	} else {
	    return cost > s.cost;
	}
    }
};

vector<Edge> G[MAX];
int D[MAX][MAXK][1<<MAXL];
bool V[MAX][MAXK][1<<MAXL];
int B[MAX];

int size, source, target, K, L;

void kthDijkstra(){
    priority_queue<State> PQ;
    int LV[MAX][1<<L]; // level

    rep(i, size) rep(k, K) rep(l, (1<<L)){
	D[i][k][l] = INFTY;
	V[i][k][l] = false;
    }
    rep(i, size) rep(l, (1<<L)) LV[i][l] = 0;

    int bs = 0;
    if ( B[source] != -1 ) bs = (bs | (1<<B[source]));

    D[source][0][bs] = 0;
    V[source][0][bs] = true;
    PQ.push(State(source, bs, 0));

    State s;
    while(!PQ.empty()){
	s = PQ.top(); PQ.pop();
	if ( LV[s.u][s.b] >= K ) continue;
	V[s.u][LV[s.u][s.b]][s.b] = true;
	D[s.u][LV[s.u][s.b]++][s.b] = s.cost;
	
	rep(i, G[s.u].size() ){
	    int v = G[s.u][i].v;
	    bs = s.b;
	    if ( B[v] != -1 ) bs = (bs | (1<<B[v]));
	    if ( LV[v][bs] <= K ){
		if ( !V[v][LV[v][bs]][bs] ){
		    PQ.push(State(v, bs, s.cost + G[s.u][i].cost ));
		}
	    }
	}
    }
}

void compute(){
    kthDijkstra();
    if ( D[target][K-1][(1<<L)-1] == INFTY ) printf("NA\n");
    else printf("%d\n", D[target][K-1][(1<<L)-1]);
}

bool input(){
    int m, s, t, c;
    scanf("%d %d %d %d", &size, &m, &L, &K);
    if ( size == 0 && m == 0 && L == 0 && K == 0) return false;

    rep(i, size) B[i] = -1;
    rep(i, size) G[i].clear();
    rep(i, m){
	scanf("%d %d %d", &s, &t, &c);
	s--; t--;
	G[s].push_back(Edge(t, c));
	G[t].push_back(Edge(s, c));
    }

    scanf("%d %d",  &source, &target);
    source--; target--;
    rep(i, L){
	int p;
	scanf("%d", &p);
	B[p-1] = i;
    }
    return true;
}

int main(){
    while(input()) compute();
    return 0;
}
