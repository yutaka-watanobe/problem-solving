#include<iostream>
#define MAX 100
#define MINE '*'
#define SPACE ' '

char field[ MAX + 2 ][ MAX + 2 ];
int row, column;

void searchMine( int i, int j ){
    int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int target_i, target_j;
    int sum = 0;
    for ( int direction = 0; direction < 8; direction++ ){
	target_i = i + dx[ direction ];
	target_j = j + dy[ direction ];
	if ( field[ target_i ][ target_j ] == MINE ) sum++;
    }
    field[i][j] = ( sum + '0' );
}

void compute(){
    for ( int i = 1; i <= row; i++ ){
	for ( int j = 1; j <= column; j++ ){
	    if ( field[i][j] == MINE ) continue;
	    searchMine( i, j );
	}
    }
}

bool input(){
    cin >> row >> column;
    if ( row == 0 && column == 0 ) return false;
    for ( int i = 1; i <= row; i++ ){
	for ( int j = 1; j <= column; j++ ){
	    cin >> field[i][j];
	}
    }
    return true;
}

void output(){
    for ( int i = 1; i <= row; i++ ){
	for ( int j = 1; j <= column; j++ ){
	    cout << field[i][j];
	}
	cout << endl;
    }
}

void setGuard(){
    for ( int i = 0; i < row + 2; i++ ) field[i][0] = field[i][column+1] = SPACE;
    for ( int j = 0; j < column + 2; j++ ) field[0][j] = field[row+1][j] = SPACE;
}

int main(){
    setGuard();

    for ( int tcase = 1; input(); tcase++ ){
	if ( tcase > 1 ) cout << endl;
	cout << "Field #" << tcase << ":" << endl;
	compute();
	output();
    }

    return 0;
}
