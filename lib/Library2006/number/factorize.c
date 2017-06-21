#include<iostream>

void factorize( int x ){
  int d, q;
  
  while ( x >= 4 && x % 2 == 0 ){
    cout << "2 * "; x /= 2;
  }

  d = 3; q = x / d;

  while ( q >= d ){
    if ( x % d == 0 ){
      cout << d << " * "; x = q;
    } else {
      d += 2;
    }

    q = x / d;
  }

  cout << x << endl;
}

main(){
  int n;
  while ( cin >> n ) factorize( n );
}
