// begin_of_source
// @author yutaka C++
// N queens problem: 全ての可能な配置と総数を出力
#include<iostream>
using namespace std;

#define N 8
#define FREE -1
#define NOT_FREE 1

int row[N], col[N], dpos[2*N-1], dneg[2*N-1];
int counter;

void initialize(){
    for ( int i = 0; i < N; i++ ){ row[i] = FREE, col[i] = FREE; }
    for ( int i = 0; i < 2*N - 1; i++ ) { dpos[i] = FREE; dneg[i] = FREE; }
}

void printBoard(){
    for ( int i = 0; i < N; i++ ){
	for ( int j = 0; j < N; j++ ){
	    cout << (( row[i] == j ) ? "Q" : ".");
	}
	cout << endl;
    }
    cout << endl;
}

void recursive( int i ){
    if ( i == N ){ // SUCCESS
	counter++;
	printBoard(); return;
    }

    for ( int j = 0; j < N; j++ ){
	// if (i, j) is attacked by other queens, continue
	if ( col[j] == NOT_FREE || dpos[i+j] == NOT_FREE ||
	     dneg[i-j+N-1] == NOT_FREE ) continue;
	// put a queen on (i, j)
	row[i] = j; col[j] = dpos[i+j] = dneg[i-j+N-1] = NOT_FREE;
	// try next row
	recursive( i + 1 ); 
	// remove the queen from (i, j)
	row[i] = col[j] = dpos[i+j] = dneg[i-j+N-1] = FREE;
    }

    // FAIL
}

main(){
    initialize();
    counter = 0;
    recursive( 0 );
    cout << counter << endl;
}
// end_of_source
