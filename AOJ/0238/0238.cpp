#include<iostream>
using namespace std;

main(){
  int t, n, st, ft;
  while(1){
    cin >> t;
    if ( t == 0 ) break;
    cin >> n;
    int sum = 0;
    for ( int i = 0; i < n;  i++ ){
      cin >> st >> ft;
      sum += ft - st;
    }
    if ( sum >= t ) cout << "OK" << endl;
    else cout << t - sum << endl;
  }
}
