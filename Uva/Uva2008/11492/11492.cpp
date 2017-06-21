#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
#include<climits>
using namespace std;
#define REP(i, n) for ( int i = 0; i < (int)n; i++ )
#define FOR(i, s, e) for ( int i = s; i <= (int)e; i++ )
#define MAX 2000*2+2

class Edge{
    public:
    int v, cost;
    string name;
    Edge(){}
    Edge( int v, string name): v(v), name(name){ cost = name.size();}
};

class Node{
    public:
    vector<Edge> adj;
    Node(){}
};

class State{
    public:
    int id, cost;
    char in;
    State(){}
    State( int id, char in, int cost): id(id), cost(cost), in(in){}

    bool operator < ( const State &s ) const{
	if ( cost == s.cost ) return id < s.id;
	else return cost > s.cost;
    }
};

int size;
Node G[MAX];
string startL, lastL;
map<string, int> NtoI;

int dijkstra( int source, int target){
    bool V[MAX][26];
    int D[MAX][26];
    priority_queue<State> PQ;

    REP(i, size) REP(j, 26) { D[i][j] = INT_MAX; V[i][j] = false; }

    for ( int i = 0; i < G[source].adj.size(); i++ ){
	Edge e = G[source].adj[i];
	PQ.push(State(e.v, e.name[0], e.cost));
	//	D[e.v][e.name[0]-'a'] = e.cost;
    }

    State u;

    while(!PQ.empty()){
	u = PQ.top(); PQ.pop();

	//	if ( u.id == target ) return D[u.id][u.in-'a'];
	if ( u.id == target ) return u.cost;

	if ( V[u.id][u.in-'a'] ) continue;
	V[u.id][u.in-'a'] = true;

	for ( int i = 0; i < G[u.id].adj.size(); i++ ){
	    Edge e = G[u.id].adj[i];
	    if ( e.name[0] == u.in ) continue;
	    int v = e.v;
	    char vin = e.name[0];

	    if ( V[v][vin-'a'] ) continue;

	    //	    int c = D[u.id][u.in-'a'];
	    int c = u.cost;

	    if ( D[v][vin-'a'] > c + e.cost ){
		//		D[v][vin-'a'] = c + e.cost;
		//PQ.push(State(v, vin, D[v][vin-'a']));
		PQ.push(State(v, vin, c + e.cost));
	    }
	}
    }

    return INT_MAX;
}

void compute(){
    int cost =  dijkstra( NtoI[startL], NtoI[lastL]);
    if ( cost == INT_MAX ) cout << "impossivel" << endl;
    else cout << cost << endl;
}

int getIndex(string str){
    if ( NtoI.find(str) == NtoI.end() ){
	NtoI[str] = size++;
    }
    return NtoI[str];
}

int main(){
    int M;
    string name, l1, l2;
    char str1[51], str2[51], str3[51];
    int s, t;
    while ( cin >> M && M ) {
	size = 0;
	NtoI = map<string, int>();

	REP(i, MAX) G[i] = Node();
	cin >> startL >> lastL;
	getIndex(startL);
	getIndex(lastL);
	REP(i, M){
	    //	    cin >> l1 >> l2 >> name;
	    scanf("%s %s %s", str1, str2, str3);
	    s = getIndex(string(str1));
	    t = getIndex(string(str2));
	    G[s].adj.push_back(Edge(t, string(str3)));
	    G[t].adj.push_back(Edge(s, string(str3)));
	}
	compute();
    }
}



