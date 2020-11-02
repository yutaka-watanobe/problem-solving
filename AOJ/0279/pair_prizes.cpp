#include<iostream>
using namespace std;

int main() {
  while ( 1 ) { // 無限ループ
    int N; cin >> N;
    if ( N == 0 ) break; // データセットの終わり
    int less1Cnt = 0;
    int zeroCnt = 0;
    for ( int i = 0; i < N; ++i ) {
      int k; cin >> k;
      if ( k <= 1 ) ++less1Cnt;
      if ( k == 0 ) ++zeroCnt;
    }
    if ( N == less1Cnt ) cout << "NA" << endl;
    else cout << N - zeroCnt + 1 << endl;
  }

  return 0;
}
