// @JUDGE_ID:  17051CA  498  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>

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

string line1, line2;

int read(){
  getline(cin, line1);
  if(cin.eof()) return 0;
  getline(cin, line2);
  return 1;
}

void work(){
  vector<string> coefficient;
  vector<string> value;

  split(coefficient, line1);
  split(value, line2);

  int n = coefficient.size();
  
  for(int i=0; i<value.size(); i++){
    if(i!=0) cout << " ";
    int v = atoi(value[i].c_str());
    int ans = 0;
    for(int j=n-1; j>=0; j--){
      int c = atoi(coefficient[n-j-1].c_str());
      ans += c*(int)pow(v, j);
    }
    cout << ans;
  }
  cout << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
