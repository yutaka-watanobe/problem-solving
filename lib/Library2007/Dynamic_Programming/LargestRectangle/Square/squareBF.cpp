#include<iostream>
using namespace std;

#define MAX 200
#define BLOCK '*'

int getLargestSquare(int size, char G[MAX][MAX]){
    int maxWidth = 0;
    for ( int i = 0; i < size; i++ ){
	for ( int j = 0; j < size; j++ ){
	    for ( int width = 1; width <= size - max(i, j); width++ ){
		bool isSquare = true;
		for ( int a = i; a < i + width; a++ ){
		    for ( int b = j; b < j + width; b++ ){
			if ( G[a][b] == BLOCK ) {
			    isSquare = false;
			    break;
			}
		    }
		    if ( !isSquare ) break;
		}
		if ( isSquare ) maxWidth = max( maxWidth, width );
		else break;
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


