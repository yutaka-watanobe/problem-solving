#include<iostream>
using namespace std;


// begin_of_source
#define MAX 1000
int size;
int adjMatrix[MAX][MAX]; // graph structure
bool visited[MAX];

void visit( int currentNode ){
    visited[ currentNode ] = true;

    // perform some activities here

    for ( int nextNode = 0; nextNode < size; nextNode++ ){
	if ( !adjMatrix[ currentNode ][ nextNode ] ) continue;
	if ( !visited[ nextNode ] ){
	    visit( nextNode );
	}
    }
}

void depthFirstSearch(){
    for ( int i = 0; i < size; i++ ) visited[ i ] = false;
    int startNode = 0;

    visit( startNode );
}

void inputGraph(){
    cin >> size;

    for ( int i = 0; i < size; i++ ){
	for ( int j = 0; j < size; j++ ){
	    adjMatrix[i][j] = 0;
	}
    }

    int source, target;
    // input based on adjMatrix
    for ( int source = 0; source < size; source++ ){
	for ( int target = 0; target < size; target++ ){
	    cin >> adjMatrix[source][target];
	}
    }
}

int main(){
    inputGraph();
    depthFirstSearch();

    return 0;
}
// end_of_source
