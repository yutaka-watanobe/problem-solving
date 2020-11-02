#include <iostream>
#include <string>
using namespace std;

int main() {
  int L, N;
  string snake;
  cin >> L >> N >> snake;

  long long oocnt = 0;
  for ( int i = 0; i < L - 1; i++ ) {
    if ( snake.substr(i, 2) == "oo" )
      ++oocnt;
  }

  long long total = 0;
  for ( int i = 0; i < N; i++ ) {
    total += oocnt;
    oocnt *= 2;
  }

  cout << 3 * total + L << endl;
  return 0;
}
