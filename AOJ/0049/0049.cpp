#include<iostream>
#include<string>
using namespace std;

main(){
  int k;
  char kasu;
  string t;
  int A=0, B=0, AB=0, O=0;
  while( cin >> k >> kasu >> t ){
    if ( t == "A" ) A++;
    if ( t == "B" ) B++;
    if ( t == "AB" ) AB++;
    if ( t == "O" ) O++;
  }
  cout << A << endl;
  cout << B << endl;
  cout << AB << endl;
  cout << O << endl;
}
