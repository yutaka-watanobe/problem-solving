#include<iostream>
#include<cassert>
using namespace std;

main(){
  int n, T[10], x;
  while(1){
    cin >> n;
    if ( n == 0 ) break;
    assert(1 <= n && n <= 10000);
    for ( int i = 0; i < 10; i++ ) T[i] = 0;
    for ( int i = 0; i < n; i++ ){ 
      cin >> x; T[x]++;
    }
    for ( int i = 0; i < 10; i++ ){
      if (T[i] == 0 ) cout << "-" << endl;
      else {
	for ( int j = 0; j < T[i]; j++ ) cout << "*";
	cout << endl;
      }
    }
  }
}
