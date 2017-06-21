#include<iostream>
#include<string>
using namespace std;
string s;

bool check( char ch ){
  if ( s[0] == ch && s[1] == ch && s[2] == ch ) return true;
  if ( s[3] == ch && s[4] == ch && s[5] == ch ) return true;
  if ( s[6] == ch && s[7] == ch && s[8] == ch ) return true;
  if ( s[0] == ch && s[3] == ch && s[6] == ch ) return true;
  if ( s[1] == ch && s[4] == ch && s[7] == ch ) return true;
  if ( s[2] == ch && s[5] == ch && s[8] == ch ) return true;
  if ( s[0] == ch && s[4] == ch && s[8] == ch ) return true;
  if ( s[2] == ch && s[4] == ch && s[6] == ch ) return true;
  return false;
}

main(){
  while( cin >> s ){
    if ( check('o') ) cout << 'o' << endl;
    else if ( check('x') ) cout << 'x' << endl;
    else cout << 'd' << endl;
  }
}
