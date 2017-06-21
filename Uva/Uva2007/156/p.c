// @JUDGE_ID:  17051CA  156  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<stl.h>

vector<string> dic;

void read(){
  dic.clear();
  string str;
  while(1){
    cin >> str;
    if(str=="#") return ;
    dic.push_back(str);
  }
}

bool isAnagram(string, string);

void work(){
  set<string> goal;
  vector<string> v;

  for(int i=0; i<dic.size(); i++){
    bool anagram = false;
    for(int j=0; j<dic.size(); j++){
      if(i!=j){
	if( isAnagram(dic[i], dic[j]) ){
	  anagram = true;
	  goto next;
	}
      }
    }
  next:;
    if(!anagram) goal.insert(dic[i]);	
  }

  v.resize(goal.size());
  copy(goal.begin(), goal.end(), v.begin());
  for(int i=0; i<v.size(); i++){
    cout << v[i] << endl;
  }
}

void toLower(string &str){
  for(int i=0; i<str.size(); i++){
    str[i] = tolower(str[i]);
  }
}

bool isAnagram(string s1, string s2){
  if(s1.size() != s2.size()) return false;
  toLower(s1);
  toLower(s2);

  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());

  for(int i=0; i<s1.size(); i++){
    if(s1[i] != s2[i]) return false;
  }
  return true;
}

main(){
  read();  
  work();
}
// @end_of_source_code
