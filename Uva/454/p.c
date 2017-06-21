// @JUDGE_ID:  17051CA  454  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

string line;
int A[128];
int B[128];

bool check(string s1, string s2){
  for(int i=0; i<128; i++) {A[i]=0; B[i]=0;}
  for(int i=0; i<s1.size(); i++){
    if(s1[i]!=' '){
      A[s1[i]]++;
    }
  }
  for(int i=0; i<s2.size(); i++){
    if(s2[i]!=' '){
      B[s2[i]]++;
    }
  }

  for(int i=0; i<128; i++){
    if(A[i]!=B[i]) return false;
  }
  return true;
}

void work(){
  vector<string> v;

  while(1){
    getline(cin, line);
    if(line=="" || cin.eof()) break;
    v.push_back(line);
  }

  sort(v.begin(), v.end());

  for(int i=0; i<v.size(); i++){
    for(int j=i+1; j<v.size(); j++){
      if(check(v[i], v[j])){
	cout << v[i] << " = " << v[j] << endl;
      }
    }
  }
}

main(){
  int testCase;
  getline(cin, line);
  testCase = atoi(line.c_str());
  getline(cin, line);
  for(int i=0; i< testCase; i++){
    if(i!=0) cout << endl;
    work();
  }
  cout << endl;
}
// @end_of_source_code
