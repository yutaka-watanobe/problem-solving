// @JUDGE_ID:  17051CA  10282  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>

void split(vector<string> &d, string &s, char c=' '){
  string t = "";

  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

map<string, string> mp;

int read(){
  string line;
  vector<string> v;
  while(1){
    getline(cin, line);
    if(line.size()==0) return 1;
    v.clear();
    split(v, line);
    mp[v[1]] = v[0];
  }
}

void work(){
  string line, str;
  while(1){
    cin >> line;
    if(cin.eof()) return ;
    str = mp[line];
    if(str.size()==0) cout << "eh" << endl;
    else cout << str << endl;
  }
}

main(){
  read();
  work();
}
// @end_of_source_code
