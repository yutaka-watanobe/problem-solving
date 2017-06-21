#include<iostream>
using namespace std;
#define rep(i,n) for ( int i = 0; i <= n; i++)
#define L 9
main(){
  int n;
  while( cin >> n){
    int cnt = 0;
    rep(a,L) rep(b,L) rep(c,L) rep(d,L){
      if ( a + b + c + d == n ) cnt++;
    }
    cout << cnt << endl;
  }
}
