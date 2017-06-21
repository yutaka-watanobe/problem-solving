#include<iostream>
#include<vector>

#define MAX 100
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
                if ( buffer[i][j] == SPACE ) {toTop[i][j] = ++count; }
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
	
	/*
	cout << "toTop" << endl;
	for ( int i = 1; i <= row; i++ ){
	    for ( int j = 1; j <= column; j++ ){
		cout << toTop[i][j];
            }
	    cout << endl;
        }
	cout << "toLeft" << endl;
	for ( int i = 1; i <= row; i++ ){
	    for ( int j = 1; j <= column; j++ ){
		cout << toLeft[i][j];
            }
	    cout << endl;
        }
	cout << endl;
	*/
    }

    void compute(){
	makeTable();
	vector<pair<int, int> > table[ MAX ][ MAX ];

	for ( int i = 1; i <= row; i++ ){
	    for ( int j = 1; j <= column; j++ ){
		if ( buffer[i][j] == BLOCK ) continue;
		//table[i][j].clear();
		
		if ( buffer[i][j-1] == BLOCK && buffer[i-1][j] == BLOCK ){
		    table[i][j].push_back( make_pair(1, 1) );
		} 

		if ( buffer[i][j-1] == SPACE ){
		    for ( int v = 0; v < table[i][j-1].size(); v++ ){
			pair<int, int> p = table[i][j-1][v];
			table[i][j].push_back( make_pair( p.first + 1, min(p.second, toTop[i][j] )));
		    }
		} 
		
		if ( buffer[i-1][j] == SPACE ){
		    for ( int v = 0; v < table[i-1][j].size(); v++ ){
			pair<int, int> p = table[i-1][j][v];
			table[i][j].push_back( make_pair( min(p.first, toLeft[i][j] ), p.second + 1 ));
		    }
		}
	    }
	}

	int maxValue = 0;
	for ( int i = 1; i <= row; i++ ){
	    for ( int j =1; j <= column; j++ ){
		for ( int v = 0; v < table[i][j].size(); v++ ){
		    pair<int, int> p = table[i][j][v];
		    maxValue = max(maxValue, p.first * p.second );
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
