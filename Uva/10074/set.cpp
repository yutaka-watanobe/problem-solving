// @author yutaka
// DP
#include<iostream>
#include<set>

#define MAX 105
#define SPACE '0'
#define BLOCK '1'

class RectangleSearch{
public:
    char buffer[ MAX + 2 ][ MAX + 2 ];
    int toTop[ MAX + 2 ][ MAX + 2 ];
    int toLeft[ MAX + 2 ][ MAX + 2 ];
    int row, column;

    void makeTable(){
	for ( int j = 1; j <= column; j++ ){
            int count = 0;
            for ( int i = 1; i <= row; i++ ){
                if ( buffer[i][j] == SPACE ) { toTop[i][j] = ++count; }
                else { toTop[i][j] = 0; count = 0; }
            }
        }
	for ( int i = 1; i <= row; i++ ){
            int count = 0;
	    for ( int j = 1; j <= column; j++ ){
                if ( buffer[i][j] == SPACE ) {toLeft[i][j] = ++count; }
                else { toLeft[i][j] = 0; count = 0; }
            }
        }
    }

    void compute(){
	makeTable();

	set<pair<int, int> > table[ MAX ][ MAX ];
	set<pair<int, int> >::iterator it;
	int p1, p2;

	int maxValue = 0;

	for ( int i = 1; i <= row; i++ ){
	    for ( int j = 1; j <= column; j++ ){
		if ( buffer[i][j] == BLOCK ) continue;
		
		if ( buffer[i][j-1] == BLOCK && buffer[i-1][j] == BLOCK ){
		    table[i][j].insert( make_pair(1, 1) );
		    maxValue = max( maxValue, 1 );
		} 

		if ( buffer[i][j-1] == SPACE ){
		    for ( it = table[i][j-1].begin(); it != table[i][j-1].end(); it++ ){
			pair<int, int> p = *it;
			p1 = p.first + 1;
			p2 = min(p.second, toTop[i][j] );
			table[i][j].insert( make_pair( p1, p2 ) );
			maxValue = max( maxValue, p1 * p2);
		    }
		} 
		
		if ( buffer[i-1][j] == SPACE ){
		    for ( it = table[i-1][j].begin(); it != table[i-1][j].end(); it++ ){
			pair<int, int> p = *it;
			p1 = min(p.first, toLeft[i][j]);
			p2 = p.second + 1;
			table[i][j].insert( make_pair( p1,p2 ) );
			maxValue = max( maxValue, p1 * p2);
		    }
		}
	    }
	}

	cout << maxValue << endl;
    }

    bool input(){
	cin >> row >> column;
	if ( row == 0 && column == 0 ) return false;
	for ( int i = 0; i < row + 2; i++ ) buffer[i][0] = buffer[i][column+1] = BLOCK;
	for ( int j = 0; j < column + 2; j++ ) buffer[0][j] = buffer[row+1][j] = BLOCK;
	for ( int i = 1; i <= row; i++ ){
	    for ( int j = 1; j <= column; j++ ){
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
