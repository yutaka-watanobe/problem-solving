// @JUDGE_ID:  17051CA  10260  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>

string line;
map<char, int> mp;

int read(){
  cin >> line;
  if(cin.eof()) return 0;
  return 1;
}

void work(){

  int pre = -1;

  for(int i=0; i<line.size(); i++){
    char c = line[i];
    int x = mp[c];
    if(pre!=x && x!=0) cout << x;
    pre = x;
  }
  cout << endl;
}

main(){
  mp['A'] = 0;
  mp['B'] = 1;
  mp['C'] = 2;
  mp['D'] = 3;
  mp['E'] = 0;
  mp['F'] = 1;
  mp['G'] = 2;
  mp['H'] = 0;
  mp['I'] = 0;
  mp['J'] = 2;
  mp['K'] = 2;
  mp['L'] = 4;
  mp['M'] = 5;
  mp['N'] = 5;
  mp['O'] = 0;
  mp['P'] = 1;
  mp['Q'] = 2;
  mp['R'] = 6;
  mp['S'] = 2;
  mp['T'] = 3;
  mp['U'] = 0;
  mp['V'] = 1;
  mp['W'] = 0;
  mp['X'] = 2;
  mp['Y'] = 0;
  mp['Z'] = 2;
  while(read()){
    work();
  }
}
// @end_of_source_code
