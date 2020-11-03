#include<iostream>
#include<string>
using namespace std;

int main() {
  int w;
  cin >> w;

  string res;
  while ( w > 0 ) {
    int r = w % 3;
    if ( r == 0 ){
      res = '0' + res;
    } else if ( r == 1 ){
      res = '+' + res;
    } else if ( r == 2 ){
      res = '-' + res;
      ++w;
    }
    w /= 3;
  }
  cout << res << endl;
  return 0;
}
