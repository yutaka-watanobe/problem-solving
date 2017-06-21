// @JUDGE_ID:  17051CA  148  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>

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

vector<string> words;
vector<string> com;
map<char, int> mp;
int leng;
string phrase;

int read(){
  string line;
  while(1){
    getline(cin, line);
    if(line[0]=='#') break;
    words.push_back(line);
  }
}

bool check(vector<string> list){
  for(int i=0; i<list.size(); i++){
    for(int j=0; j<com.size(); j++){
      if(list[i]==com[j]) return true;
    }
  }
  return false;
}

void rec(int index, map<char, int> m, vector<string> list, int len){
  if(index>=words.size()) return ;

  string str = words[index];
  char c;
  /*check*/
  bool ok = true;
  for(int i=0; i<str.size(); i++){
    c = str[i];
    if(m[c]+1>mp[c]) {
      ok = false;
      break;
    }
  }

  if(ok){
    rec(index+1, m, list, len);
    for(int s=0; s<str.size(); s++){
      c = str[s];
      m[c]++;
    }
    len += str.size();
    
    list.push_back(str);
  
    if(leng==len){
      if(check(list)) return;
      cout << phrase << " = ";
      for(int v=0; v<list.size(); v++){
	if(v!=0) cout << " ";
	cout << list[v];
      }
      cout << endl;
      return;
    }
  }

}

void work(){

  while(1){
    getline(cin, phrase);
    if(phrase[0]=='#') break;
    
    com.clear();
    split(com, phrase);
    mp = map<char,int>();

    leng = 0;
    for(int s=0; s<phrase.size(); s++){
      char c = phrase[s];
      if(c!=' ') {
	mp[c]++;
	leng++;
      }
    }

    vector<string> list;
    map<char, int> m;
    rec(0, m, list, 0);

  }

}

main(){
  read();
  work();
}
// @end_of_source_code
