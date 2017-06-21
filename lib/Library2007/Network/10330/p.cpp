#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 220
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
    cout << flow << endl;
}

Network network;
int n;

int input(){
    int M, B, D, source, target, cap;
    cin >> n;
    if(cin.eof()) return 0;
    
    network = Network(2*n+2);
    
    /* 各ノードをエッジに見立てる */
    for(int i=1; i<=2*n; i+=2){
	cin >> cap;
	network.insert(i, i+1, cap); 
	network.insert(i+1, i, cap); 
    }
    
    cin >> M;
    
    for(int i=0; i<M; i++){
	cin >> source >> target >> cap;
	network.insert(source*2, target*2-1, cap);
    }
    
    cin >> B >> D;
    
    for(int i=0; i<B; i++){
	cin >> target;
	network.insert(0, target*2-1, INT_MAX);
    }
    
    for(int i=0; i<D; i++){
	cin >> source;
	network.insert(source*2, 2*n+1, INT_MAX);
    }
    
    return 1;
}


void compute(){
    edmonds_karp( network, 0, 2*n+1 );
}

main(){
    while(input()){
	compute();
    }
}
