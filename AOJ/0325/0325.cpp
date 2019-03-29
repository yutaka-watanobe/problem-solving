#include<iostream>
#include<algorithm>
using namespace std;

bool solve(){
  pair<int, int> D[6];
  for ( int i = 0; i < 6; i++ ) {
    cin >> D[i].first >> D[i].second;
    if ( D[i].first > D[i].second) swap(D[i].first, D[i].second);
  }
  sort(D, D+6);
  for ( int i = 0; i < 6; i+=2){
    if ( D[i] == D[i+1] ) D[i/2] = D[i];
    else return false;
  }

  return D[0].first == D[1].first && D[0].second == D[2].first && D[1].second == D[2].second;
}

main(){
  if ( solve() ) cout << "yes" << endl;
  else cout << "no" << endl;
}


