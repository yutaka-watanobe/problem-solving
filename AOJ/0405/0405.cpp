#include<iostream>
using namespace std;

main(){
  int N;
  cin >> N;
  if ('A' <= N && N <= 'Z' ) cout << 1 << endl;
  else if ( 'a' <= N && N <= 'z' ) cout << 2 << endl;
  else cout << 0 << endl;
}
