#include<iostream>
using namespace std;

int getValue(int x){
    if ( x == 4 ) return 5;
    return (x < 4) ? x : x+2;
}

void convert( int n ){
    if ( n == 0 ) return;
    convert( n/8 );
    cout << getValue(n%8);
}

main(){
    int n;
    while( cin >> n && n ) { assert( n <=1000000000); convert(n); cout << endl; }
}

