#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

main(){
  int n = 1000;
  int pre, x; cin >> pre;
  for ( int i = 1; i < 1000; i++ ){
    cin >> x;
    if ( pre > x ) cout << "error" << endl;
  }
}
