#include<iostream>
using namespace std;
#define REP(i, n) for ( int i = 0; i < n; i++ )
#define MAX 3

int G[MAX*MAX][MAX*MAX], n;

bool row[MAX*MAX][10], col[MAX*MAX][10], cell[MAX][MAX][10];

bool recursive( int pos ){
    if ( pos >= n*n*n*n ) return true;

    int i = pos/(n*n);
    int j = pos%(n*n);

    if ( G[i][j] != 0 ) {
	if ( recursive(pos+1) ) return true;
    } else {
	for ( int k = 1; k <= 9; k++ ){
	    if ( row[i][k] || col[j][k] || cell[i/n][j/n][k] ) continue;
	    row[i][k] = col[j][k] = cell[i/n][j/n][k] = true;
	    G[i][j] = k;
	    if ( recursive(pos+1) ) return true;
	    G[i][j] = 0;
	    row[i][k] = col[j][k] = cell[i/n][j/n][k] = false;
	}
    }

    return false;
}

void compute(){
    REP(i, n*n) REP(k, 10) row[i][k] = false;
    REP(i, n*n) REP(k, 10) col[i][k] = false;
    REP(i, n) REP(j, n) REP(k, 10) cell[i][j][k] = false;

    REP(i, n*n) REP(j, n*n){
	if ( G[i][j] == 0 ) continue;
	row[i][G[i][j]] = true;
	col[j][G[i][j]] = true;
	cell[i/n][j/n][G[i][j]] = true;
    }

    if ( recursive(0) ){
	REP(i, n*n) {
	    REP(j, n*n){
		if (j) cout << " ";
		cout << G[i][j];
	    }
	    cout << endl;
	}
    } else {
	cout << "NO SOLUTION" << endl;
    }
}

int main(){
    for ( int t = 0; cin >> n; t++ ){
	if ( t ) cout << endl;
	REP(i, n*n) REP(j, n*n) cin >> G[i][j];
	compute();
    }
    return 0;
}
