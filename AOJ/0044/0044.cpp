#include<iostream>
using namespace std;

bool isPrime( int x ){
    if ( x == 2 ) return true;
    if ( x < 2 || x % 2 == 0 ) return false;
    for ( int i = 3; i < x; i += 2 ){
	if ( x % i == 0 ) return false;
    }
    return true;
}

main(){
    int n;
    while ( cin >> n ){
	for ( int i = n-1; ; i-- ) { 
	    if ( isPrime(i) ) { cout << i << " "; break; }
	}
	for ( int i = n+1; ; i++ ) { 
	    if ( isPrime(i) ) { cout << i << endl; break; }
	}
    }
}
