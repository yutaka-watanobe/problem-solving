#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 1002
#define INFTY (1<21)
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

int edmonds_karp( Network &network, int source, int target ){
    int flow;
    int pi[MAX];

    while ( bfs( network, pi, source, target ) ){
	flow = INT_MAX;
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
    return flow;
}

int compute(){
    int nbolt, nnut;
    scanf("%d %d", &nbolt, &nnut);
    Network network = Network( nbolt + nnut + 2 );
    
    int m;
    for ( int i = 0; i < nbolt; i++ ){
	for ( int j = 0; j < nnut; j++ ){
	    scanf("%d", &m);
	    if ( m ) network.insert(i+1, j + nbolt+1, 1 );
	}
    }

    for ( int i = 1; i <= nbolt; i++ ) network.insert(0, i, INFTY);
    for ( int j = nbolt+1; j < nbolt+1+nnut; j++ ) network.insert(j, nbolt + nnut + 1, INFTY);
    
    return edmonds_karp(network, 0, nbolt + nnut + 1 );
}

int main(){
    int tcase; scanf("%d", &tcase);
    for ( int i = 1; i <= tcase; i++ ){
	printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", i, compute());
    }

    return 0;
}

