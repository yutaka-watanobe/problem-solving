// @JUDGE_ID:  17051CA  494  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

void work();

void work(){
  string line, str;
  int cnt;
  char c;
  str = "";
  cnt = 0;

  while(1){
    cin.get(c);
    if(cin.eof()){
      break;
    }
    
    if( c=='\n'){
      if( str.size() > 0 ) cnt++;
      cout << cnt << endl;
      cnt = 0;
      str = "";
      continue;
    }

    if( isalpha(c) ){
      str += c;
    }else {
      if( str.size() > 0 ) cnt++;
      str = "";
    }
  }

}

main(){
  work();
}
// @end_of_source_code
