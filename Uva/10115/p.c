// @JUDGE_ID:  17051CA  10115  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

int n;

int read(){
  string line;
  getline(cin, line);
  n = atoi(line.c_str());
  if(n==0) return 0;
  return 1;
}

void work(){
  string s1, s2, str;
  vector<string> v;
  vector<string> mp;

  for(int i=0; i<n; i++){
    getline(cin, s1);
    getline(cin, s2);
    v.push_back(s1);
    mp.push_back(s2);
  }
  getline(cin, str);

  string::size_type pos;
  for(int i=0; i<v.size(); i++){
    while(1){
      pos = str.find(v[i]);
      if(pos!=string::npos){
	str.replace(pos, v[i].size(), mp[i]);
      }else{ break;}
    }
  }

  cout << str << endl;

}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
