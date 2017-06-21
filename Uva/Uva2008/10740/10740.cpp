#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define REP(i, e) for ( int i = 0; i < (int)e; i++ )
#define MAX 100
#define MAXK 10
#define INFTY (1<<21)

class Edge{
    public:
    int v, cost;
    Edge(){}
    Edge( int v, int cost): v(v), cost(cost){}
};

class State{
    public:
    int u, cost;
    State(){}
    State(int u, int cost):u(u), cost(cost){}

    bool operator < ( const State &s) const{
	if ( cost == s.cost ) return u > s.u;
	return cost > s.cost;
    }
};

vector<Edge> G[MAX];
int D[MAX][MAXK];

int size, source, target, K;

void kthDijkstra(){
    priority_queue<State> PQ;
    int L[MAX]; // level

    REP(i, size) REP(k, K){
	D[i][k] = INFTY;
    }
    REP(i, size) L[i] = 0;

    D[source][0] = 0;
    PQ.push(State(source, 0));

    State s;
    while(!PQ.empty()){
	s = PQ.top(); PQ.pop();
	if ( L[s.u] >= K ) continue;
	D[s.u][L[s.u]++] = s.cost;
	REP(i, G[s.u].size() ) if ( L[G[s.u][i].v] <= K ){
	    PQ.push(State(G[s.u][i].v, s.cost + G[s.u][i].cost ));
	}
    }
}

int compute(){
    kthDijkstra();
    if ( D[target][K-1] == INFTY ) return -1;
    else return D[target][K-1];
}

bool input(){
    int m, s, t, c;
    scanf("%d %d", &size, &m);
    if ( size == 0 && m == 0 ) return false;
    scanf("%d %d %d",  &source, &target, &K);
    source--; target--;
    REP(i, size) G[i].clear();
    REP(i, m){
	scanf("%d %d %d", &s, &t, &c);
	s--; t--;
	G[s].push_back(Edge(t, c));
    }

    return true;
}

int main(){
    while(input()) printf("%d\n", compute());
    return 0;
}
