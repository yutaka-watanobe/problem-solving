#include<stdio.h>
#include<iostream>
#include<stl.h>
#define MAX 105
#define BLOCK '.'
#define SPACE '?'

class LeastSquares{
    public:
    int row, column;
    char G[ MAX ][ MAX ];
    int current;
    
    char getMinChar( int x, int y ){
	char current = 'A';
	while ( 1 ){
	    if ( G[x-1][y] != current && G[x][y-1] != current && G[x][y+1] != current ) return current;
	    current++;
	}
    }
    
    void fillGrid( int x, int y ){
	char base = getMinChar(x, y);
	char next;
	
	int shift = 1;
	G[x][y] = base;
	
	while (1){
	    if ( G[x][y+shift] != SPACE ) return;
	    next = getMinChar(x, y + shift );
	    if ( next < base ) return;
	    
	    for ( int i = x; i <= x + shift; i++ ){
		if ( G[i][y+shift] != SPACE || G[i][y+shift+1] == base ) return;
	    }
	    if ( G[x-1][y+shift] == base ) return;
	    
	    for ( int j = y; j <= y + shift; j++ ){
		if ( G[x+shift][j] != SPACE || G[x+shift+1][j] == base ) return;
	    }
	    if ( G[x+shift][y-1] == base ) return;
	    
	    for ( int i = x; i <= x + shift; i++ ) G[i][y+shift] = base;
	    for ( int j = y; j <= y + shift; j++ ) G[x+shift][j] = base;
	    
	    shift++;
	}
    }
    
    void work(){
	for ( int i = 1; i <= row; i++ ){
	    for ( int j = 1; j <= column; j++ ){
		if ( G[i][j] == SPACE ){
		    fillGrid( i, j );
		}
	    }
	}
	print();
    }
    
    void print(){
	for ( int i = 1; i <= row; i++ ){
	    for ( int j = 1; j <= column; j++ ){
		printf("%c", G[i][j] );
	    }
	    printf("\n");
	}
	
    }
    
    bool read(){
	cin >> row >> column;
	if ( row == 0 && column == 0 ) return false;
	
	/* banpei */
	for ( int i = 0; i < row + 2; i++ ) G[i][0] = G[i][column+1] = BLOCK;
	for ( int j = 0; j < column + 2; j++ ) G[0][j] = G[row+1][j] = BLOCK;
	for ( int i = 1; i <= row; i++ ){
	    for ( int j = 1; j <= column; j++ ){
		cin >> G[i][j];
	    }
	}
	
	return true;
    }
};

main(){
    LeastSquares LS;
    for ( int i = 0; LS.read(); i++ ) {
	if ( i ) printf("\n");
	LS.work();
    }
}


