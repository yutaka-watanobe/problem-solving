#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)

bool check(string line){
  stack<char> S;
  char ch;
  for ( int i = 0; i < line.size()-1; i++ ){
    if ( line[i] == '(' ){
      S.push('(');
    } else if ( line[i] == '[' ){
      S.push('[');
    } else if ( line[i] == ')' ){
      if ( S.size() == 0) return false;
      ch = S.top(); S.pop();
      if ( ch != '(' ) return false;
    } else if ( line[i] == ']' ){
      if ( S.size() == 0) return false;
      ch = S.top(); S.pop();
      if ( ch != '[' ) return false;
    } 
  }
  return S.size() == 0;
}

main(){
  string line;
  while(1){
    getline(cin, line);
    if ( line == "." ) break;
    if ( check(line) ) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}
