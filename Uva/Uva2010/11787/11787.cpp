// 11787:Numeral Hieroglyphs:1.0:Writing
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

map<char, int> M;
map<char, int> I;

bool checkR(string str){
  for ( int i = 1; i < str.size(); i++ ){
    if ( I[str[i-1]] > I[str[i]] ) return false;
  }
  return true;
}

bool check(string str){
  int cnt[7];
  rep(i, 7) cnt[i] = 0;

  for ( int i = 0; i < str.size(); i++ ){
    char ch = str[i];
    cnt[I[ch]]++;
  }

  string str2 = str;
  reverse(str2.begin(), str2.end());

  if ( !( checkR(str) || checkR(str2) ) ) return false;

  rep(i, 7 ) if (cnt[i] >9 ) return false;
  return true;
}

void compute(){
  string str; cin >> str;

  if ( !check(str) ) {
    cout << "error" << endl; return;
  }

  int sum = 0;
  rep(i, str.size()){
    sum += M[str[i]];
  }
  
  cout << sum <<endl;

  

}

main(){
  M['B'] = 1;
  M['U'] = 10;
  M['S'] = 100;
  M['P'] = 1000;
  M['F'] = 10000;
  M['T'] = 100000;
  M['M'] = 1000000;

  I['B'] = 0;
  I['U'] = 1;
  I['S'] = 2;
  I['P'] = 3;
  I['F'] = 4;
  I['T'] = 5;
  I['M'] = 6;

  int tcase; cin >> tcase;
  rep(t, tcase){
    compute();
  }
}
