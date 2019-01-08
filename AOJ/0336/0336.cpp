#include<iostream>
using namespace std;

int main(){
  int H, R;
  cin >> H >> R;
  if ( H*(-1) == R ) cout << 0 << endl;
  else if ( H*(-1) > R ) cout << -1 << endl;
  else if ( H*(-1) < R ) cout << 1 << endl;

  return 0;
}

