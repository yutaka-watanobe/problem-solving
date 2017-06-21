#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 520
#define INFTY (1<<22)

using namespace std;

// source = node 0
// sink = node size-1
class Network{
    public:
    int size, flow[MAX][MAX], capacity[MAX][MAX];

    vector<int> adjLists[MAX];
    vector<int>::iterator it[MAX];

    Network(){}
    Network( int size ): size(size){
	for ( int i = 0; i < size; i++ ){
	    for ( int j = 0; j < size; j++ ){
		flow[i][j] = capacity[i][j] = 0;
	    }
	}
    }

    int next( int node ){
	if ( it[node] != adjLists[node].end() ) return *it[node]++;
	else return -1;
    }

    void insert( int source, int target, int cap ){
	adjLists[source].push_back( target );
	adjLists[target].push_back( source );
	capacity[source][target] = cap;
    }

    void reset( int node ){
	it[node] = adjLists[node].begin();
    }
    void reset(){
	for ( int node = 0; node < size; node++ ) reset(node);
    }
};

bool bfs( Network &network, int pi[], int source, int target ){
    bool visited[MAX];
    queue<int> Q;

    for ( int i = 0; i < network.size; i++ ) {
	visited[i] = false;
	pi[i] = -1;
    }

    int u, v;
    Q.push( source );
    visited[source] = true;
    network.reset();

    while( !Q.empty() ){
	u = Q.front(); Q.pop();

	if ( u == target ) return true;
	
	while ( ( v = network.next(u) ) != -1 ){
	    if ( visited[v] ) continue;
	    if ( network.capacity[u][v] > network.flow[u][v] ){
		pi[v] = u;
		visited[v] = true;
		Q.push(v);
	    }
	}
    }
    return false;
}

void edmonds_karp( Network &network, int source, int target ){
    int flow;
    int pi[MAX];

    while ( bfs( network, pi, source, target ) ){
      flow = INFTY;
	for ( int v = network.size-1; v != 0; v = pi[v] ){
	  int u = pi[v];
	  flow = min( flow, network.capacity[u][v] - network.flow[u][v]);
	}

	for ( int v = network.size-1; v != 0; v = pi[v] ){
	    int u = pi[v];
	    network.flow[u][v] += flow;
	    network.flow[v][u] = -network.flow[u][v];
	}
    }

    int v;
    network.reset(0);
    for ( flow = 0; (v=network.next(0)) != -1; flow += network.flow[0][v] );
    cout << flow << endl;
}

Network network;
int M, W, size;

bool input(){
    cin >> M >> W;
    if ( M == 0 && W == 0 ) return false;
    int n, c, s, t;
    size = 2*M;

    network = Network(size);
    for ( int i = 0; i < M-2; i++ ){
	cin >> n >> c;
	n--;
	network.insert(2*n, 2*n+1, c);
    }
    network.insert(0, 1, INFTY);
    network.insert(size-2, size-1, INFTY);


    for ( int i = 0; i < W; i++ ){
	cin >> s >> t >> c;
	s--; t--;
	if ( t < s ) swap(s, t);

	network.insert(2*s+1, 2*t, c);
	network.insert(2*t+1, 2*s, c);

    }
    return true;
}


main(){
    while(input()){
	edmonds_karp( network, 0, network.size - 1 );
    }
}
