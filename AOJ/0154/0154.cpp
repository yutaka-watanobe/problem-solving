#include<iostream>
using namespace std;
#define MAX 7
#define VMAX 1000

int m, n, counter;
int value[MAX+1], amount[MAX+1];

int compute(){
    int T[MAX+1][VMAX+1];
    for ( int i = 0; i <= m; i++ )
	for ( int j = 0; j <= n; j++ ) T[i][j] = 0;
    for ( int j = 0; j <= n; j++ ) T[0][j] = 0;
    for ( int i = 0; i <= m; i++ ) T[i][0] = 1;

    for ( int i = 1; i <= m; i++ ){
      	for ( int j = 0; j <= n; j++ ) T[i][j] = T[i-1][j];
	for ( int j = 1; j <= n; j++ ){
	    for ( int a = 1; a <= amount[i]; a++ ){
		int k = j - a*value[i];
		if ( k >= 0 ) T[i][j] +=  T[i-1][k];
	    }
	}
    }

    int maxe = 0;
    for ( int i = 1; i <= m; i++ ) maxe = max(maxe, T[i][n]);
    return maxe;
}

int main(){
    while( cin >> m, m ){
	for ( int i = 0; i < m; i++ ){
	    cin >> value[i+1] >> amount[i+1];
	}
	int g; cin >> g;
	for ( int i = 0; i < g; i++ ){
	    cin >> n;
	    cout << compute() << endl;
	}
    }
    return 0;
}
