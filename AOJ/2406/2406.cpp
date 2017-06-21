#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

main(){
  int N, T, E, x;
  cin >> N >> T >> E;
  vector<int> ans;

  for ( int i = 0; i < N; i++ ){
    cin >> x;
    for ( int e = -E; e <= E; e++ ){
      if ((T+e)%x == 0 ) ans.push_back(i+1);
    }
  }
  if ( ans.size() == 0 ) cout << -1 << endl;
  else {
    cout << ans[rand()%(ans.size())] << endl;
  }
}
