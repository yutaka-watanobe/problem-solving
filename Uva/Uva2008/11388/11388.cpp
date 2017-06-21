#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ullong;

ullong gcd( ullong x, ullong y ){
    int r;
    if ( x < y ) swap( x, y );
    
    while ( y > 0 ){
	r = x % y;
	x = y;
	y = r;
    }
    return x;
}

ullong lcm( ullong x, ullong y ){
    return x*y/gcd(x, y);
}

void compute(){
    int G, L;
    cin >> G >> L;
    ullong N = G*L;
    for ( ullong a = 1; a*a <= N; a++ ){
	if ( N % a != 0 ) continue;
	ullong b = N / a;
	if ( G == gcd( a, b ) && L == lcm( a, b ) ){
	    cout << a << " " << b << endl;
	    return;
	}
    }
    cout << -1 << endl;

}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	compute();
    }
}
