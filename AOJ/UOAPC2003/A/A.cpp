#include<iostream>
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

main(){
  int a, b;
  while(  cin >> a >> b ) cout << gcd(a, b) << endl;
}
