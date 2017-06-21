#include<iostream>
using namespace std;

main(){
  for ( int i = 1; i <= 50; i++ ){
    cout << 49 << endl;
    bool isf = true;
    for ( int j = 1; j <= 50; j++ ){
      if ( j == i ) continue;
      if (!isf ) cout << " ";
      cout << j;
      isf = false;
    }
    cout << endl;
  }
  cout << 0 << endl;
}
