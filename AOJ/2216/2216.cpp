#include<iostream>
using namespace std;

main(){
  static int C[3] = {1000, 500, 100}, ans[3];
  int a, b;
  while(1){
    cin >> a >> b;
    if ( a== 0 && b == 0 ) break;
    b -= a;
    for ( int i = 0; i < 3; i++ ){
      ans[3-i-1] = b/C[i];
      b = b%C[i];
    }
    for ( int i = 0; i < 3; i++ ){
      if (i) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }
}
