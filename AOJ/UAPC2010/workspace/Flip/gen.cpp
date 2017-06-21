#include<iostream>
using namespace std;

main(){
  int n = 5;

  for ( int t = 0; t < 50; t++ ){
    cout << n << endl;
    for ( int i = 0; i < n; i++ ){
      for ( int j = 0; j < n; j++ ){
	cout << rand()%2 << " ";
      }
      cout << endl;
    }
  }

  cout << "0" << endl;
}
