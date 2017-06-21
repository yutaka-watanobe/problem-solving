#include<iostream>
#include<string>
using namespace std;
main(){
  string s;
  cin >> s;
  if ( s[0] == 'x' && s[s.size()-1] == 'x' ) cout << "x" << endl;
  else cout << "o" << endl;
}
