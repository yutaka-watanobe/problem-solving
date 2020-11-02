#include <iostream>
using namespace std;

int main() {
  int N, p = 0;
  cin >> N;

  while ( N > 1 ) {
    N >>= 1;
    ++p;
  }

  cout << (1 << p) << endl;
  return 0;
}
