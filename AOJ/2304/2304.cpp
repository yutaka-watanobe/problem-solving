
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>

#define MAX 300
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
	capacity[target][source] = cap; // special code for this problem
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
bool inG[MAX][MAX];
int T[MAX][MAX];
pair<int, int> M[MAX*MAX];
int size, m;

int input(){

    cin >> size >> m;
    network = Network(size);

    int source, target, cap;
    for ( int i = 0; i < size; i++ ){
      for ( int j = 0; j < size; j++ ) inG[i][j] = false;
    }

    for ( int i = 0; i < m; i++ ){
      cin >> source >> target;
      source--; target--;
      T[source][target] = i;
      M[i] = make_pair(source, target);
      network.insert( source, target, 1 );
      //      network.insert( target, source, 1 );
      inG[source][target] = true;
    }


}

main(){
    input();
    int s, t; cin >> s >> t;
    s--; t--;
    edmonds_karp( network, s, t );
    vector<int> ans;

    for ( int i = 0; i < m; i++ ){
      int s = M[i].first;
      int t = M[i].second;
      //      if ( inG[s][t] && network.flow[s][t] == 0 && network.flow[t][s] == 1 ) ans.push_back(i+1); 
      if ( network.flow[t][s] > 0 ) ans.push_back(i+1); 
    }
    cout << ans.size() << endl;
    for ( int i = 0; i < ans.size(); i++ ) cout << ans[i] << endl;
   
}
