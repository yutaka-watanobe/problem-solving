#include<iostream>
using namespace std;

main(){
    int tcase; cin >> tcase;
    int n, m;
    for ( int i = 0; i < tcase; i++ ){
	cin >> n >> m;
	if ( n == m ){
	    n = (n+1)/2;
	    cout << n*(n+1)/2 << endl;
	} else {
	    cout << ((n+1)/2)*((m+1)/2) << endl;
	}
    }
}