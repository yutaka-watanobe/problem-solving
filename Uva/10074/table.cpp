#include<iostream>
#include<list>

#define MAX 100
#define SPACE '0'
#define BLOCK '1'

class RectangleSearch{
    public:
    char buffer[ MAX ][ MAX ];
    int row, column;

    void makeTable(){
	for ( int j = 0; j < column; j++ ){
	    int count = 0;
	    for ( int i = 0; i < row; i++ ){
		if ( buffer[i][j] == SPACE ) {table[i][j] = ++count; }
		else { table[i][j] = 0; count = 0; }
	    }
	}
    }

    void compute(){
	makeTable();
	
	
    }

    bool input(){
	cin >> row >> column;
	if ( row == 0 && column == 0 ) return false;
	for ( int i = 0; i < row; i++ ){
	    for ( int j = 0; j < column; j++ ){
		cin >> buffer[i][j];
	    }
	}
	return true;
    }

    
};

main(){
    RectangleSearch RS;
    while ( RS.input() ){
	RS.compute();
    }
}
