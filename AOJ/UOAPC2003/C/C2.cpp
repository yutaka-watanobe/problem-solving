#include<iostream>
using namespace std;

main(){
  int T[50];
  T[1] = 1;
  T[2] = 2;

  int p = 3;
  for ( int i = 3; i < 50; i+=2 ){
    T[i] = T[i-1] + p;
    T[i+1] = T[i] + p;
    p*=3;
  }

  int n;
  while( cin >> n ) cout << T[n] << endl;
}
