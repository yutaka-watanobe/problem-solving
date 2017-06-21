#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
main(){
  int d, n, m, k;
  while( cin >> d && d ){
    cin >> n >> m;
    vector<int> v;
    v.push_back(0);
    rep(i, n-1){
      cin >> k;
      v.push_back(k);
    }
    v.push_back(d);
    sort(v.begin(), v.end());

    int sum = 0;
    rep(i, m){
      cin >> k;
      vector<int>::iterator pos = upper_bound(v.begin(), v.end(), k)-1;
      sum += min(k - *pos, *(pos+1) - k );
    }
    cout << sum << endl;
  }
}
