// @author yutaka
// DP
#include<iostream>
#include<vector>
#include<algorithm>

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

	vector<pair<int, int> > table[ MAX ][ MAX ];
	vector<pair<int, int> >::iterator it;
	int p1, p2;

	int maxValue = 0;

	for ( int i = 1; i <= row; i++ ){
	    for ( int j = 1; j <= column; j++ ){
		if ( buffer[i][j] == BLOCK ) continue;
		
		if ( buffer[i][j-1] == BLOCK && buffer[i-1][j] == BLOCK ){
		    table[i][j].push_back( make_pair(1, 1) );
		    maxValue = max( maxValue, 1 );
		} 

		if ( buffer[i][j-1] == SPACE ){
		    for ( int v = 0; v < table[i][j-1].size(); v++ ){
			pair<int, int> p = table[i][j-1][v];
			p1 = p.first + 1;
			p2 = min(p.second, toTop[i][j] );
			maxValue = max( maxValue, p1 * p2);

			it = lower_bound( table[i][j].begin(), table[i][j].end(), p );
			if ( it == table[i][j].end() ){
			     table[i][j].push_back( make_pair( p1, p2 ) );
			} else if ( !( (*it).first >= p1 && (*it).second >= p2 ) ){
			     table[i][j].insert( it, make_pair( p1, p2 ) );
			}

		    }
		} 


		if ( buffer[i-1][j] == SPACE ){
		    for ( int v = 0; v < table[i-1][j].size(); v++ ){
			pair<int, int> p = table[i-1][j][v];
			p2 = p.second + 1;
			p1 = min(p.first, toLeft[i][j] );
			maxValue = max( maxValue, p1 * p2);

			it = lower_bound( table[i][j].begin(), table[i][j].end(), p );
			if ( it == table[i][j].end() ){
			     table[i][j].push_back( make_pair( p1, p2 ) );
			} else if ( !( (*it).first >= p1 && (*it).second >= p2 ) ){
			     table[i][j].insert( it, make_pair( p1, p2 ) );
			}

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
