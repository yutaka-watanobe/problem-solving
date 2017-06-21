#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define REP(i, n) for ( int i = 0; i < (int)n; i++ )
#define FOR(i, s, e) for ( int i = s; i <= (int)e; i++ )
#define MAX 2000

class Node{
    public:
    string name, lang1, lang2;
    vector<int> adj;

    Node(){}
    Node(string name, string l1, string l2): name(name), lang1(l1), lang2(l2){}
};

class State{
    public:
    int id, cost;
    State(){}
    State( int id, int cost): id(id), cost(cost){}
    bool operator < ( const State &s ) const{
	if ( cost == s.cost ) return id < s.id;
	else return cost > s.cost;
    }
};

int size;
Node G[MAX];
string startL, lastL;

void dijkstra( int source, int D[MAX] ){
    bool V[MAX];
    REP(i, size) { D[i] = INT_MAX; V[i] = false; }

    priority_queue<State> PQ;
    PQ.push(State(source, 0));
    D[source] = G[source].name.size();

    State u;
    while(!PQ.empty()){
	u = PQ.top(); PQ.pop();

	if ( V[u.id] ) continue;
	V[u.id] = true;

	for ( int i = 0; i < G[u.id].adj.size(); i++ ){
	    int v = G[u.id].adj[i];
	    if ( V[v] ) continue;
	    if ( D[v] > D[u.id] + G[v].name.size() ){
		D[v] = D[u.id] + G[v].name.size();
		PQ.push(State(v, D[v]));
	    }
	}
    }
}

void compute(){
    int ans = INT_MAX;
    int D[MAX];

    REP(source, size){
	if ( G[source].lang1 == startL || G[source].lang2 == startL ){
	    dijkstra(source, D);
	    REP(target, size){
		if ( source == target ) continue;
		if ( G[target].lang1 == lastL || G[target].lang2 == lastL ){
		    ans = min( ans, D[target] );
		}
	    }
	}
    }

    if ( ans == INT_MAX ) cout << "impossivel" << endl;
    else cout << ans << endl;
}

void input(){
    string name, l1, l2;
    cin >> startL >> lastL;
    char str1[51], str2[51], str3[51];
    REP(i, size){
	//	cin >>  l1 >> l2 >> name;
	scanf("%s %s %s", str1, str2, str3);
	//	G[i] = Node( name, l1, l2 );
	G[i] = Node( string(str3), string(str1), string(str2));
    }
    FOR(i, 0, size-2) FOR(j, i+1, size-1){
	if ( G[i].name[0] == G[j].name[0] ) continue;
	if ( G[i].lang1 == G[j].lang1 ||
	     G[i].lang1 == G[j].lang2 ||
	     G[i].lang2 == G[j].lang1 ||
	     G[i].lang2 == G[j].lang2 ){
	    G[i].adj.push_back(j);
	    G[j].adj.push_back(i);
	}
    }
}

int main(){
    while ( cin >> size && size ) {
	input();
	compute();
    }
}
