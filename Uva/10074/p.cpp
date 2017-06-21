// @author yutaka
#include<iostream>
#include<set>

#define MAX 105
#define SPACE '0'
#define BLOCK '1'

class Point{
public:
  int x, y;
  Point();
  Point( int x, int y ): x(x), y(y){}
  bool operator < ( const Point &p ) const{
    if ( x == p.x ) return y < p.y;
    else return x < p.x;
  }
};

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
    }

    void compute(){
	makeTable();

	set<Point> table[ MAX ][ MAX ];
	set<Point>::iterator it;

	for ( int i = 1; i <= row; i++ ){
	    for ( int j = 1; j <= column; j++ ){
		if ( buffer[i][j] == BLOCK ) continue;
		
		if ( buffer[i][j-1] == BLOCK && buffer[i-1][j] == BLOCK ){
		    table[i][j].insert( Point(1, 1) );
		} 

		if ( buffer[i][j-1] == SPACE ){
		    for ( it = table[i][j-1].begin(); it != table[i][j-1].end(); it++ ){
			Point p = *it;
			table[i][j].insert( Point( p.x + 1, min(p.y, toTop[i][j] )));
		    }
		} 
		
		if ( buffer[i-1][j] == SPACE ){
		    for ( it = table[i-1][j].begin(); it != table[i-1][j].end(); it++ ){
			Point p = *it;
			table[i][j].insert( Point( min(p.x, toLeft[i][j] ), p.y + 1 ));
		    }
		}
	    }
	}

	int maxValue = 0;
	for ( int i = 1; i <= row; i++ ){
	    for ( int j =1; j <= column; j++ ){
	      for ( it = table[i][j].begin(); it != table[i][j].end(); it++ ){
		    Point p = *it;
		    maxValue = max(maxValue, p.x * p.y );
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
