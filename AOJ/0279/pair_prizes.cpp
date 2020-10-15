#include<iostream>
using namespace std;

int main() {
  while ( 1 ) {
    int n; cin >> n;
    if ( n == 0 ) break;
    int less1Cnt = 0;
    int zeroCnt = 0;
    for ( int i = 0; i < n; ++i ) {
      int k; cin >> k;
      if ( k <= 1 ) ++less1Cnt;
      if ( k == 0 ) ++zeroCnt;
    }
    if ( n == less1Cnt ) cout << "NA" << endl;
    else cout << n - zeroCnt + 1 << endl;
  }

  return 0;
}
