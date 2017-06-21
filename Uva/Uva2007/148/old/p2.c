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
map<string, bool> has;
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


void rec(int index, bool use, map<char, int> m, vector<string> list, int len){
  if( index>=words.size()) return;

  if(use){
    char c;
    string str = words[index];
    for(int s=0; s<str.size(); s++){
      c = str[s];
      m[c]++;
      if(m[c]>mp[c]) {
	return;
      }
    }
    len+=str.size();
    if( has[str] ) return ;

    list.push_back(str);
  
    if(leng==len){
      cout << phrase << " = ";
      for(int v=0; v<list.size(); v++){
	if(v!=0) cout << " ";
	cout << list[v];
      }
      cout << endl;
      return;
    }
  }

  rec(index+1, true, m, list, len);
  rec(index+1, false, m, list, len);

}

void work(){

  while(1){
    getline(cin, phrase);
    if(phrase[0]=='#') break;
    
    com.clear();
    split(com, phrase);
    
    for(int i=0; i<com.size(); i++){
      has[com[i]] = true;
    }
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
    rec(0, true, m, list, 0);
    rec(0, false, m, list, 0);

  }

}

main(){
  read();
  work();
}
// @end_of_source_code
