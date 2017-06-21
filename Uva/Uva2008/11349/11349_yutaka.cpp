#include<iostream>
using namespace std;
#define MAX 1000
long long M[MAX*MAX];

bool check( int n ){
    for ( int i = 0; i < n*n; i++ ) cin >> M[i];
    for ( int i = 0; i <= n*n/2; i++ ){
	if ( M[i] != M[n*n-i-1] || M[i] < 0 ) return false;
    }
    return true;
}

main(){
    int tcase, n; cin >> tcase;
    char ch;

    for ( int i = 1; i <= tcase; i++ ){
	cin >> ch >> ch >> n;
	cout << "Test #" << i << ": ";
	cout << (( check(n) ) ? "Symmetric." : "Non-symmetric.") << endl;
    }
}
