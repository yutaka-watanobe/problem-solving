#include<iostream>
#include<string>
#include<vector>

using namespace std;

int M, N;
vector<long> A, B;
vector<int> U;

int read(){
    cin >> M >> N;
    A.clear(); A.resize( M );
    U.clear(); U.resize( N );
    
    for ( int i = 0; i < M; i++ ) cin >> A[i];
    for ( int i = 0; i < N; i++ ) cin >> U[i];
}

void compute(){
    B.clear();
    int cursor = 0;
    int i = 0;
    
    for ( int a = 0; a < A.size(); a++ ){
	B.insert( lower_bound(B.begin(), B.end(), A[a]), A[a] );
	while( cursor < U.size() &&  U[cursor] == B.size() ){
	    i++;
	    cout << B[i-1] << endl;
	    cursor++;
	}
    }
}

main(){
    int t;
    cin >> t;
    for ( int i = 0; i < t; i++ ){
	if ( i ) cout << endl;
	read();
	compute();
    }
}

