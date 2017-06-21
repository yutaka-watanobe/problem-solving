#include<iostream>
using namespace std;

void gen(int  n){
  cout << n << endl;
  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j  < n; j++ ){
      if ( j ) cout << " ";
      cout << rand()%2;
    }
    cout << endl;
  }
}
main(){
  for ( int i = 0; i < 100; i++ ){
    gen(3);
  }
  cout << 0 << endl;
}
