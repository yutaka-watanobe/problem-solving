// C++ @yutaka
// begin_of_library
#include<iostream>
#include<vector>
using namespace std;

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
// end_of_library

// begin_of_source
#define SIZE 1000

Graph graph = Graph( SIZE ); // graph structure
bool visited[SIZE];

int prenum[SIZE]; int parent[SIZE]; int lowest[SIZE]; int timer;

void dfs( int current, int prev ){

    // ノード current を訪問した直後の処理
    prenum[current] = timer; lowest[current] = timer;
    timer++;

    visited[current] = true;

    int next;

    while ( (next = graph.next( current )) != graph.END ){
        if ( !visited[next] ){
            // ノード current からノード next へ訪問する直前の処理
            parent[next] = current;

            dfs( next, current );

            // ノード next の探索が終了した直後の処理
            lowest[current] = min( lowest[current], lowest[next] );
        } else if ( next != prev ){
            // エッジ current --> next が Back-edge の場合の処理
            lowest[current] = min( lowest[current], prenum[next] );
        }
    }

    // ノード current の探索が終了した直後の処理


}

void depthFirstSearchScheme(){
    for ( int i = 0; i < SIZE; i++ ) visited[ i ] = false;
    int root = 0;
    timer = 1;
      
    graph.reset();

    // lowest の計算
    dfs( root, -1 );
}

// end_of_source

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

void output(){
    cout << endl;
    for ( int i = 0; i < SIZE; i++ ){
	cout << i << " ---> pre = " << prenum[i] << "  lowest = " << lowest[i] << endl;
    }
}

int main(){
    inputGraph();
    depthFirstSearchScheme();
    output();
    return 0;
}
