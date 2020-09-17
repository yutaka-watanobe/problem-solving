#include<iostream>
#include<string>
using namespace std;

int main(){
  int n; cin >> n;
  for ( int t = 0; t < n; t++ ) {
    string s; cin >> s; // 巡回記録
    string form;        // 列車の編成
    form += s[0];
    for ( int i = 3; i < s.size(); i += 3 ){
      if ( form.find(s[i]) != string::npos ) continue;
      if ( s[i - 1] == '>' ) form += s[i];
      else form = s[i] + form;
    }
    cout << form << endl;
  }
  return 0;
}
