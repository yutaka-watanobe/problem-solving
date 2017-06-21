#include<iostream>

using namespace std;

void gen( int n){
  cout << n << " ";
  for ( int i = 0; i < n; i++ ) {
    int k;
    k = rand()%20;
    k -= 5;
    k = max( 0, k );
    cout << k << " ";
  }
  cout << endl;
}

main(){
  for ( int i = 1; i < 100; i++ ){
    gen(200+i);
    gen(260+i);
    gen(233+i);
    gen(73+i);
    gen(87+i);
    gen(33+i);
    gen(11+i);
    gen(i);
  }

  cout << 0 << endl;
}
