#include<iostream>
using namespace std;

main(){
  int x = 45;
  int b1 = 1 << 0;
  int b2 = b1 << 1;
  int b3 = b2 << 1;
  int b4 = b3 << 1;
  int b5 = b4 << 1;
  int b6 = b5 << 1;
  cout << (x & b1) << endl;
  cout << (x & b2) << endl;
  cout << (x & b3) << endl;
  cout << (x & b4) << endl;
  cout << (x & b5) << endl;
  cout << (x & b6) << endl;

  cout << b1 << " " << (x - b1) << endl;
  cout << b2 << " " << (x - b2) << endl;
  cout << b3 << " " << (x - b3) << endl;
  cout << b4 << " " << (x - b4) << endl;
  cout << b5 << " " << (x - b5) << endl;
  cout << b6 << " " << (x - b6) << endl;


}
