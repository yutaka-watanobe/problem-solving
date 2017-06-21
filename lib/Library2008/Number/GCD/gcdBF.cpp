#include<iostream>
#include<algorithm>
using namespace std;

int gcd( int x, int y ){
    int n;
    n = min( x, y ); 

    for ( int d = n; d >= 1; d-- ){
        if ( x % d == 0 && y % d == 0 ) return d;
    }
}

int main(void ){
    int x, y; 
    cin >> x >> y;
    cout << gcd( x, y) << endl;

    return 0;
}
