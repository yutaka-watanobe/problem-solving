#include <iostream>
using namespace std;

int main() {
  int N; 
  cin >> N;

  int x, xmin = 2000, xmax = 0;
  for ( int i = 0; i < N; i++ ) {
    cin >> x;
    if ( x < xmin ) xmin = x;
    if ( x > xmax ) xmax = x;
  }

  cout << xmax - (xmin + xmax) / 2 << endl;
  return 0;
}
