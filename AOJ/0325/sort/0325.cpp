#include<iostream>
#include<algorithm>
using namespace std;
static const int N = 6;

bool solve(){
  pair<int, int> D[N];
  for ( int i = 0; i < N; i++ ) {
    cin >> D[i].first >> D[i].second;
    if ( D[i].first > D[i].second) swap(D[i].first, D[i].second);
  }
  sort(D, D + N);
  for ( int i = 0; i < N; i += 2){
    if ( D[i] != D[i+1] ) return false;
  }

  return D[0].first == D[2].first && D[0].second == D[4].first && D[2].second == D[4].second;
}

main(){
  if ( solve() ) cout << "yes" << endl;
  else cout << "no" << endl;
}


