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

int rec( int x, int y ){
  if ( y == 0 ) return x;
  return rec(y, x%y);
}

int main(void){
    int x, y; 
    cin >> x >> y;
    cout << gcd( x, y) << endl;
    cout << rec(x, y) << endl;
    return 0;
}
