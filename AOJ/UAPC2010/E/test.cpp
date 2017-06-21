#include<iostream>

using namespace std;

main(){
  cout << 2147483648LL%10007 << endl;
  cout << 4294967296LL%10007 << endl;
  cout << 8589934592LL%10007<< endl;

  int p = 1;
  for ( int i = 0; i < 10; i++ ){
    p = (p*99)%10007;
  }
  cout << p%10007 << endl;

}
