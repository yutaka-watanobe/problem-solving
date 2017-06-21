// compute GCD
#include<iostream>
#include<algorithm>
using namespace std;

int gcd( int x, int y ){
    int r;
    if ( x < y ) swap( x, y );

    while( y > 0 ){
	r = x % y;
	x = y;
	y = r;
    }
    return x;
}

int main(){
    int N;
    while ( cin >> N, N ){
	int G = 0;
	for ( int i = 1; i < N; i++ ){
	    for ( int j = i+1; j <= N; j++ ){
		G += gcd(i, j);
	    }
	}
	cout << G << endl;
    }
    
    return 0;
}
