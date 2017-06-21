// Priority First Search
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 101
#define INFTY 10000000
using namespace std;

class Graph{
    public:
    int M[MAX][MAX]; // adj matrix
    int adjList[MAX][MAX];
    int size[MAX];

    Graph(){}
    Graph( int n ){
	for ( int i = 1; i <= n; i++ ) size[i] = 0;
	for ( int i = 1; i <= n; i++ )
	    for ( int j = 1; j <= n; j++ ) M[i][j] = INFTY;
    }
    
    void insert( int source, int target, int cost ){
	adjList[source][ size[source]++ ] = target;
	M[source][target] = cost;
    }
};

class State{
    public:
    int p1, p2, cost;
    State(){}
    State( int p1, int p2, int cost): p1(p1), p2(p2), cost(cost){}

    bool operator < ( const State &s ) const{
	return cost > s.cost;
    }
};

Graph graph;
int n, m, s, g1, g2;

int dijkstra(){
    priority_queue<State> PQ;
    bool visited[MAX][MAX];
    int cost[MAX][MAX];
    for ( int i = 1; i <= n; i++ ){
	for ( int j = 1; j <= n; j++ ){
	    visited[i][j] = false;
	    cost[i][j] = INFTY;
	}
    }

    PQ.push( State( s, s, 0 ) );
    cost[s][s] = 0;

    State u;
    while ( !PQ.empty() ){
	u = PQ.top(); PQ.pop();
	if ( u.p1 == g1 && u.p2 == g2 ) return u.cost;
	visited[u.p1][u.p2] = true;

	int v1, v2;
	for ( int i = 0; i < graph.size[u.p1]; i++ ){
	    v1 = graph.adjList[u.p1][i];
	    for ( int j = 0; j < graph.size[u.p2]; j++ ){
		v2 = graph.adjList[u.p2][j];

		if ( visited[v1][v2] ) continue;

		int nextcost;
		if ( v1 == v2 && u.p1 == u.p2) nextcost = cost[u.p1][u.p2] + graph.M[u.p1][v1];
		else nextcost = cost[u.p1][u.p2] + graph.M[u.p1][v1] + graph.M[u.p2][v2];
		if ( nextcost < cost[v1][v2] ){
		    cost[v1][v2] =  nextcost;
		    PQ.push( State( v1, v2, cost[v1][v2] ) );
		}
	    }
	}
    }

    return cost[g1][g2];
}

bool input(){
    int source, target, cost;
    cin >> n >> m >> s >> g1 >> g2;
    if ( n == 0 ) return false;
    graph = Graph( n );

    for ( int i = 0; i < m; i++ ){
	cin >> source >> target >> cost;
	graph.insert( source, target, cost );
    }
    for ( int i = 1; i <= n; i++ ) graph.insert( i, i, 0 );
    return true;
}

main(){
    while ( input() ) cout << dijkstra() << endl;
}
