#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int q, n;

void compute(){
  int dx, dy;
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;

  dx = abs( c1 - c2 );
  dy = abs( r1 - r2 );

  if ( (dx + dy) % 2 != 0 ) {
    cout << "no move" << endl;
    return;
  }

  if ( r1 == r2 && c1 == c2 ){
    cout << "0" << endl;
    return;
  }

  if ( dx == dy ){
    cout << "1" << endl;
  } else {
    cout << "2" << endl;
  }

  

}

void work(){
  cin >> q >> n;

  for ( int i = 0; i < q; i++ ){
    compute();
  }

}


main(){
  int tcase;

  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    work();
  }
}
