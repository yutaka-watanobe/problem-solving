#include<iostream>
using namespace std;
#define MAX 100

double T[MAX+1][MAX+1];
int n, ntry;

double compute(){
    double M[MAX+1][MAX+1];
    for ( int i = 1; i <= n; i++ ) M[i][1] = 1.0;
    for ( int j = 2; j <= ntry; j++ ){
	for ( int i = 1; i <= n; i++ ){
	    M[i][j] = 0.0;
	    for ( int p = 1; p <= n; p++ ){
		M[i][j] = max( M[i][j], M[p][j-1]*T[p][i] );
	    }
	}
    }
    double maxv = 0.0;
    for ( int i = 1; i <= n; i++ ) maxv = max( maxv, M[i][ntry] );
    return maxv;
}

int main(){
    while( cin >> n >> ntry ){
	if ( ntry == 0 && n == 0 ) break;
	for ( int i = 1; i <= n; i++ )
	    for ( int j = 1; j <= n; j++ ) cin >> T[i][j];
	printf("%.2lf\n", compute());
    }
    return 0;
}
