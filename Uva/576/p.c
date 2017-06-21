// @JUDGE_ID:  17051CA  576  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

void split(vector<string> &d, const string &s, char c='/'){
  string t = "";

  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

string line;
int read(){
  getline(cin, line);
  if(line=="e/o/i") return 0;
  return 1;
}

bool isVowel(char c){
  if(c=='a' || c=='i' || c=='u' || c=='e' || c=='o' || c=='y') return true;
  else return false;
}

void work(){
  vector<string> haiku;
  split(haiku, line);
  int cnt[3];
  for(int i=0; i<3; i++) cnt[i] = 0;

  char p, c;
  for(int i=0; i<3; i++){
    string h = haiku[i];
    p = ' ';
    for(int j=0; j<h.size(); j++){
      c = h[j];
      if(isVowel(c) && !isVowel(p) ) cnt[i]++;
      p = c;
    }
  }

  for(int i=0; i<3; i++){
    if(i==1){
      if(cnt[i]!=7){
	cout << "2" << endl;
	return;
      }
    }else{
      if(cnt[i]!=5){
	cout << i+1 << endl;
	return;
      }
    }
  }
  
  cout << "Y" << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
