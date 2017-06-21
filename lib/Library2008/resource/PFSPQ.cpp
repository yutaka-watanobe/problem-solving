// 423
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#define MAX 101

using namespace std;

// begin_of_source
class Graph{
    public:
    vector<vector<int> > adjList;
    vector<vector<int>::iterator> pos;

    Graph(){}
    Graph( int size ){ resize( size );}

    void resize( int size ){
	adjList.resize( size ); pos.resize( size );
	for ( int i = 0; i < size; i++ ) adjList[i].clear();
    }

    int size(){ return adjList.size(); }
    
    void insert( int i, int j ){
	adjList[i].push_back( j );
    }

    int next( int i ){
	if ( pos[i] == adjList[i].end() ) return -1;
	return *pos[i]++;
    }

    void reset( int i ){ pos[i] = adjList[i].begin(); }
    void reset(){ for( int i = 0; i < size(); i++ ) reset(i); }
};

class Node{
    public:
    int id, cost;
    Node(){}
    Node( int id, int cost ): id(id), cost(cost){}

    bool operator < ( const Node &n ) const{
	return cost > n.cost;
    }
};

int size;
int M[MAX][MAX];
Graph graph;

void dijkstra( int s, int d[] ){
    bool visited[MAX]; // S Ç…ëÆÇ∑ÇÈÉmÅ[ÉhÇÕ true
    for ( int i = 0; i < size; i++ ){
	d[i] = INT_MAX;
	visited[i] = false;
    }

    d[s] = 0; 

    priority_queue<Node> PQ;
    PQ.push( Node( s, 0 ) );// ç≈èâÇ… s Ç™ u Ç∆ÇµÇƒëIÇŒÇÍÇÈ

    graph.reset();

    while( !PQ.empty() ){
	int u = PQ.top().id; PQ.pop();

	visited[u] = true; // u Ç S Ç…í«â¡

	int v;
	while ( ( v = graph.next( u ) ) != -1 ){
	    if ( visited[v] ) continue;
	    if ( d[u] + M[u][v] < d[v] ){
		d[v] =  d[u] + M[u][v];
		PQ.push( Node( v, d[v] ) );
	    }
	}
    }
}
// end_of_source

main(){
    cin >> size;
    graph = Graph( size );
    string x;
    for ( int i = 1; i < size; i++ ){
	for ( int j = 0; j < i; j++ ){
	    cin >> x;
	    if ( x == "x" ){
		M[i][j] = M[j][i] = INT_MAX;
	    } else {
		M[i][j] = M[j][i] = atoi(x.c_str());
		graph.insert( i, j );
		graph.insert( j, i );
	    }
	}
    }

    int d[MAX];
    dijkstra(0,  d );
    int maxvalue = 0;
    for ( int i = 0; i < size; i++ ){
	if ( d[i] != INT_MAX && maxvalue < d[i] ) maxvalue = d[i];
    }
    cout << maxvalue << endl;
}

