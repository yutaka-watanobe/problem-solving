#include<iostream>
using namespace std;

void gen(int n ){
  cout << n << " " << n*(n-1)/2 << " " << n-2 << endl;
  for ( int i = 0; i < n; i++ ){
    for ( int j = i+1; j < n; j++ ){
      cout << i << " " << j << " " << j-i << endl;
    }
  }
  for ( int i = 1; i <= n-2; i++ ){
    cout << i << endl;
  }
}

main(){
  gen(4);
  gen(5);
  gen(6);
  gen(7);
  gen(99);
  gen(100);
  cout << "0 0 0" << endl;
}
