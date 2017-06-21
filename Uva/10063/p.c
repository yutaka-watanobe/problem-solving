// @JUDGE_ID:  17051CA  10063  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

string str;
int pos;
int size;

void rec(char c, string s, int i);

void work(){
  size = str.size();
  if(size==1){
    cout << str << endl;
    return;
  }
  string s = "";
  s += str[0];
  pos = 1;
  rec(str[pos], s, 1);
}

void rec(char c, string s, int p){
  string tmp;
  for(int i=0; i<s.size(); i++){
    tmp = s;
    tmp.insert(tmp.begin()+i, c);
    if(tmp.size()==size) cout << tmp << endl;
    else rec(str[p+1], tmp, p+1);
  }
  tmp = s;
  tmp += c;
  if(tmp.size()==size)cout << tmp << endl;
  else rec(str[p+1], tmp, p+1);
}

main(){
  bool start = true;
  while(cin >> str){
    if(!start) cout << endl;
    work();
    start = false;
  }
}
// @end_of_source_code
