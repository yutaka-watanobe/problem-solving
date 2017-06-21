#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//#define REP(i, e) for ( int i = 0; i < (int)e; i++ )
#define MAX 1000


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
	if ( cap <= 0 ) return;
	if ( capacity[source][target] == 0 ){
	    adjLists[source].push_back( target );
	    adjLists[target].push_back( source );
	    capacity[source][target] = cap;
	    capacity[target][source] = cap;
	    
	} else {
	    capacity[source][target] += cap;
	    capacity[target][source] += cap;
	}
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
    if ( source == target ) return 0;
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

Network network;
int size, source, target;

void input(){
    int s, t, c, cap;
    cin >> source >> target >> c;

    //    if ( source > target ) swap(source, target );

    network = Network(size+2);

    for ( int i = 0; i < c; i++ ){
	cin >> s >> t >> cap;

	if ( s == source ) s = 0;
	if ( s == target ) s = size+1;
	if ( t == source ) t = 0;
	if ( t == target ) t = size+1;

	network.insert( s, t, cap );
    }
}

int main(){
    int tcase = 1;
    while(cin >> size && size ){
	cout << "Network " << tcase++ << endl;
	input();
	cout << "The bandwidth is " << edmonds_karp( network, 0, size+1 ) << "." << endl;
	cout << endl;
    }

    return 0;
}
