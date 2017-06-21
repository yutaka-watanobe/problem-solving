#include<iostream>
using namespace std;

int main(){
    int n;
    while ( cin >> n && n ){
	if ( n % 2 != 0 || n <= 2 ){
	    cout << "Impossible" << endl; continue;
	}

	cout << n*3/2 << endl;
	for ( int i = 0; i < n; i++ ) cout << i+1 << " " << (i+1)%n+1 << endl;

	for ( int i = 1; i <= n/2; i++ ){
	    cout << i << " " << i + n/2 << endl;
	}
    }

    return 0;
}
