#include<iostream>
#include<string>
using namespace std;

main(){
  string s1, s2;
  cin >> s1 >> s2;

  if ( s1 < s2 ) cout << s1 << " " << s2 << endl;
  else cout << s2 << " " << s1 << endl;
}
