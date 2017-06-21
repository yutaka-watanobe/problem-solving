#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 255

int n;
char G[MAX+2][MAX+2];
int T[MAX+2][MAX+2][4];

void compute(){
    for ( int i = 0; i < n + 2; i++ ){
	for ( int j = 0; j < n + 2; j++ ){
	    for ( int k = 0; k < 4; k++ ) T[i][j][k] = 0;
	}
    }

    static const int di[4] = {-1, -1, -1, 0};
    static const int dj[4] = {1, 0, -1, -1};

    int maxv = 0;

    for ( int i = 0; i <= n; i++ ){
	for ( int j = 0; j <= n; j++ ){
	    if ( G[i][j] == '1' ){
		for ( int k = 0; k < 4; k++ ){
		    T[i][j][k] = T[i+di[k]][j+dj[k]][k] + 1;
		    maxv = max( maxv, T[i][j][k] );
		}
	    }
	}
    }

    cout << maxv << endl;
}

main(){
    while(cin >> n, n){
	for ( int i = 1; i <= n; i++ ){
	    for ( int j = 1; j <= n; j++ ) cin >> G[i][j];
	}
	compute();
    }
}