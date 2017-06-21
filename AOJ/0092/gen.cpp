#include<iostream>
using namespace std;

void gen(int n){
  cout << n << endl;
  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < n; j++ ){
      cout << '.';
    }
    cout << endl;
  }
}

main(){
  gen(1000);
  gen(1000);
  gen(1000);
  gen(1000);
  cout << 0 << endl;
}
