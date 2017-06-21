#include<iostream>
using namespace std;

main(){
  int n = 100;
  cout << n << endl;
  for ( int y = 0; y < 10; y++ ){
    for ( int x = 0; x < 10; x++ ){
      cout << y*50 + 50 << " " << x*50 + 50 << " " << 10 << endl;
    }
  }
  cout << "250 250" << endl;
}
