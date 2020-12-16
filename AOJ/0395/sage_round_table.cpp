#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
static const int INF = 100000;

int main() {
  int N, a[10];
  cin >> N;
  for ( int i = 0; i < N; ++i ) cin >> a[i];

  int lmin = INF;
  int rmin = INF;
  for ( int i = 0; i < N; ++i ) {
    int w; cin >> w;
    if ( a[i] ) lmin = min(lmin, w);
    else rmin = min(rmin, w);
  }
    
  if ( rmin == INF || lmin == INF ) cout << 0 << endl;
  else cout << rmin + lmin << endl;
  return 0;
}
