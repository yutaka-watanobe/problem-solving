#include<iostream>
#include<vector>
#include<queue>

#define MAX 100
using namespace std;

class Edge{
    public:
    int source, target;
    int capacity, flow;
    Edge(){}
    Edge( int source, int target, int capacity ): source(source), target(target), capacity(capacity){
	flow = 0;
    }
};

// source = node 0
// sink = node size-1
class Network{
    public:
    int size, maxflow;
    int flow[MAX][MAX], capacity[MAX][MAX];

    vector<int> adjLists[MAX];
    vector<int>::iterator it[MAX];

    Network(){}
    Network( int size ): size(size){
	maxflow = 0;
	for ( int i = 0; i < size; i++ ){
	    for ( int j = 0; j < size; j++ ){
		flow[i][j] = 0;
		capacity[i][j] = 0;
	    }
	}
    }

    int next( int node ){
	if ( it[node] != adjLists[node].end() ) return *it[node]++;
	else return -1;
    }

    void insert( int source, int target, int cap ){
	adjLists[source].push_back( target );
	capacity[source][target] = cap;
    }

    void reset( int node ){
	it[node] = adjLists[node].begin();
    }
    void reset(){
	for ( int node = 0; node < size; node++ ) reset(node);
    }
};


Network network;


void input(){
    int size, m;
    cin >> size >> m;
    network = Network(size);

    int source, target, cap;

    for ( int i = 0; i < m; i++ ){
	cin >> source >> target >> cap;
	network.insert( source, target, cap );
    }
}

bool bfs( int &add, int pi[] ){
    bool visited[MAX];
    queue<int> Q;

    for ( int i = 0; i < network.size; i++ ) {
	visited[i] = false;
	pi[i] = -1;
    }
    add = INT_MAX;

    int u, v;
    Q.push( 0 );
    visited[0] = true;
    network.reset();
    while( !Q.empty() ){
	u = Q.front(); Q.pop();

	if ( u == network.size - 1 ) return true;
	
	while ( ( v = network.next(u) ) != -1 ){
	    if ( visited[v] ) continue;
	    if ( network.capacity[u][v] > 0 &&
		 network.capacity[u][v] > network.flow[u][v] ){
		add = min( add, network.capacity[u][v] - network.flow[u][v]);
		pi[v] = u;
		visited[v] = true;
		Q.push(v);
	    }
	}

    }
    return false;
}

void simulate(){
    cout << "simulate" << endl;
    bool cont = true;
    int add;
    int pi[MAX];

    while ( 1 ){
	cont = bfs( add, pi );
	if ( !cont ) break;
	
	network.maxflow += add;

	int pos = network.size - 1;
	while (1){
	    if ( pi[pos] == -1 ) break;
	    int u = pi[pos];
	    int v = pos;
	    network.flow[u][v] += add;
	    network.flow[v][u] = -network.flow[u][v];
	    pos = pi[pos];
	}
	
    }

    cout << "maximul flow = " << network.maxflow << endl;
}

main(){
    input();
    simulate();
}
