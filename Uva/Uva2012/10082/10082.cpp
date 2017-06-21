#include<iostream>
#include<string>
#include<map>
using namespace std;

main(){
  static const string T = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
  map<char, int> M;
  for ( int i = 0; i < T.size(); i++ ) M[T[i]] = i;
  string line;
  while(1){
    getline(cin, line);
    if ( cin.eof() ) break;
    for ( int i = 0; i < line.size(); i++ ){
      char ch = line[i];
      if ( M.find(ch) != M.end() ) cout << T[M[ch]-1];
      else cout << ch;
    }
    cout << endl;
  }
}
