#include<iostream>
#include<algorithm>
using namespace std;

#define NMAX 605
#define KMAX 305
static const int INFTY = (1<<21);

void reconstructPartition( int n, int k, int D[NMAX+1][KMAX+1], int S[NMAX+1] ){
    if ( k == 1 ){
	cout << "| ";
	for ( int i = 1; i <= n; i++ ) cout << S[i] << " ";
	cout << "| ";
    } else {
	reconstructPartition(D[n][k], k-1, D, S);
	for ( int i = D[n][k]+1; i <= n; i++ )cout << S[i] << " ";
	cout << "| ";
    }
}

// n >= k
void compute( int n, int k, int S[NMAX+1] ){
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

    cout << M[n][k] << endl;
}

int main(){
    int n, k, S[NMAX+1];
    while (cin >> n >> k ){
	for ( int i = 1; i <= n+1; i++ ) cin >> S[i];
	compute(n+1, k+1, S);
    }

    return 0;
}
