// @JUDGE_ID:  17051CA  483  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<vector>

void work();

void work(){
  char c;
  string str;

  str = "";
  while(1){
    cin.get(c);
    if(cin.eof()) {
      reverse(str.begin(), str.end());
      cout << str;
      return;
    }

    if(c=='\r') continue;
    if(c=='\n'){
      reverse(str.begin(), str.end());
      cout << str << endl ;
      str = "";
      continue;
    }
    if(c==' '){
      reverse(str.begin(), str.end());
      cout << str;
      str = "";
      cout << c;
    }else{
      str += c;
    }
  }
}

main(){
  work();
}
// @end_of_source_code
