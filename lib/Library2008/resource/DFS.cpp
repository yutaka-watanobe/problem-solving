// C++ @yutaka
// begin_of_library
#include<iostream>
using namespace std;
// end_of_library

// begin_of_user
#define SIZE 10
#define USER_VARIABLES // your variables
#define FORMULA_BODY1  // your formula
#define FORMULA_BODY2  // your formula
// end_of_user

// begin_of_function
// end_of_function

// begin_of_source
int adjMatrix[ SIZE ][ SIZE ]; // graph structure
bool visited[ SIZE ];

void dfs( int currentNode ){

    visited[ currentNode ] = true;

    for ( int nextNode = 0; nextNode < SIZE; nextNode++ ){
	if ( !adjMatrix[ currentNode ][ nextNode ] ) continue;
	if ( !visited[ nextNode ] ){
	    dfs( nextNode );
	}
    }
}

void depthFirstSearchScheme(){
    for ( int i = 0; i < SIZE; i++ ) visited[ i ] = false;
    int startNode = 0;

    dfs( startNode );
}

void inputGraph(){
    for ( int i = 0; i < SIZE; i++ ){
	for ( int j = 0; j < SIZE; j++ ){
	    adjMatrix[i][j] = 0;
	}
    }

    int  source, target;
    // input based on adjMatrix
    cout << "input adjMatrix : ";

    for ( int source = 0; source < SIZE; source++ ){
	for ( int target = 0; target < SIZE; target++ ){
	    cin >> adjMatrix[source][target];
	}
    }
}


int main(){
    inputGraph();
    depthFirstSearchScheme();

    return 0;
}

// end_of_source
