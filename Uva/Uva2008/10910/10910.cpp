#include<iostream>
using namespace std;
#define MAX 80
typedef unsigned long long ullong;

ullong T[MAX+1][MAX+1];

void init(){
    for ( int i = 1; i <= MAX; i++ ) T[i][1] = 1;
    for ( int i = 1; i <= MAX; i++ ) T[1][i] = i;
    for ( int i = 2; i <= MAX; i++ ){
	for ( int j = 2; j <= MAX; j++ ){
	    T[i][j] = (T[i-1][j] + T[i][j-1]);
	}
    }
}

main(){
    init();
    ullong n, t, p;
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	cin >> n >> t >> p;
	ullong x = t - p*n;
	if ( x == 0 || n == 0 ) cout << 1 << endl;
	else cout << T[x][n] << endl;
    }
}
