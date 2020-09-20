#include<iostream>
using namespace std;
static const int N = 6;

bool solve(){
  pair<int, int> D[N];
  for ( int i = 0; i < N; i++ ) {
    cin >> D[i].first >> D[i].second;
    if ( D[i].first > D[i].second) swap(D[i].first, D[i].second);
  }

  // バブルソート
  for ( int i = 0; i < N - 2; i++ ){
    for ( int j = N - 2; j >= i; j-- ){
      if ( D[j] > D[j + 1] ) swap(D[j], D[j + 1]);
    }
  }

  for ( int i = 0; i < N; i += 2){
    if ( D[i] != D[i + 1] ) return false;
  }

  return D[0].first == D[2].first && D[0].second == D[4].first && D[2].second == D[4].second;
}

int main(){
  cout << (solve() ? "yes" : "no") << endl;
  return 0;
}





