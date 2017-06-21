#include<iostream>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)


main(){
  int N; cin >> N;
  int k; cin >> k;
  int x, y;
  rep(i, k){
    cin >> x >> y;
    if ( x >= (N+1)/2 ) x = N - x + 1;
    if ( y >= (N+1)/2 ) y = N - y + 1;
    int p = min(x, y);
    cout << (p-1)%3 + 1 << endl;
  }
}
