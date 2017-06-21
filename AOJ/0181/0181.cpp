#include<iostream>
#include<algorithm>
using namespace std;

#define NMAX 100
#define KMAX 100
static const int INFTY = (1<<21);

// n >= k
int compute( int n, int k, int S[NMAX+1] ){
    
    int M[NMAX+1][KMAX+1], D[NMAX+1][KMAX+1];
    int P[NMAX+1];
    
    P[0] = 0;
    for ( int i = 1; i <= n; i++ ) P[i] = P[i-1] + S[i];
    
    for ( int i = 1; i <= n; i++ ) M[i][1] = P[i];
    for ( int j = 1; j <= k; j++ ) M[1][j] = S[1];
    
    for ( int i = 2; i <= n; i++ ){
	for ( int j = 2; j <= k; j++ ){
	    M[i][j] = INFTY;
	    for ( int x = 1; x <= i-1; x++ ){
		int maximum = max( M[x][j-1], P[i] - P[x] );
		if ( M[i][j] > maximum ){
		    M[i][j] = maximum;
		    D[i][j] = x;
		}
	    }
	}
    }

    return M[n][k];
}

int main(){
    int n, k, S[NMAX+1];
    while(1){
	cin >> k >> n;
	if ( k == 0 && n == 0 ) break;
	for ( int i = 1; i <= n; i++ ) cin >> S[i];
	cout << compute(n, k, S) << endl;
    }
    return 0;
}
