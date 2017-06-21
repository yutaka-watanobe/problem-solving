#include<iostream>
using namespace std;

main(){
  int n = 1000;
  cout << n << endl;
  for ( int i = 0; i < n; i++ ){
    if ( i % 100 == 0 ){
      cout << i+1 << " " << 2 << " " << i+99 << " " << 1 << endl;
    } else if ( i % 100 == 99 ){
      cout << i-99 << " " << 1 << " " << i-1 << " " << 2 << endl;
    } else {
      cout << i+1 << " " << 2 << " " << i-1 << " " << 2 << endl;
    }
  }
  cout << 0 << endl;
}
