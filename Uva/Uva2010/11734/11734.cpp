#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

string normalize(string str ){
  string s = "";
  rep(i, str.size() ) if ( str[i] != ' ' ) s += str[i];
  return s;
}

string judge(string str1, string str2 ){

  if ( str1 == str2 ) return "Yes"; 

  str1 = normalize(str1);
  str2 = normalize(str2);
  
  if ( str1 == str2 ) return "Output Format Error";

  return "Wrong Answer"; 
}

main(){
  string str1, str2;
  int t; cin >> t;
  getline(cin, str1);
  rep(i, t){
    getline(cin, str1);
    getline(cin, str2);
    cout << "Case " << i+1 << ": " << judge(str1, str2) << endl;
  }
}


 
