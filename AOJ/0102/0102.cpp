#include<iostream>
using namespace std;
#define REP(i, n) for ( int i = 0; i < (int)n; i++ )
#define MAX 11

int main(){
    int n;
    int M[MAX][MAX];
    while( cin >> n && n ){
	REP(i, n) REP(j, n) cin >> M[i][j];
	REP(k, n) {M[n][k] = M[k][n] = 0;}
	M[n][n] = 0;



	REP(j, n) REP(i, n) M[n][j] += M[i][j];
	REP(i, n) REP(j, n) M[i][n] += M[i][j];
	REP(k, n) M[n][n] += M[k][n];

	REP(i, n+1){
	    REP(j, n+1){
		printf("%5d", M[i][j]);
	    }
	    cout << endl;
	}

    }
}
