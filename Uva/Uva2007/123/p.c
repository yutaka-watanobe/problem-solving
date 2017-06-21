// @JUDGE_ID:  17051CA  123  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>


void split(vector<string> &d, const string &s, char c=' '){
  d.clear();
  string t = "";
  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

void toupper(string &s){
  for(int i=0; i<s.size(); i++)
    s[i] = toupper(s[i]);
}

void tolower(string &s){
  for(int i=0; i<s.size(); i++) 
    s[i] = tolower(s[i]);
}

string line;
vector<string> ignore;
vector<string> title;

int read(){
  while(1){
    getline(cin, line);
    if(line=="::") break;
    ignore.push_back(line);
  }
  while(1){
    getline(cin, line);
    if(cin.eof()) return 1;
    tolower(line);
    title.push_back(line);
  }
}

void work(){
  sort(ignore.begin(), ignore.end());

  pair<string, int> p;
  map<int, vector<string> > mp;
  vector<pair<string, int> > kwic;
  
  vector<string> l;
  int index = 0;

  for(int i=0; i<title.size(); i++){
    string t = title[i];
    split(l, t);
    for(int j=0; j<l.size(); j++){
      if(!binary_search(ignore.begin(), ignore.end(), l[j])){
	p.first = l[j]; p.second = index;
	kwic.push_back(p);
	mp[index] = l;
	index++;
      }
    }
  }

  sort(kwic.begin(), kwic.end());

  for(int i=0; i<kwic.size(); i++){
    p = kwic[i];
    l = mp[p.second];
    for(int j=0; j<l.size(); j++){
      //if(j!=0) cout << " ";
      if(l[j]==p.first) {
	string tmp = l[j];
	toupper(tmp);
	cout << tmp;
      }
      else cout << l[j];
      cout << " ";
    }
    cout << endl;
  }
  

  

}

main(){
  read();
  work();
}
// @end_of_source_code
