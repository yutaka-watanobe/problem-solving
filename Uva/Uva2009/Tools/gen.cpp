#include<iostream>
using namespace std;

main(){
  int n; cin >> n;
  for ( int i = n; i < n+100; i++ ) {
    if ( i % 20 == 0 ) {
      cout << endl;
      cout << "Set #" << i/20 << endl;
    }
    cout << i << endl;
  }
}
