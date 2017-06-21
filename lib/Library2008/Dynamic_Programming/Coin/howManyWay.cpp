#include<iostream>
using namespace std;
#define KMAX 17
#define VMAX 300

static const int K[17] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289};
int T[KMAX][VMAX+1];

main(){
    for ( int j = 0; j <= VMAX; j++ ) T[0][j] = 1;
    for ( int i = 0; i < KMAX; i++ ) T[i][0] = 1;
    for ( int i = 1; i < KMAX; i++ ){
	for ( int j = 1; j < K[i]; j++ ) T[i][j] = T[i-1][j];
	for ( int j = K[i]; j <= VMAX; j++ ){
	    T[i][j] = T[i-1][j] + T[i][j-K[i]];
	}
    }
    int n;
    while( cin >> n && n ) cout << T[KMAX-1][n] << endl;
}
