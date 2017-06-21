// for AA 2006 ex06
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#define MAX 101
#define INFTY 99999
using namespace std;

// begin_of_source
int N;
int A[MAX][MAX];

void floyd(){
    for ( int k = 0; k < N; k++ ){
	for ( int i = 0; i < N; i++ ){
	    for ( int j = 0; j < N; j++ ){
		//A[i][j] = min( A[i][j], A[i][k] + A[k][j] );
		A[i][j] = A[i][j] | A[i][k] & A[k][j];
	    }
	}
    }
}
// end_of_source

main(){
    cin >> N;
    string x;
    for ( int i = 0; i < N; i++ ){
	for ( int j = 0; j < N; j++ ){
	    cin >> x;
	    if ( x == "M" )
		A[i][j] = INFTY;
	    else
		A[i][j] = atoi(x.c_str());
	}
    }
    for ( int i = 0; i < N; i++ ) A[i][i] = 0;
    
        floyd();

    for ( int i = 0; i < N; i++ ){
	for ( int j = 0; j < N; j++ ) {
	    if ( A[i][j] == INFTY ) cout << "  M";
	    else printf("%3d", A[i][j]);
	}
	cout << endl;
    }
}

