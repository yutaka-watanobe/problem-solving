// @JUDGE_ID:  17051CA  628  C++
// @begin_of_source_code
/* 再帰 */
/* 全てのパターンを見つける */

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

int n, m;
string str;
vector<string> pattern;
vector<string> word;
string current_p;

int read(){
  cin >> n;
  if(cin.eof()) return 0;
  word.clear();
  pattern.clear();
  for(int i=0; i<n; i++){
    cin >> str;
    word.push_back(str);
  }
  cin >> m;
  for(int i=0; i<m; i++){
    cin>> str;
    pattern.push_back(str);
  }
  return 1;
}

void rec(int x, string w){

  if(x==current_p.size()){
    cout << w << endl;
    return;
  }

  string tw;
  if(current_p[x]=='#'){
    for(int i=0; i<word.size(); i++){
      tw = w;
      tw += word[i];
      rec(x+1, tw);
    }
  }else{
    for(int i=0; i<=9; i++){
      tw = w;
      char c = i + '0';
      tw += c;
      rec(x+1, tw);
    }
  }
}

void work(){
  cout << "--" << endl;
  for(int i=0; i<pattern.size(); i++){
    current_p = pattern[i];
    rec(0, "");
  }
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
