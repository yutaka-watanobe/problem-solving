// 11710:Expensive subway:2.5:MST Prim
// 1.47sec
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

#define MAX 400
#define INFTY INT_MAX

class Edge{
    public:
    int target, cost;
    Edge( int target=0, int cost=0 ): target(target), cost(cost){}
};

int prim(int N, vector<Edge> adj[MAX]){
    priority_queue<pair<int, int> > PQ;
    int D[MAX];
    pair<int, int> P[MAX];
    bool V[MAX];
    rep(i, N) { D[i] = INFTY; V[i] = false;}
    D[0] = 0;
    P[0] = make_pair(-1, 0);
    PQ.push(make_pair(0, 0));
    
    pair<int, int> u;
    while(!PQ.empty()){
	u = PQ.top(); PQ.pop();
	V[u.second] = true;
	for ( int i = 0; i < adj[u.second].size(); i++ ){
	    int v = adj[u.second][i].target;
	    int c = adj[u.second][i].cost;
	    if ( !V[v] && D[v] > c ){
		P[v] = make_pair(u.second, c);
		D[v] = c;
		PQ.push(make_pair(c*(-1), v));
	    }
	}
    }
    int sum = 0;
    rep(i, N){
	if ( !V[i] ) return -1;
	sum += P[i].second;
    }
    return sum;
}

int main(){
    int N, M, cost;
    string source, target;
    while(1){
	cin >> N >> M;
	if ( N == 0 && M == 0 ) break;
	map<string, int> NM;
	rep(i, N){
	    cin >> source;
	    NM[source] = i;
	}

	vector<Edge> adj[MAX];
	for ( int i = 0; i < M; i++ ){
	    cin >> source >> target >> cost;
	    adj[NM[source]].push_back(Edge(NM[target], cost));
	    adj[NM[target]].push_back(Edge(NM[source], cost));
	}
	cin >> source;

	int cost = prim(N, adj);
	if ( cost == -1 ) cout << "Impossible" << endl;
	else cout << cost << endl;
    }
}

