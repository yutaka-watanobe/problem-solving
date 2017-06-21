#include<stdio.h>
#include<string>
#include<vector>

main(){
  string a = "abc";
  string b = "def";
  string c = "ghi";

  vector<string> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  
  cout << v[1][1] << endl;
}
