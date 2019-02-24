#include<iostream>
#include<algorithm>
using namespace std;

main(){
  int n, m, s, t;
  cin>> n >> m;
  bool f = true;
  int maxv = m;
  for ( int i = 0; i < n; i++ ){
    cin >> s >> t;
    m = m + s - t;
    if ( m < 0 ) f = false;
    maxv = max(maxv, m);
  }
  if ( !f ) cout << 0 << endl;
  else cout << maxv << endl;

}
