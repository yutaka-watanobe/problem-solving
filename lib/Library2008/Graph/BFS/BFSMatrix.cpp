#include<iostream>
#include<queue>
using namespace std;

#define MAX 1000
int size;
int adjMatrix[ MAX ][ MAX ]; // graph structure

void breadthFirstSearch(){
    queue< int > Q;
    bool visited[ MAX ];
    for ( int i = 0; i < size; i++ ) visited[ i ] = false;
    int currentNode = 0;    

    Q.push( currentNode );
    visited[ currentNode ] = true;

    while ( !Q.empty() ){
	currentNode = Q.front(), Q.pop();

	cout << currentNode << endl;

	for ( int nextNode = 0; nextNode < size; nextNode++ ){
	    if ( !adjMatrix[ currentNode ][ nextNode ] ) continue;
	    if ( !visited[ nextNode ] ){
		visited[ nextNode ] = true;
		Q.push( nextNode );
	    }
	}
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
    for ( int i = 0; i < size; i++ ){
	for ( int j = 0; j < size; j++ ){
	    cin >> adjMatrix[i][j];
	}
    }
}

int main(){
    inputGraph();
    breadthFirstSearch();

    return 0;
}
