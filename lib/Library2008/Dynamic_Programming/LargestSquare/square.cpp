#include<iostream>
using namespace std;

#define MAX 200
#define BLOCK '*'

int getLargestSquare( int size, char G[MAX][MAX]){
    int W[MAX][MAX];
    
    for ( int i = 0; i < size; i++ ) {
	W[0][i] = (G[0][i] == BLOCK) ? 0 : 1;
	W[i][0] = (G[i][0] == BLOCK) ? 0 : 1;
    }

    int maxWidth = 0;
    for ( int i = 1; i < size; i++ ){
	for ( int j = 1; j < size; j++ ){
	    if ( G[i][j] == BLOCK ) {
		W[i][j] = 0;
	    } else {
		W[i][j] = min(W[i-1][j-1], min(W[i-1][j], W[i][j-1])) + 1;
		maxWidth = max( maxWidth, W[i][j] );
	    }
	}
    }
    
    return maxWidth;
}

int main(void){
    int size;
    char G[MAX][MAX];
    
    cin >> size;
    for ( int i = 0; i < size; i++ ){
	for ( int j = 0; j < size; j++ ) cin >> G[i][j];
    }

    cout << getLargestSquare(size, G) << endl;

    return 0;
}
