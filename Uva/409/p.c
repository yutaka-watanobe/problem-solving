// @JUDGE_ID:  17051CA  409  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

/*
 * Split a string object by a delimiter( default = ' ')
 * requirement: #include <string>, #include <stl.h>
 */
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

/*
 * String object --> Lowercase
 * requirement: #include <string>, #include <ctype.h>
 */
void tolower(string &s){
  for(int i=0; i<s.size(); i++) 
    s[i] = tolower(s[i]);
}

int k, l;

int read(){
  string line;
  getline(cin, line);
  if(cin.eof()) return 0;
  vector<string> com;
  split(com, line);
  k = atoi(com[0].c_str());
  l = atoi(com[1].c_str());
  return 1;
}

void work(){
  string line;
  vector<string> key;
  vector<string> exc;

  for(int i=0; i<k; i++){
    getline(cin, line);
    tolower(line);
    key.push_back(line);
  }
  
  int maxX = 0;
  map<int, int> cnt;

  for(int i=0; i<l; i++){
    getline(cin, line);
    exc.push_back(line);
    tolower(line);

    int pos;
    string ks;
    for(int j=0; j<key.size(); j++){
      pos = line.find(key[j]);
      if(pos == string::npos ) continue;
      
      ks = key[j];
      if(ks == line){
	cnt[i]++;
      }else if(pos==0){
	if(!isalpha(line[ks.size()])) cnt[i]++;
      }else if(pos == line.size()-ks.size()+1){
	if(!isalpha(line[pos-1])) cnt[i]++;
      }else{
	if(!isalpha(line[pos-1]) && !isalpha(line[pos+ks.size()]) ) cnt[i]++;
      }
    }
    maxX = max(maxX, cnt[i]);
  }

  for(int i=0; i<l; i++){
    if(cnt[i] == maxX ){
      cout << exc[i] << endl;
    }
  }

}

main(){
  for(int i=1; read(); i++){
    cout << "Excuse Set #" << i << endl;
    work();
    cout << endl;
  }
}
// @end_of_source_code
