#include<iostream>
#include<vector>
#include<string>

using namespace std;

#define rep(i, n) for ( int i = 0; i < (int)n; i++)

main(){
  int tcase, d; cin >> tcase;
  string num;
  rep(t, tcase){
    int sum = 0;
    rep(i, 4) {
      cin >> num;
      d = num[0]-'0'; d *= 2; sum += d/10 + d%10;
      d = num[2]-'0'; d *= 2; sum += d/10 + d%10;
      sum += (num[1]-'0') + (num[3]-'0');
    }
    if ( sum % 10 == 0 ) cout << "Valid" << endl;
    else cout << "Invalid" << endl;
  }
}
