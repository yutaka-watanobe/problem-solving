// @author Yutaka Watanobe
// Dynamic Programming
#include<iostream>
#include<stdio.h>
#include<algorithm>

#define MAX 105

class RectangleSearch{
    public:
    int row, column;
    int buffer[ MAX ][ MAX ], table[ MAX ][ MAX ];

    bool input(){
	scanf("%d %d", &row, &column );
	if( row == 0 && column == 0 ) return false;
	for ( int i = 0; i < row; i++ ){
	    for ( int j = 0; j < column; j++ ){
		scanf("%d", &buffer[i][j]);
	    }
	}
	return true;
    }
    
    void makeTable(){
	for ( int i = 0; i < row; i++ ){
	    int count = 0;
	    for ( int j = 0; j < column; j++ ){
		if ( buffer[i][j] == 0 ) { table[i][j] = ++count; }
		else { table[i][j] = 0; count = 0; }
	    }
	}
    }

    void compute(){
	makeTable();
	int maxValue = 0;

	for ( int j = 0; j < column; j++ ){
	    for ( int i = 0; i < row; i++ ){
		int cnt = 0;
		int val = table[i][j];      

		for ( int start = i; start < row; start++ ){
		    val = min( val, table[start][j] );
		    if( val == 0 ) break;
		    cnt++;
		    maxValue = max ( maxValue, cnt * val );
		}
	    }
	}

	cout << maxValue << endl;
    }
};

main(){
    RectangleSearch RS;
    while ( RS.input() ){
	RS.compute();
    }
}
// @end_of_source_code
