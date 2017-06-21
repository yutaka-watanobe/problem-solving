#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>
using namespace std;
#define rep(i,n) for ( int i = 0; i < (int)n; i++)
#define INFTY (1<<21)
#define NMAX 12 // nshop = 10
#define IMAX 15
#define SMAX 32768 // (1<<IMAX)

class State{
    public:
    int pos, state, cost;
    State(int p=0, int s=0, int c=0): pos(p), state(s), cost(c){}

    bool operator < ( const State &s) const{
	return cost > s.cost;
    }
};

int G[NMAX+1][NMAX+1], nshop, nitem;
vector<pair<string, int> > S[NMAX]; // shop

pair<string, int> L[IMAX]; // list
map<string, int> N_I; // name to index


int getCheapest( string name ){
    int cheapest = INFTY;
    for ( int i = 1; i <= nshop; i++ ){
	rep(j, S[i].size()){
	    if ( S[i][j].first == name && S[i][j].second < cheapest ) cheapest = S[i][j].second;
	}
    }
    return cheapest;
}


int dijkstra(){
    priority_queue<State> PQ;
    int D[NMAX][SMAX];
    bool V[NMAX][SMAX];
    rep(i, nshop+1) rep(j, (1<<nitem)) { D[i][j] = INFTY; V[i][j] = false; }

    PQ.push(State(0, 0, 0));
    D[0][0] = 0;

    State u, v;
    while( !PQ.empty() ){
	u = PQ.top(); PQ.pop();
	//	cout << u.pos << " " << u.state << " " << u.cost << endl;
	if ( u.pos == 0 && u.state == (1<<nitem)-1 ) return u.cost;

	rep(adj, nshop+1){
	    if ( G[u.pos][adj] == INFTY ) continue;
	    v = u;
	    int nstate = v.state;
	    for ( int i = 0; i < nitem; i++ ){ // is it possible to bye item i in shop adj??
		bool possible = false;
		for ( int j = 0; j < S[adj].size(); j++ ){
		    if ( S[adj][j].first == L[i].first && S[adj][j].second == L[i].second) possible = true;
		}
		if ( possible ) nstate |= (1<<i);
	    }
	    v.state = nstate;
	    v.pos = adj;
	    if ( D[u.pos][u.state] + G[u.pos][adj] < D[v.pos][v.state] ){
		D[v.pos][v.state] = D[u.pos][u.state] + G[u.pos][adj];
		v.cost = D[v.pos][v.state];
		PQ.push(v);
	    }
	}
    }

    return INFTY;
}

void print(){
    // print list
    for ( int i = 0; i < nitem; i++ ){
	cout << L[i].first << " " << L[i].second << endl;
    }
}

main(){
    int k, v, m, s, t, c;
    string name;
    while( cin >> nshop && nshop ){
	S[0].clear();
	for ( int i = 1; i <= nshop; i++ ){
	    S[i].clear();
	    cin >> k;
	    rep(j, k){
		cin >> name >> v; S[i].push_back(make_pair(name, v));
	    }
	}
	cin >> nitem;
	int total = 0;
	N_I = map<string, int>();
	rep(i, nitem){
	    cin >> L[i].first;
	    L[i].second = getCheapest(L[i].first);
	    total += L[i].second;
	    N_I[L[i].first] = i;
	}
	rep(i, nshop+1) rep(j, nshop+1) G[i][j] = INFTY;
	cin >> m;
	rep(i, m){
	    cin >> s >> t >> c;
	    G[s][t] = G[t][s] = c;
	}
	//	print();
	int cost = dijkstra();
	if ( cost == INFTY ) cout << "impossible" << endl;
	else cout << total << " " << cost << endl;
    }
}
