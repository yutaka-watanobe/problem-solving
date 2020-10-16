#include<iostream>
using namespace std;
int N;
string G[1000], T[1000];

void rotate(){
  for ( int i = 0; i < N; i++ )
    for ( int j = 0; j < N; j++ )
      T[j][N-i-1] = G[i][j];
  for ( int i = 0; i < N; i++ ) G[i] = T[i];
}

int main(){
  int Q;
  int cnt = 4 * 100000;
  cin >> N;
  for ( int i = 0; i < N; i++ ) {
    cin >> G[i];
    T[i] = G[i];
  }
  cin >> Q;
  for ( int i = 0; i < Q; i++ ){
    int q; cin >> q; cnt += q;
  }
  cnt %= 4;
  for ( int i = 0; i < cnt; i++ ) rotate();
  for ( int i = 0; i < N; i++ ) cout << G[i] << endl;
  
  return 0;
}
