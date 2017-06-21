#include<iostream>
#include<vector>
using namespace std;
#define PMAX 187
#define NMAX 1120
#define KMAX 14

int T[PMAX+1][NMAX+1][KMAX+1];

void eratos ( int n, vector<int> &p){
    bool prime[NMAX+1];
    for ( int i = 0; i <= n; i++ ) prime[i] = false;
    for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
    prime[2] = true;
    for ( int i = 3; i*i <= n; i += 2 ){
	if ( !prime[i] ) continue;
	for ( int j = i + i; j <= n; j += i ) prime[j] = false;
    }
    for ( int i = 0; i <= n; i++ ) if ( prime[i] ) p.push_back(i);
}

void initialize(){
    vector<int> primes;
    eratos( NMAX, primes );

    for ( int i = 0; i < PMAX; i++ ){
	for ( int j = 0; j <= NMAX; j++ ){
	    for ( int k = 0; k <= KMAX; k++ ) T[i][j][k] = 0;
	    if ( j == primes[i] ) T[i][j][1] = 1;
	}
    }

    for ( int i = 1; i < PMAX; i++ ){
	for ( int j = 0; j <= NMAX; j++ ){
	    for ( int k = 1; k <= KMAX; k++ ){
		T[i][j][k] += T[i-1][j][k];
		if ( j - primes[i] >= 0 ) {
		    T[i][j][k] += T[i-1][j-primes[i]][k-1];
		}
	    }
	}
    }
}

main(){
    initialize();
    int n, k;
    while( cin >> n >> k, (n || k) ) cout << T[PMAX-1][n][k] << endl;
}