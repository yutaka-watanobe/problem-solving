#include<iostream>
#include<algorithm>
using namespace std;

int gcd( int x, int y ){
    int r;
    if ( x < y ) swap( x, y ); 
    
    while ( y > 0 ){
        r = x % y;
        x = y;
        y = r;
    }

    return x;
}

int lcm( int x, int y ){
    return (x*y)/gcd(x, y);
}

int main(void){
    int x, y; 
    cin >> x >> y;
    cout << lcm( x, y) << endl;

    return 0;
}
