#include<iostream>

using namespace std;
typedef unsigned long long ullong;

int n, it;
ullong s;

ullong power( ullong b, int t ){
    int v = 1;
    for ( int i = 0; i < t; i++ ) v *= b;
    return v;
}

void compute(){
    n = 4;
    it = 10;
    cin >> s;

    for ( int i = 0; i < it; i++ ){
	s = s*s;
	s = s % ( power( 10, n + n/2) );
	s = s / ( power( 10, n/2) );
	cout << s << endl;
    }
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) {
	cout << "Case " << i+1 << ":" << endl;
	compute();
    }
}
