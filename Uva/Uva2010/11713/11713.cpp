// 11713:Abstract Name:1.0:Writing String char
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>

using namespace std;

#define rep(i, n) for ( int i = 0; i < (int)n; i++)

bool isVowel(char c){
  return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
}
bool check(string s1, string s2){
  if ( s1.size() != s2.size() ) return false;
  
  rep(i, s1.size() ){
    char c1 = s1[i];
    char c2 = s2[i];
    if ( isVowel(c1) && !isVowel(c2) ) return false;
    if ( !isVowel(c1) && isVowel(c2) ) return false;
    if ( !isVowel(c1) && !isVowel(c2) && c1 != c2) return false;
  }
  return true;
}

main(){
  int tcase; cin >> tcase;
  string s1, s2;
  rep(t, tcase){
    cin >> s1 >> s2;
    if ( check(s1, s2) ) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
