#include<iostream>
#include<string>

using namespace std;

bool isA(string s){
  if ( s.substr(0, 2) != ">'" || s[s.size()-1] != '~' ) return false;
  int c = s.find('#');
  if ( c == string::npos ) return false;
  if ( c - 2 != s.size() - 1 - (c+1) ) return false;
  for (int i = 2; i < c; i++ ) if ( s[i] != '=' || s[c+i-1] != '=' ) return false;
  return s.size() > 4;
}

bool isB(string s){
  if ( s.substr(0, 2) != ">^" || s.substr(s.size()-2, 2) != "~~" ) return false;
  for (int i = 2; i <= s.size() - 4; i += 2 )
    if ( s.substr(i, 2) != "Q=" ) return false;
  return s.size() > 4;
}

int main(){
  int n; cin >> n;
  for ( int i = 0; i < n; i++ ) {
    string snake; cin >> snake;
    if ( isA(snake) ) cout << "A" << endl;
    else if ( isB(snake) ) cout << "B" << endl;
    else cout << "NA" << endl;
  }
  return 0;
}
