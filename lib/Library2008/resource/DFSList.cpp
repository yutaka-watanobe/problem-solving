// C++ @yutaka
// begin_of_library
#include<iostream>
#include<vector>
using namespace std;

// begin_of_source
class Graph{
    private:
    vector<vector<int> > adjList;
    vector<vector<int>::iterator> pos;

    public:
    static const int END = -1;
    Graph(){}
    Graph( int n ) { resize(n); }

    void resize( int n ){
	adjList.resize(n), pos.resize(n);
	for ( int i = 0; i < n; i++ ){
	    adjList[i].clear();
	}
    }
    
    int size(){ return adjList.size(); }

    void insert( int source, int target ){
	adjList[source].push_back( target );
    }
    
    int next( int source ){
	if ( pos[source] == adjList[source].end() ) return END;
	return *pos[source]++;
    }
    
    void reset( int i ){ pos[i] = adjList[i].begin(); }
    void reset(){ for ( int i = 0; i < size(); i++ ) reset(i); }
};

Graph graph = Graph( SIZE ); // graph structure
bool visited[ SIZE ];

void dfs( int currentNode ){

    visited[ currentNode ] = true;

    int nextNode;

    while ( (nextNode = graph.next( currentNode )) != graph.END ){
	if ( visited[ nextNode ] ) continue;
	dfs( nextNode );
    }
}

void depthFirstSearchScheme(){
    for ( int i = 0; i < SIZE; i++ ) visited[ i ] = false;
    int startNode = 0;

    graph.reset();
    dfs( startNode );
}

void inputGraph(){

    int source, target;
    // input based on adjList
    cout << "input edges: ";
    while (1){
	cin >> source >> target;
	if ( source == -1 && target == -1 ) break;
	graph.insert( source, target );
	graph.insert( target, source );
    }
}

int main(){
    inputGraph();
    depthFirstSearchScheme();

    return 0;
}
// end_of_source
