#include<iostream>
#include<string>
using namespace std;

int simulate(string S){
  char cur = 'A';
  for ( int i = 0; i < S.size(); i++ ){
    int u = S[i]-'0';
    if ( cur == 'A' ) cur = u ? 'Y' : 'X';
    else if ( cur == 'W' ) cur = u ? 'Y' : 'B';
    else if ( cur == 'X' ) cur = u ? 'Z' : ' ';
    else if ( cur == 'Y' ) cur = u ? ' ' : 'X';
    else if ( cur == 'Z' ) cur = u ? 'B' : 'W';
    else if ( cur == 'B' ) cur = u ? 'X' : 'Y';
    if ( cur == ' ' ) return 0;
  }
  return cur == 'B';
}

int main(){
  string S;
  while(1){
    cin >> S;
    if ( S[0] == '#' ) break;
    if (simulate(S)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
