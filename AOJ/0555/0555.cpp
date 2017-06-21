/**
 * String find
 **/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)

main(){
  string pattern, target; cin >> pattern;
  int n; cin >> n;
  int cnt = 0;
  rep(i, n){
    cin >> target;
    target += target;
    if ( target.find(pattern) != string::npos ) cnt++;
  }
  cout << cnt << endl;
}
