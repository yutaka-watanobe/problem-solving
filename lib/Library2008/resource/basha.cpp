// begin_of_source
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<climits>
#include<queue>

using namespace std;

#define INFTY 1 << 21
#define TMAX 8
#define MAX 30
#define VMAX 256

class Node{
    public:
    int id, state;
    double cost;
    Node(){}
    Node( int id, int state, double cost ): id(id), state(state), cost(cost){}
    
    bool operator < ( const Node &n ) const {
	return cost > n.cost;
    }
};

int nticket, nnode, p, source, target;
int T[TMAX +1], M[MAX+1][MAX+1];

double dijkstra(){
    bool visited[MAX+1][VMAX];
    double d[MAX+1][VMAX];
    int p = 1; p = p << nticket;

    for ( int i = 1; i <= nnode; i++ ){
	for ( int j = 0; j < p; j++ ){
	    d[i][j] = INFTY;
	    visited[i][j] = false;
	}
    }

    d[source][0] = 0;
    priority_queue<Node> PQ;
    PQ.push( Node( source, 0, 0.0) );

    while ( !PQ.empty()) {
	int u, k;
	Node curr = PQ.top(); PQ.pop();
	u = curr.id;
	k = curr.state;

	if ( u == target ) return d[u][k];
	if ( d[u][k] < curr.cost ) continue;
	d[u][k] = curr.cost;

	if ( visited[u][k] ) continue;

	visited[u][k] = true;

	for ( int v = 1; v <= nnode; v++ ){
	    if ( M[u][v] == INFTY ) continue;
	    
	    int l = 1;
	    for ( int use = 1; use <= nticket; use++, l = l << 1 ){
		int next = k | l;
		if ( k == next ) continue; // already used
		if ( visited[v][next] ) continue;
		
		double cost = curr.cost + 1.0 * M[curr.id][v] / T[use];

		if ( cost < d[v][next] ){
		    d[v][next] = cost;
		    PQ.push( Node( v, next, cost ) );
		}
	    }
	}
    }

    return INFTY;
}

void compute(){
    double cost = dijkstra();
    if ( cost == INFTY ) cout << "Impossible" << endl;
    else printf("%.3lf\n", cost);
}

void init(){
    for ( int i = 1; i <= nnode; i++ ){
	for ( int j = 1; j <= nnode; j++ ){
	    M[i][j] = INFTY;
	}
    }
}

bool input(){
    cin >> nticket >> nnode >> p >> source >> target;
    if ( nticket == 0 ) return false;
    for ( int i = 1; i <= nticket; i++ ) cin >> T[i];
    int x, y, z;

    init();
	    
    for ( int i = 0; i < p; i++ ){
	cin >> x >> y >> z;
	M[x][y] = M[y][x] = z;
    }
    return true;
}

main(){
    while ( input() ) compute();
}
// end_of_source
