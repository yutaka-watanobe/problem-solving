#include<iostream>
using namespace std;

int calcID(int r, int t) { return r + 5 * t; }

int main() {
  int n, r, t;
  cin >> n;
  for ( int i = 0; i < n; i++ ) {
    cin >> r >> t;
    bool onR = r % 100 == 0;
    bool onT = t % 30 == 0;
    r /= 100;
    t /= 30;
    if ( onR && onT ) cout << calcID(r, t) << endl;
    else if ( onR ) cout << calcID(r, t) << " " << calcID(r, t + 1) << endl;
    else if ( onT ) cout << calcID(r, t) << " " << calcID(r + 1, t) << endl;
    else cout << calcID(r, t) << " " << calcID(r + 1, t) << " "
              << calcID(r, t + 1) << " " << calcID(r + 1, t + 1) << endl;
  }

  return 0;
}
