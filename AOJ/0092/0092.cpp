#include<iostream>
using namespace std;
#define MAX 1000
#define BLOCK '*'

int max(int a, int b ){
    if ( a > b ) return a;
    else return b;
}

int min(int a, int b ){
    if ( a < b ) return a;
    else return b;
}
    int n, W[MAX][MAX];
    char G[MAX][MAX];
main(){

    while ( cin >> n && n){
	for ( int i = 0; i < n; i++ ){
	    for ( int j = 0; j < n; j++ ) cin >> G[i][j];
	}
	
	for ( int i = 0; i < n; i++ ){
	    if ( G[0][i] == BLOCK ) W[0][i] = 0;
	    else W[0][i] = 1;
	    if ( G[i][0] == BLOCK ) W[i][0] = 0;
	    else W[i][0] = 1;
	}
	
	int maxWidth = 0;
	for ( int i = 1; i < n; i++ ){
	    for ( int j = 1; j < n; j++ ){
		if ( G[i][j] == BLOCK ) W[i][j] = 0;
		else {
		    W[i][j] = min(W[i-1][j-1], min(W[i-1][j], W[i][j-1])) + 1;
		    maxWidth = max( maxWidth, W[i][j] );
		}
	    }
	}
	cout << maxWidth << endl;
    }
}

