#include<iostream>
#include<string>
using namespace std;

main(){
  string L = "qwertasdfgzxcvb";
  string R = "yuiophjklnm";
  string str;
  char M[256];
  for ( int i = 0; i < L.size(); i++ ) M[L[i]] = 1;
  for ( int i = 0; i < R.size(); i++ ) M[R[i]] = 2;

  while(1){
    cin >> str;
    if ( str == "#" ) break;
    int pre = M[str[0]];
    int cnt = 0;
    for ( int i = 1; i < str.size(); i++ ){
      if ( M[str[i]] != pre ) cnt++;
      pre = M[str[i]];
    }
    cout << cnt << endl;
  }
  return 0;
}
