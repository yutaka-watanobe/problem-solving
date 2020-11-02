#include<iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int res = 0, row = 1, w = 0;
  while ( n >= row ) {
    if ( row * k >= w ) {
      ++res;
      w += row;
      n -= row;
    }
    else if ( n >= row + 1 ) ++row;
    else break;
  }
    
  cout << res << endl;
  return 0;
}
