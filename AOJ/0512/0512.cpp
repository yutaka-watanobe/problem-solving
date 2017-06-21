#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;
  cin >> s;
  for ( int i = 0; i < s.size(); i++ ) cout << (char)((s[i] - 'A' + 23)%26 + 'A');
  cout << endl;
}
