#include<iostream>
using namespace std;

bool isPrime( int x ){
    if ( x <= 1 ) return false;

    for ( int i = 2; i <= x - 1; i++ ){
	if ( x % i == 0 ) return false;
    }
    return true;
}

int main(void){
    int x;
    while ( cin >> x ){
	if ( isPrime( x ) ) cout << "yes" << endl;
	else cout << "no" << endl;
    }

    return 0;
}

