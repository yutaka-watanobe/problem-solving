// DP
#include<iostream>
#include<algorithm>
using namespace std;

static const int NMAX = 75;
static const int KMAX = 5;
static const int INFTY = (-1)*(1<<21);
int N, k;
int G[NMAX][NMAX];

void compute(){
    int T[NMAX][NMAX][KMAX+1];
    for ( int i = 0; i < N; i++ ){
	for ( int j = 0; j < N; j++ ){
	    for ( int l = 0; l <= k; l++ ) T[i][j][l] = INFTY; 
	}
    }

    if ( G[0][0] < 0 ) T[0][0][1] = G[0][0];
    else T[0][0][0] = G[0][0];

    for ( int j = 1; j < N; j++ ){
	for( int l = 0; l <= k; l++ ){
	    if ( T[0][j-1][l] == INFTY ) continue;
	    if ( G[0][j] < 0 && l <= k-1 )
		T[0][j][l+1] = max( T[0][j][l+1], T[0][j-1][l] + G[0][j] );
	    else if ( G[0][j] >= 0 )
		T[0][j][l] = max( T[0][j][l], T[0][j-1][l] + G[0][j] );
	}
    }

    for ( int i = 1; i < N; i++ ){
	// down
	for ( int j = 0; j < N; j++ ){
	    for ( int l = 0; l <= k; l++ ){
		if ( T[i-1][j][l] == INFTY ) continue;
		if ( G[i][j] < 0 && l <= k-1)
		    T[i][j][l+1] = max( T[i][j][l+1], T[i-1][j][l] + G[i][j] );
		else if ( G[i][j] >= 0 )
		    T[i][j][l] = max( T[i][j][l], T[i-1][j][l] + G[i][j] );
	    }
	}
	int LT[NMAX][KMAX+1];
	int RT[NMAX][KMAX+1];
	for ( int j = 0; j < N; j++ ){
	    for ( int l = 0; l <= k; l++ ) {
		LT[j][l] = T[i][j][l];
		RT[j][l] = T[i][j][l];
	    }
	}
	// left
	for ( int j = 1; j < N; j++ ){
	    for( int l = 0; l <= k; l++ ){
		if ( LT[j-1][l] == INFTY ) continue;
		if ( G[i][j] < 0 && l <= k-1 )
		    LT[j][l+1] = max( LT[j][l+1], LT[j-1][l] + G[i][j] );
		else if ( G[i][j] >= 0 )
		    LT[j][l] = max( LT[j][l], LT[j-1][l] + G[i][j] );
	    }
	}
	// right
	for ( int j = N-2; j >= 0; j-- ){
	    for( int l = 0; l <= k; l++ ){
		if ( RT[j+1][l] == INFTY ) continue;
		if ( G[i][j] < 0 && l <= k-1 )
		    RT[j][l+1] = max( RT[j][l+1], RT[j+1][l] + G[i][j] );
		else if ( G[i][j] >= 0 )
		    RT[j][l] = max( RT[j][l], RT[j+1][l] + G[i][j] );
	    }
	}
	for ( int j = 0; j < N; j++ ){
	    for ( int l = 0; l <= k; l++ ) {
		T[i][j][l] = max( T[i][j][l], max( LT[j][l], RT[j][l] ));
	    }
	}
    }

    int maxv = INFTY;
    for ( int l = 0; l <= k; l++ ) maxv = max( maxv, T[N-1][N-1][l] );

    if ( maxv == INFTY ) cout << "impossible" << endl;
    else cout << maxv << endl;


}

main(){
    for ( int i = 1; ; i++ ){
	cin >> N >> k;
	if ( N == 0 && k == 0 ) break;
	cout << "Case " << i << ": ";
	for ( int i = 0; i < N; i++ ){
	    for ( int j = 0; j < N; j++ ) cin >> G[i][j];
	}
	compute();
    }
}
