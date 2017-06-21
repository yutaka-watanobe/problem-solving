#include<iostream>
using namespace std;
#define MAX 100

main(){
    int n, m, T[MAX], H[MAX], sumT, sumH, exT, exH;
    while( cin >> n >> m  ){
	if ( n == 0 && m == 0 ) break;
	sumT = sumH = 0;
	for ( int i = 0; i < n; i++ ) { cin >> T[i]; sumT += T[i]; }
	for ( int j = 0; j < m; j++ ) { cin >> H[j]; sumH += H[j]; }
	exT = exH = MAX;
	for ( int i = 0; i < n; i++ ){
	    for ( int j = 0; j < m; j++ ){
		if ( sumT - T[i] + H[j] != sumH - H[j] + T[i] ) continue;
		if ( exT + exH > T[i] + H[j] ){
		    exT = T[i];
		    exH = H[j];
		}
	    }
	}
	if ( exT == MAX && exH == MAX ) cout << -1 << endl;
	else cout << exT << " " << exH << endl;
    }
}
