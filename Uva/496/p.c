// @JUDGE_ID:  17051CA  496  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>


/*
 * Split a string object by a delimiter( default = ' ')
 * requirement: #include <string>, #include <stl.h>
 */
void split(vector<int> &d, string &s, char c=' '){
  string t = "";

  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(atoi(t.c_str())); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(atoi(t.c_str()));
}

string line1, line2;


int read(){
  char buf[10000];

  cin.getline(buf, 10000);
  if(cin.eof()) return 0;
  line1 = buf;
  cin.getline(buf, 10000);
  line2 = buf;
  return 1;
}

void work(){
  vector<int> A, B;
  split(A, line1);
  split(B, line2);

  int n = min(A.size(), B.size());
  int a = A.size();
  int b = B.size();
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int much = 0;

  map<int, bool> m;

  for(int i=0; i<a; i++){
    for(int j=0; j<b; j++){
      if(A[i]==B[j] && !m[A[i]]){
	m[A[i]] = true;
	much++;
      }
    }
  }

  if(a==b && a==much) cout << "A equals B" << endl;
  else if(a>b && b==much) cout << "B is a proper subset of A" << endl;
  else if(b>a && a==much) cout << "A is a proper subset of B" << endl;
  else if(much==0) cout << "A and B are disjoint" << endl;
  else cout << "I'm confused!" << endl;
  
  

}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
