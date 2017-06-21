#include<iostream>
#include<string>
#define MAX 100

using namespace std;

void print( int i ){
    cout << "P appears at " << i << endl;
}

// begin_of_source
void initNext( string P, int m, int N[]){
    int i, j;
    N[0] = -1;
    for ( i = 0, j = -1; i < m; i++, j++, N[i] = j )
	while( ( j >= 0 ) && ( P[i] != P[j] ) ) j = N[j];
}

int KMPSearch( string T, int n, string P, int m ){
    int N[MAX];
    initNext( P, m, N );

    int i, j;
    i = j = 0;

    while ( i < n ){
	while( i < n && j < m ){
	    if ( j == 0 ){ 
		if ( T[i] != P[j] ){ j = 0; i++; }
		else { i++; j++; }
	    } else {
	      if ( T[i] != P[j] ){ j = N[j]; }
		else { i++; j++; }
	    }
	}
	if ( j == m ) {
	    printf("P appers at %d\n", i - j); j = N[j];
	}
    }
}
// end_of_source

main(){
    string T, P;
    cin >> T >> P;
    KMPSearch( T, T.size(), P, P.size() );
}
