#include<iostream>
using namespace std;

#define MAX 10001

main(){
    int n, m, L[MAX], R[MAX], C[MAX*2], i, j, k;
    while( cin >> n >> m ){
	if ( n == 0 && m == 0 ) break;
	for ( i = 0; i < n; i++ ) cin >> L[i];
	for ( i = 0; i < m; i++ ) cin >> R[i];
	L[n] = R[m] = 1000001;
	i = j = k = 0;
	while( k < n + m ) {
	    C[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
	}
	int maxv = C[0];
	for ( int i = 1; i < n+m; i++ ){
	    if ( maxv < C[i] - C[i-1] ) maxv = C[i] - C[i-1];
	}
	cout << maxv << endl;
    }
}
