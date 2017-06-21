#include<iostream>
using namespace std;
#define NMAX 100
#define KMAX 100

bool check( int S[KMAX], int k ){
    for ( int i = 0; i < k; i++ ){
	if ( S[i] < 0 ) return false;
    }
    return true;
}
main(){
    int n, k;
    int S[KMAX];
    while(1){
	cin >> n >> k;
	if ( n == 0 && k == 0 ) break;
	for ( int i = 0; i < k; i++ ) cin >> S[i];
	for ( int i = 0; i < n; i++ ){
	    for ( int j = 0; j < k; j++ ){
		int c; cin >> c;
		S[j] -= c;
	    }
	}
	
	if ( check(S,k) ) cout << "Yes" << endl;
	else cout << "No" << endl;
    }
}
