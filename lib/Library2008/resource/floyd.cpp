// 423
#include<iostream>
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
		if ( i == k || j == k ) continue;
		A[i][j] = min( A[i][j], A[i][k] + A[k][j] );
	    }
	}
    }
}
// end_of_source

main(){
    cin >> N;
    string x;
    for ( int i = 1; i < N; i++ ){
	for ( int j = 0; j < i; j++ ){
	    cin >> x;
	    if ( x == "x" )
		A[i][j] = A[j][i] = INFTY;
	    else
		A[i][j] = A[j][i] = atoi(x.c_str());
	}
    }
    for ( int i = 0; i < N; i++ ) A[i][i] = 0;
    
    floyd();

    int maxvalue = 0;
    for ( int j = 0; j < N; j++ ){
	if ( A[0][j] != INT_MAX && maxvalue < A[0][j] ) maxvalue = A[0][j];
    }
    cout << maxvalue << endl;
}

