#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> d;

bool isReachable() {
  int current = 0;
  for ( int i = 0; i < N; i++ ) {
    if ( current < 10 * i ) return false;
    current = max( current, 10 * i + d[i] );
    if ( current >= 10 * N ) return true;
  }
  return false;
}

int main() {
  cin >> N;
  d.resize(N);
  for ( int i = 0; i < N; i++ ) cin >> d[i];
  if ( !isReachable() ) {
    cout << "no" << endl;
    return 0;
  }
    
  reverse( d.begin(), d.end() ); // 列の要素を逆順に変換する
  if ( !isReachable() ) cout << "no" << endl;
  else cout << "yes" << endl;
    
  return 0;
}
