#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

main(){
  char ch;
  int id, p, t;
  vector<pair<int, int> > T;
  vector<int> R, TR;
  while(1){
    cin >> id >> ch >> p;
    if ( id == 0 && p == 0 ) break;
    T.push_back(make_pair(p, id));
  }
  sort(T.begin(), T.end());
  reverse(T.begin(), T.end());
  R.resize(T.size());
  TR.resize(T.size());
  int rank = 1;
  R[0] = rank;
  for ( int i = 1; i < T.size(); i++ ) {
    if ( T[i-1].first == T[i].first ) R[i] = rank;
    else R[i] = ++rank;
  }
  for ( int i = 0; i < T.size(); i++ ) TR[T[i].second-1] = R[i];
  while( cin >> t ) cout << TR[t-1] << endl;
}
