#include <iostream>
using namespace std;

int main() {
  int N, ans = 1;
  cin >> N;

  while ( ans <= N ) {
    ans *= 2;
  }

  cout << ans / 2 << endl;
  return 0;
}
