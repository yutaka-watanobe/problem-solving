// @JUDGE_ID:  17051CA  642  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<map>

vector<string> v;
map<string, string> mp;

void parse(string str){
  string s1, s2;
  int cnt = 0;
  for(int i=0; i<v.size(); i++){
    if(str.size()==v[i].size()){
      s1 = str;
      s2 = v[i];
      sort(s1.begin(), s1.end());
      sort(s2.begin(), s2.end());
      if(s1==s2){
	cout << v[i] << endl;
	cnt++;
      }
    }
  }

  if(cnt==0) cout << "NOT A VALID WORD" << endl;
}

void work(){
  string line;

  
  while(1){
    cin >> line;
    if(line=="XXXXXX") break;
    v.push_back(line);
  }
  sort(v.begin(), v.end());

  while(1){
    cin >> line;
    if(line=="XXXXXX") break;
    parse(line);
    cout << "******" << endl;
  }


}

main(){
  work();
}
// @end_of_source_code
