#include<iostream>
using namespace std;

int main(){
  int N, r[1000]; // N 個の円盤の半径を記録できる配列
  cin >> N;
  for ( int i = 0; i < N; i++ ) cin >> r[i];
  int maxr = 0, cnt = 0;
  for ( int i = N - 1; i >= 0; i-- ){
    if ( r[i] > maxr ) {
      cnt++;
      maxr = r[i];
    }
  }
  cout << cnt << endl;
  return 0;
}
