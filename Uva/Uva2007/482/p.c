// @JUDGE_ID:  17051CA  482  C++
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

void work(){
  string line1, line2;

  getline(cin, line1); /* brank */
  getline(cin, line1);
  getline(cin, line2);

  vector<string> index;
  vector<string> v;
  map<int, int> m;

  split(index, line1);
  split(v, line2);

  for(int i=0; i<index.size(); i++){
    int id = atoi(index[i].c_str())-1;
    m[id] = i;
  }

  for(int i=0; i<v.size(); i++){
    cout << v[m[i]] << endl;
  }
}

main(){
  int testCase;
  char buf[10000];
  cin.getline(buf, 10000);
  testCase = atoi(buf);
  for(int i=0; i<testCase; i++){
    if(i!=0) cout << endl;
    work();
  }
}
// @end_of_source_code
