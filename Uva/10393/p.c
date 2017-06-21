// @JUDGE_ID:  17051CA  10393  C++
// @begin_of_source_code
/* シミュレーション */
/* *unique の使い方 */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<vector>

void split(vector<string> &d, const string &s, char c=' '){
  string t = "";

  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

int F, N;
vector<string> finger;
map<char, bool> disable;
string line;

int read(){
  getline(cin, line);
  if(cin.eof()) return 0;

  sscanf(line.c_str(), "%d %d", &F, &N);

  disable = map<char, bool>();
  
  vector<string> v;
  if(F>0) getline(cin, line);
  else line = "";

  split(v, line);
  int k;
  int space = 0;
  for(int i=0; i<v.size(); i++){
    k = atoi(v[i].c_str());
    string s = finger[k-1];
    for(int j=0; j<s.size(); j++){
      disable[s[j]] = true;
    }
    if(k==5 || k==6) space++;
  }
  
  if(space==2) disable[' '] = true;
  else disable[' '] = false;
  return 1;
}

void init(){
  finger.resize(10);

  finger[0] = "qaz";
  finger[1] = "wsx";
  finger[2] = "edc";
  finger[3] = "rfvtgb";
  finger[4] = " ";
  finger[5] = " ";
  finger[6] = "yhnujm";
  finger[7] = "ik,";
  finger[8] = "ol.";
  finger[9] = "p;/";
}

void work(){
  string str;
  int maxS = 0;
  vector<string> able;

  for(int i=0; i<N; i++){
    getline(cin, str);
    for(int j=0; j<str.size(); j++){
      if(disable[str[j]]){
	goto next;
      }
    }
    able.push_back(str);
    if(maxS<str.size()){
      maxS = str.size();
    }
  next:;
  }
  
  vector<string> result;
  for(int i=0; i<able.size(); i++){
    if(able[i].size()==maxS){
      result.push_back(able[i]);
    }
  }

  sort(result.begin(), result.end());
  result.erase(unique(result.begin(), result.end()), result.end());

  cout << result.size() << endl;
  for(int i=0; i<result.size(); i++){
    cout << result[i] << endl;
  }

}

main(){
  init();

  while(read()){
    work();
  }
}
// @end_of_source_code
