#include<iostream>
#include<string>

using namespace std;

void print( int i ){
    cout << "P appears at " << i << endl;
}

// begin_of_source
int bruteForceSearch( string T, int n, string P, int m ){
    int i, j;
    i = j = 0;
    while ( i <= n - m ){
	while( i < n && j < m ){
	    if ( T[i] != P[j] ){
		i = i - j + 1; j = 0;
	    } else { i++; j++; }
	}
	if ( j == m ) {
	    print( i - j );
	    i = i - j + 1; j = 0;
	}
    }
}
// end_of_source

main(){
    string T, P;
    cin >> T >> P;
    bruteForceSearch( T, T.size(), P, P.size() );
}
