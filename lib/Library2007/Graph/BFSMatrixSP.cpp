#include<iostream>
#include<queue>
using namespace std;

// begin_of_source
#define MAX 1000
int size;
int adjMatrix[MAX][MAX]; // graph structure

void breadthFirstSearch( int source ){
    queue< int > Q;
    bool visited[MAX];
    int dist[MAX];
    int pi[MAX];

    for ( int i = 0; i < size; i++ ) {
	visited[i] = false;
	dist[i] = INT_MAX;
    }
    int currentNode = source;    

    Q.push( currentNode );
    visited[currentNode] = true;
    dist[currentNode] = 0;
    pi[currentNode] = -1;

    while ( !Q.empty() ){
	currentNode = Q.front(), Q.pop();

	for ( int nextNode = 0; nextNode < size; nextNode++ ){
	    if ( !adjMatrix[currentNode][nextNode] ) continue;
	    if ( !visited[nextNode] ){
		visited[nextNode] = true;
		dist[nextNode] = dist[currentNode] + 1;
		pi[nextNode] = currentNode;
		Q.push( nextNode );
	    }
	}
    }
}
// end_of_source

void inputGraph(){
    cin >> size;
    for ( int i = 0; i < size; i++ ){
	for ( int j = 0; j < size; j++ ){
	    adjMatrix[i][j] = 0;
	}
    }

    int source, target;
    for ( int i = 0; i < size; i++ ){
	for ( int j = 0; j < size; j++ ){
	    cin >> adjMatrix[i][j];
	}
    }
}

int main(){
    inputGraph();
    int source = 0;
    breadthFirstSearch(0);

    for ( int i = 0; i < size; i++ ) cout << i << " " << dist[i] << endl;
    return 0;
}

