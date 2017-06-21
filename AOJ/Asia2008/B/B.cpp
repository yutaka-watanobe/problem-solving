#include<iostream>
using namespace std;
#define MMAX 1000
#define NMAX 21

int main(){

    int T[MMAX*NMAX][NMAX];
    int n, m, k;
    while( cin >> n >> m >> k && n){
	for ( int i = 0; i <= m*n; i++ )
	    for ( int j = 0; j <= n; j++ ) T[i][j] = 0;
	for ( int i = 1; i <= m; i++ ) T[i][1] = 1;
	
	for ( int i = 1; i <= m*n; i++ ){
	    for ( int j = 1; j <= n-1; j++ ){
		for ( int p = 1; p <= m; p++ ){
		    int t = i+p;
		    if ( t <= m*n ) T[t][j+1] += T[i][j];
		}
	    }
	}

	for ( int i = 1; i <= n*m; i++ ){
	  for ( int j = 1; j <= n; j++ ) {
	    printf("%5d", T[i][j]);
	  }
	  cout << endl;
	}

	    
	
	double expected = 0.0;
	int base = 1;
	for ( int i = 0; i < n; i++ ) base *= m;
	for ( int i = 1; i <= m*n; i++ ){
	    expected += 1.0*max(1, i-k)*T[i][n]/base;
	}
	printf("%.8lf\n", expected);
    }
}
