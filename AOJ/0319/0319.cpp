#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int N; cin >> N;
  int p[101];
  for ( int i = 0; i < N; i++ ) cin >> p[i];

  sort(p, p + N);
  reverse(p, p + N);
  
  int ans = 0;
  for ( int i = 0; i < N; i++ ){
    if ( p[i] >= i + 1 ) ans = i + 1;
  }

  cout << ans << endl;
  return 0;
}
