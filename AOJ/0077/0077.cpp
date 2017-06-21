#include<iostream>
#include<string>
using namespace std;

main(){
  string s;
  while( cin >> s ){
    for ( int i = 0; i < s.size(); i++ ){
      if ( s[i] == '@' ){
	int v = s[i+1]-'0';
	char c = s[i+2];
	i += 2;
	for ( int j = 0; j < v; j++ ) cout << c;
      } else { cout << s[i]; }
    }
    cout << endl;
  }
}
