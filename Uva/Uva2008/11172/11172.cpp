#include<iostream>
using namespace std;

main(){
  int tcase; cin >> tcase;
  int a, b;
  for ( int i = 0; i < tcase; i++ ){
    cin >> a >> b;
    if ( a == b ) cout << "=" << endl;
    else if ( a < b ) cout << "<" << endl;
    else cout << ">" << endl;
  }
}
