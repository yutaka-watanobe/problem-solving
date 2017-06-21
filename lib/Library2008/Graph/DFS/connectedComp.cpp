#include<iostream>
using namespace std;

#define MAX 1000
int size;
int adjMatrix[MAX][MAX]; // graph structure
bool visited[MAX];
int group[MAX];

void visit( int currentNode, int id ){
    visited[currentNode] = true;
    group[currentNode] = id;

    for ( int nextNode = 0; nextNode < size; nextNode++ ){
	if ( !adjMatrix[currentNode][nextNode] ) continue;
	if ( !visited[nextNode] ){
	    visit( nextNode, id );
	}
    }
}

void depthFirstSearch(){
    for ( int i = 0; i < size; i++ ) visited[ i ] = false;
    int number = 1;
    for ( int startNode = 0; startNode < size; startNode++ ){
	if ( !visited[startNode] ) visit( startNode, number++ );
    }
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

    for ( int i = 0; i < size; i++ ){
	cout << i << " " << group[i] << endl;
    }
    return 0;
}
