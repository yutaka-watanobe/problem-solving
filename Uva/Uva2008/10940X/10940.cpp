#include<iostream>
using namespace std;

int compute( int n ){
    int  start, diff, shift, p;
    start = 1;
    shift = 0;
    p = 1;

    while(1){
	if ( n == 1 ) return start;
	if ( n % 2 == 0 ){
	    if ( shift == 0 ){
		n /= 2;
		shift = shift;
		start += p;
	    } else {
		n /= 2;
		shift = (shift+1)%2;
		start = start;
	    }
	} else {
	    if ( shift == 0 ){
		n /= 2;
		shift = (shift+1)%2;
		start += p;
	    } else {
		n = (n+1)/2;
		shift = (shift+1)%2;
		start = start;
	    }
	}
	p *= 2;
    }
}

main(){
    int n;
    while ( cin >> n && n ) cout << compute( n ) << endl;
}
