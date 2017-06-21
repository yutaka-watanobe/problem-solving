#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

#define MAX 2000
#define BLACK 1
#define WHITE 2

class Graph{
    public:
    int size;
    vector<int> adj[MAX];
    Graph( int size=0 ): size(size){}
    
    void connect(int i , int j){
	adj[i].push_back(j);
    }
};

int b, c;
Graph g;
int color[MAX];
vector<pair<int, int> > P;
int nb, nw;
bool valid;

void dfs(int u, int c){
    if ( c == BLACK ) nb++;
    else if ( c == WHITE) nw++;
    color[u] = c;
    for ( int i = 0; i < g.adj[u].size(); i++ ){
	int v = g.adj[u][i];
	if ( color[v] == c ) valid = false;
	int nc = ((c==BLACK)?WHITE:BLACK);
	if ( color[v] == 0 ) dfs(v, nc);
    }
}

bool makeComponents(){
    for ( int i = 0; i < g.size; i++ ) color[i] = 0;
    P.clear();

    for ( int i = 0; i < g.size; i++ ){
	nb = nw = 0;
	valid = true;
	if ( color[i] == 0 ){ 
	    dfs(i, BLACK); 
	    if ( !valid ) return false;
	    P.push_back(make_pair(min(nb, nw), max(nb, nw)));
	}
    }

    for ( int u = 0; u < g.size; u++ ){
	assert( color[u] != 0 );
	for ( int i = 0; i <  g.adj[u].size(); i++ ){
	    int v = g.adj[u][i];
	    if ( color[u] == color[v] ) return false;
	}
    }

    return true;
}


bool checkSum(){
    bool T[MAX+1][MAX];

    int limit = g.size;

    for ( int i = 0; i <= g.size; i++ ){
	for ( int j = 0; j < P.size(); j++ ) T[i][j] = false;
    }
    
    T[P[0].first][0] = T[P[0].second][0] = true;

    int next;

    for ( int j = 1; j < P.size(); j++ ){
	for ( int i = 0; i <= limit; i++ ){
	    if ( !T[i][j-1] ) continue;
	    next = i + P[j].first;
	    if ( next <= limit ) T[next][j] = true;
	    next = i + P[j].second;
	    if ( next <= limit ) T[next][j] = true;
	}
    }

    return ( T[b][P.size()-1] || T[c][P.size()-1] );
}

bool compute(){
    int a, s, d;
    cin >> b >> c >> a;
    g = Graph(b+c);
    for ( int i = 0; i < a; i++ ){
	cin >> s >> d; s--; d--;
	g.connect(s, d);
	g.connect(d, s);
    }

    if ( !makeComponents() ) return false;


    return checkSum();
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) {
	if ( compute() ) cout << "yes" << endl;
	else cout << "no" << endl;
    }
}

