#include<iostream>
using namespace std;

main(){
    int n, k;
    int T[30];
    while( cin >>k && k ){
	for ( int i = 0; i < k; i++ ) cin >> T[i];
	n = 32;
	int r = 0;
	while( n ){
	    n -= (n-1)%5;
	    cout << n << endl;
	    if ( n == 0 ) break;
	    n -= min(n, T[r%k]);
	    r++;
	    cout << n << endl;
	}
    }
}
