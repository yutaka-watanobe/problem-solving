#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int> R, vector<int> L){
  if ( R.size() == 0 || L.size() == 0 ) return 0;
  sort(R.begin(), R.end());
  sort(L.begin(), L.end());
  return R[0] + L[0];
}

int main() {
  int A[10], W[10];
  int N, a, w;
  vector<int> R, L;
  cin >> N;
  for ( int i = 0; i < N; i++ ) cin >> A[i];
  for ( int i = 0; i < N; i++ ) cin >> W[i];
  for ( int i = 0; i < N; i++ ){
    if ( A[i] == 0 ) R.push_back(W[i]);
    if ( A[i] == 1 ) L.push_back(W[i]);
  }

  cout << solve(R, L) << endl;
}

