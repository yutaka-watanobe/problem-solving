#include<iostream>
#include<vector>
using namespace std;

const int MAX_CNT = 10000;

int main() {
  int N;
  while ( cin >> N && N != 0 ) {
    vector<int> b;
    for ( int i = 0; i < N; i++ ) {
      int v; cin >> v;
      b.push_back(v);
    }

    int cnt = 0;
    while ( cnt <= MAX_CNT ) {
      // 三角形になっているか判定する
      bool isTriangle = true; 
      if ( b[0] != 1 ) isTriangle = false;
      for ( int i = 1; i < b.size(); i++ ) {
        if ( b[i] != b[i - 1] + 1 ) {
          isTriangle = false;
          break;
        }
      }
      if ( isTriangle ) break;
      // ブロックの数が１より多い列で新しい列を作る
      vector<int> tmp; 
      for ( int num : b ) 
        if ( num > 1 ) tmp.push_back(num - 1);
      tmp.push_back(b.size());
      b = tmp;

      ++cnt;
    }

    if ( cnt > MAX_CNT ) cout << -1 << endl;
    else cout << cnt << endl;
  }

  return 0;
}
