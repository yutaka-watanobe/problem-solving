// @JUDGE_ID:  17051CA  10361  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

void work(){
  string l1, l2;
  getline(cin, l1);
  getline(cin, l2);
  vector<string> v;
  v.clear();
  string str = "";
  int index = 0;
  char c;
  for(int i=0; i<l1.size(); i++){
    c = l1[i];
    if(c=='<' || c=='>'){
      v.push_back(str);
      str = "";
    }else{
      str += c;
    }
    if(i==l1.size()-1){
      v.push_back(str);
    }
  }

  for(int i=0; i<3; i++) l2.erase(l2.end()-1);

  for(int i=0; i<l1.size(); i++){
    c = l1[i];
    if(c!='>' && c!='<') cout << c;
  }
  cout << endl;
  cout << l2 << v[3] << v[2] << v[1] << v[4] << endl;
}

main(){
  string line;
  int n;
  getline(cin, line);
  n = atoi(line.c_str());
  for(int i=0; i<n; i++){
    work();
  }
}
// @end_of_source_code
