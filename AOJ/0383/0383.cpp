#include <iostream>
using namespace std;

int main() {
  int A, B, X;
  cin >> A >> B >> X;

  if ( X % 500 != 0 ) X += 500 - X % 500;

  int a = 0, b = 0;
  if ( A < B ) {
    a = X / 1000 + ((X % 1000 > 0) ? 1 : 0);
  } else if ( A > 2 * B ){
    b = X / 500;
  } else {
    a = X / 1000; X %= 1000;
    b = X / 500;
  }

  cout << A * a + B * b << endl;
  return 0;
}

