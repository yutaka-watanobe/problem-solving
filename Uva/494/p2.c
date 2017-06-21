// @JUDGE_ID:  17051CA  494  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

void split(vector<string> &d, const string &s, char c=' '){
  string t = "";
  for(int i=0; i<s.size(); i++){
    if(s[i]==c){
      if(t!=""){d.push_back(t); t= "";}
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

void work();

void work(){
  string line, str;
  vector<string> v;
  int cnt;

  while(1){
    getline(cin, line);
    if(cin.eof()) break;
    v.clear();
    split(v, line);
    
    cnt = 0; 
    for(int i=0; i<v.size(); i++){
      str = v[i];
      bool isA = false;
      for(int s=0; s<str.size(); s++){
	if(isalpha(str[s])) {isA = true; }
      }
      if(isA) cnt++;
    }
    cout << cnt << endl;
  }

}

main(){
  work();
}
// @end_of_source_code
