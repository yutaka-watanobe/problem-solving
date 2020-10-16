#include<iostream>
#include<vector>
using namespace std;
int N;
vector<string> G;

void rotate(){
  vector<string> T = G;
  for ( int i = 0; i < N; i++ )
    for ( int j = 0; j < N; j++ )
      G[j][N-i-1] = T[i][j];
}

int main(){
  int Q;
  int cnt = 4 * 100000;
  cin >> N;
  G.resize(N);
  for ( int i = 0; i < N; i++ ) cin >> G[i];
  cin >> Q;
  for ( int i = 0; i < Q; i++ ){
    int q; cin >> q; cnt += q;
  }
  cnt %= 4;
  for ( int i = 0; i < cnt; i++ ) rotate();
  for ( int i = 0; i < N; i++ ) cout << G[i] << endl;
  
  return 0;
}
