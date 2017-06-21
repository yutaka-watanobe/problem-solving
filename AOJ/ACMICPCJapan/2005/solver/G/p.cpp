#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 50
#define NMAX 80

class Node{
    public:
    vector<int> adjList;
    Node(){}
    void insert( int i ){ adjList.push_back(i);}
};

class Network{
    public:
    vector<Node> nodes;
    Network(){}

    int size(){ return nodes.size(); }
    void addNode(){ nodes.push_back(Node()); }

    void connect( int i, int j ){
	nodes[i].insert(j); nodes[j].insert(i);
    }

    void addNewNodes( int target, int diff, int u ){
	if ( diff == 1 ){
	    connect( target, u );
	} else {
	    for ( int i = 1; i < diff; i++ ){
		addNode();
		if ( i == 1 ) connect( target, size()-1 );
		else connect( size()-2, size()-1);
	    }
	    connect( size()-1, u );
	}
    }
};

class State{
    public:
    int cur, pre, d;
    State(){}
    State(int cur, int pre, int d): cur(cur), pre(pre), d(d){}
};

int N, M[MAX][MAX];
Network network;

int getDistance(int s, int t){
    queue<State> Q;
    Q.push(State(s, -1, 0));
    State u;
    while( !Q.empty() ){
	u = Q.front(); Q.pop();
	if ( u.cur == t ) return u.d;
	for ( int i = 0; i < network.nodes[u.cur].adjList.size(); i++ ){
	    int v = network.nodes[u.cur].adjList[i];
	    if ( v != u.pre ){
		Q.push(State(v, u.cur, u.d + 1));
	    }
	}
    }
}

int parse( int source, int end ){
    int pre = M[end+1][0] - getDistance( source, 0 );
    int d;
    for ( int t = 1; t <= end; t++ ){
	d = M[end+1][t] - getDistance( source, t );
	if ( pre != d ) return -1;
    }
    return pre;
}

void addNewNode( int u ){
    for ( int target = N; target < network.size(); target++ ){
	int diff = parse(target, u - 1);
	if ( diff > 0 ) {
	    network.addNewNodes(target, diff, u);
	    return;
	}
    }
}

void compute(){
    network = Network();
    for ( int i = 0; i < N + 1; i++ ) network.addNode();
    network.connect( 0, network.size()-1);

    for ( int i = 1; i < N; i++ ) addNewNode(i);

    vector<int> degree;
    for ( int i = N; i < network.size(); i++ ) {
	degree.push_back(network.nodes[i].adjList.size());
    }
    sort(degree.begin(), degree.end());
    
    for ( int i = 0; i < degree.size(); i++ ){
	if ( i ) cout << " ";
	cout << degree[i];
    }
    cout << endl;
}

bool input(){
    cin >> N;
    if ( N == 0 ) return false;
    for ( int i = 0; i < N; i++ ){
	for ( int j = 0; j < N; j++ ) cin >> M[i][j];
    }
    return true;
}

main(){
    while ( input() ) compute();
}

