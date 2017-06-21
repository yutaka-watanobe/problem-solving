// begin_of_library
#include<iostream>
#include<queue>
using namespace std;
// end_of_library

// begin_of_user
#define SIZE 6
#define USER_VARIABLES // your variables
#define FORMULA_BODY1  // your formula
#define FORMULA_BODY2  // your formula
// end_of_user

// begin_of_function
// end_of_function

// begin_of_source
int adjMatrix[ SIZE ][ SIZE ]; // graph structure
bool visited[ SIZE ];
int currentNode;
queue< int > Q;

void breadthFirstSearchScheme(){
    for ( int i = 0; i < SIZE; i++ ) visited[ i ] = false;
    
    int startNode = 0;

    Q.push( startNode );
    visited[ startNode ] = true;

    while ( !Q.empty() ){
	currentNode = Q.front(), Q.pop();

	for ( int nextNode = 0; nextNode < SIZE; nextNode++ ){
	    if ( !adjMatrix[ currentNode ][ nextNode ] ) continue;
	    if ( !visited[ nextNode ] ){
		visited[ nextNode ] = true;
		Q.push( nextNode );
	    }
	}
    }
}

void inputGraph(){
    for ( int i = 0; i < SIZE; i++ ){
	for ( int j = 0; j < SIZE; j++ ){
	    adjMatrix[i][j] = 0;
	}
    }

    int  m, source, target;
    cout << "the size = " << SIZE << endl;
    cout << "input the number of edge : ";
    cin >> m;
    for ( int i = 0; i < m; i++ ){
	cin >> source >> target;
	adjMatrix[source][target] = true;
	adjMatrix[target][source] = true;
    }
}

int main(){
    inputGraph();
    breadthFirstSearchScheme();

    return 0;
}
// end_of_source
