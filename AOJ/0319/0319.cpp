#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n, s; cin >> n;
  vector<int> S;
  for ( int i = 0; i < n; i++ ){
    cin >> s;
    S.push_back(s);
  }
  sort(S.begin(), S.end());
  reverse(S.begin(), S.end());
  int ans = 0;
  for ( int i = 0; i < S.size(); i++ ){
    if ( S[i] >= i+1 ) ans = i+1;
  }

  cout << ans << endl;
  return 0;
}
