#include<iostream>
using namespace std;
#define MAX 100
typedef unsigned long long ullong;

ullong T[MAX+1][MAX+1];

void init(){
    for ( int i = 1; i <= MAX; i++ ) T[i][1] = 1;
    for ( int i = 1; i <= MAX; i++ ) T[1][i] = i;
    for ( int i = 2; i <= MAX; i++ ){
	for ( int j = 2; j <= MAX; j++ ){
	    T[i][j] = (T[i-1][j] + T[i][j-1])%1000000;
	}
    }
}

main(){
    init();
    int n, k;
    while( cin >> n >> k && n && k ) cout << T[n][k] << endl;
}
