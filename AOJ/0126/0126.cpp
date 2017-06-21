#include<iostream>
#include<cassert>

using namespace std;
#define N 9

int G[N][N];
bool C[N][N]; // check
int counter[N+1];

void reset(){
    for ( int i = 1; i <= 10; i++ ) counter[i] = 0;
}

void checkRow( int i ){
    reset();
    for ( int j = 0; j < N; j++ ){
	counter[G[i][j]]++;
    }
    for ( int j = 0; j < N; j++ ){
	if ( counter[G[i][j]] != 1 ) C[i][j] = false;
    }
}

void checkCol( int j ){
    reset();
    for ( int i = 0; i < N; i++ ){
	counter[G[i][j]]++;
    }
    for ( int i = 0; i < N; i++ ){
	if ( counter[G[i][j]] != 1 ) C[i][j] = false;
    }
}

void checkBox( int si, int sj ){
    reset();
    for ( int i = si; i < si+3; i++){
	for ( int j = sj; j < sj+3; j++){
	    counter[G[i][j]]++;
	}
    }
    for ( int i = si; i < si+3; i++){
	for ( int j = sj; j < sj+3; j++){
	    if ( counter[G[i][j]] != 1 ) C[i][j] = false;
	}
    }
}


void compute(){
    for ( int i = 0; i < N; i++ ){
	for ( int j = 0; j < N; j++ ) {
	    cin >> G[i][j];
	    assert( 1 <= G[i][j] && G[i][j] <= 9 );
	    C[i][j] = true;
	}
    }

    for ( int i = 0; i < N; i++ ) checkRow(i);
    for ( int j = 0; j < N; j++ ) checkCol(j);
    for ( int i = 0; i < N; i += 3 ){
	for ( int j = 0; j < N; j += 3 ){
	    checkBox(i, j);
	}
    }

    for ( int i = 0; i < N; i++ ){
	for ( int j = 0; j < N; j++ ){
	    if ( C[i][j] ) cout << " ";
	    else cout << "*";
	    cout << G[i][j];
	}
	cout << endl;
    }
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	if ( i ) cout << endl;
	compute();
    }
    return 0;
}
