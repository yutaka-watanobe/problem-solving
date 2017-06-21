// @JUDGE_ID:  17051CA  10564  C++
// @begin_of_source_code
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define MAX 21
#define SMAX 501
typedef long long llong;
#define INF "Z"

class Hourglass{
    private:
    int N, S;
    int T[ MAX * 2 ][ MAX ];
    string P[ MAX * 2 ][ MAX ][ SMAX ];
    llong C[ MAX * 2 ][ MAX ][ SMAX ];
    vector<string> path;
    
    public:

    void compute(){
	int left, right, down;
	int sum;
	string p;
	
	for ( int j = 0; j < N; j++ ){
	    C[0][j][ T[0][j] ] = 1;
	    P[0][j][ T[0][j] ] = ( j + '0');
	    P[0][j][ T[0][j] ] += ' ';
	}
	
	for ( int i = 0; i < N - 1; i++ ){
	    for ( int j = 0; j < N - i; j++ ){
		left = j - 1; right = j;
		down = i + 1;
		
		for ( int k = 0; k <= S; k++ ){
		    if ( C[i][j][k] == 0 ) continue;
		    if ( 0 <= left ){
			sum = k + T[down][left];
			p = P[i][j][k] + 'L';
			if ( sum <= S ){
			    C[down][left][sum] += C[i][j][k];
			    if ( P[down][left][sum] > p ) P[down][left][sum] = p;
			}
		    }
		    if ( right < N - down ){
			sum = k + T[down][right];
			p = P[i][j][k] + 'R';
			if ( sum <= S ) {
			    C[down][right][sum] += C[i][j][k];
			    if ( P[down][right][sum] > p  ) P[down][right][sum] = p;
			}
		    }
		}
	    }
	}
	
	for ( int i = N-1; i < 2*N - 2; i++ ){
	    for ( int j = 0; j <= i - N + 1; j++ ){
		left = j; right = j + 1; down = i + 1;
		
		for ( int k = 0; k <= S; k++ ){
		    if ( C[i][j][k] == 0 ) continue;
		    
		    sum = k + T[down][left];
		    p = P[i][j][k] + 'L';
		    if ( sum <= S ){
			C[down][left][sum] += C[i][j][k];
			if ( P[down][left][sum] > p ) P[down][left][sum] =  p;
		    }
		    
		    sum = k + T[down][right];
		    p = P[i][j][k] + 'R';
		    if ( sum <= S ) {
			C[down][right][sum] += C[i][j][k];
			if ( P[down][right][sum] > p ) P[down][right][sum] = p;
		    }
		}
	    }
	}
	
	llong cont = 0;
	for ( int j = 0; j < N; j++ ){
	    cont += C[2*N-2][j][S];
	}
	cout << cont << endl;
	
	path.clear();
	for ( int j = 0; j < N; j++ ){
	    if ( C[2*N-2][j][S] > 0 ) {
		path.push_back( P[2*N-2][j][S] );
	    }
	}
	
	if ( path.size() == 0 ) cout << endl;
	else {
	    sort( path.begin(), path.end() );
	    cout << path[0] << endl;
	}
    }
    
    bool input(){
	cin >> N >> S;
	if ( N == 0 && S == 0 ) return false;
	
	for ( int i = 0; i < N; i++ ){
	    for ( int j = 0; j < N - i; j++ ){
		cin >> T[i][j];
		init( i, j );
	    }
	}
	for ( int i = N; i < 2*N - 1; i++ ){
	    for ( int j = 0; j < i - N + 2; j++ ){
		cin >> T[i][j];
		init( i, j );
	    }
	}
	return true;
    }
    
    void init( int i, int j ){
	for ( int k = 0; k <= S; k++ ) {
	    P[i][j][k] = INF;
	    C[i][j][k] = 0;
	}
    }
};

main(){
    Hourglass H;
    while ( H.input() )	H.compute();
}

// @end_of_source_code


