#include<iostream>
using namespace std;

int main(){
  int N, K, S[100], k;

  // テストケースを処理するループ
  while(1){
    cin >> N >> K;
    if ( N == 0 && K == 0 ) break;
    // S を読み込む
    for ( int i = 0; i < K; i++ ) cin >> S[i];
    // N 人の吸血鬼について、Sから該当する血の量を引いていく
    for ( int i = 0; i < N; i++ ){
      for ( int j = 0; j < K; j++ ){
	cin >> k;
	S[j] -=k;
      }
    }
    // S[i]の中に１つでも負の値があればNo
    bool ok = true;
    for ( int i = 0; i < K; i++ ) if ( S[i] < 0 ) ok = false;
    if ( ok ) cout << "Yes" << endl;
    else cout << "No" << endl;
    
  }
  return 0;
}
