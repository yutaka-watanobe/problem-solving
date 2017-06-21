// 423
#include<iostream>
#include<string>
#include<algorithm>
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

class Heap{
    public:
    int size;
    int H[MAX + 1]; // heap buffer
    int index[MAX + 1]; // index of v in the heap buffer
    int *key; // keys for heap condition

    Heap(){}
    Heap( int size, int d[] ): size(size){
	key = d;
    }

    void construct(){
	for ( int i = 0; i < size; i++ ){
	    H[i + 1] = i; // heap is 1 base not 0
	    index[i] = i + 1;
	}
	for ( int i = size / 2; i >= 1; i-- ) downheap( i );
    }
    
    int extractMin(){
	int v = H[1];
	H[1] = H[size];
	index[ H[size] ] = 1;
	size--;
	downheap(1);
	return v;
    }

    int update( int v ){
	upheap( index[v] );
    }

    private:
    void downheap( int k ){
	int j, v;
	v = H[k];
	while( k <= size/2 ){
	    j = k + k;
	    if ( j < size && key[ H[j] ] > key[ H[j+1] ] ) j++;
	    if ( key[v] <= key[ H[j] ] ) break;
	    H[k] = H[j];
	    index[ H[j] ] = k;
	    k = j;
	}
	H[k] = v;
	index[ v ] = k;
    }
    
    void upheap( int k){
	int v;
	v = H[k];
	while ( k > 1 && key[ H[k/2] ] >= key[v] ){
	    H[k] = H[k/2];
	    index[ H[k/2] ] = k;
	    k = k/2;
	}
	H[k] = v;
	index[v] = k;
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

    d[s] = 0; // ç≈èâÇ… s Ç™ u Ç∆ÇµÇƒëIÇŒÇÍÇÈ

    Heap heap = Heap( size, d );
    heap.construct();

    graph.reset();

    while( heap.size >= 1 ){
	int u = heap.extractMin();

	visited[u] = true; // u Ç S Ç…í«â¡

	int v;
	while ( ( v = graph.next( u ) ) != -1 ){
	    if ( visited[v] ) continue;
	    if ( d[u] + M[u][v] < d[v] ){
		d[v] =  d[u] + M[u][v];
		heap.update( v );
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

