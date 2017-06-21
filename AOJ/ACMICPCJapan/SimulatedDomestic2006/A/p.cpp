#include<iostream>
#define SIZE 21
using namespace std;

int N, M;
bool G[SIZE][SIZE];

void compute(){
    int counter = 0;
    cin >> M;
    char direction;
    int step;

    int x = 10;
    int y = 10;
    int dx, dy;
    for ( int i = 0; i < M; i++ ){
	cin >> direction >> step;
	if ( direction == 'E' ) { dx = 1; dy = 0; }
	else if ( direction == 'N' ) { dx = 0; dy = 1; }
	else if ( direction == 'W' ) { dx = -1; dy = 0; }
	else if ( direction == 'S' ) { dx = 0; dy = -1; }
	for ( int s = 0; s < step; s++ ){
	    x += dx; y += dy;
	    if ( G[x][y] ){ counter++; G[x][y] = false;}
	}
    }
    
    cout << (( N == counter ) ? "Yes" : "No" ) << endl;
}

bool input(){
    cin >> N;
    if ( N == 0 ) return false;
    for ( int i = 0; i < SIZE; i++ )
	for ( int j = 0; j < SIZE; j++ ) G[i][j] = false;

    int x, y;
    for ( int i = 0; i < N; i++ ){
	cin >> x >> y;
	G[x][y] = true;
    }
    return true;
}

main(){
    while ( input() ) compute();
}
