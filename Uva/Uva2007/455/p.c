// @JUDGE_ID:  17051CA  455  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

string str;

void work(){
  cin >> str;

  int len_pos = 0;
  string sub = "";
  int pos;

  while(1){
    
    sub += str[len_pos];
    pos = 0;

    for(int i=0; i<str.size(); i++){
      if(sub[pos]!=str[i]){
	goto next;
      }else{
	pos++;
	if(pos>sub.size()-1) pos = 0;
      }
    }
    
    if(pos==0){
      cout << sub.size() << endl;
      return;
    }

  next:;

    len_pos++;

  }
  
}

main(){
  int testCase;
  cin >> testCase;
  for(int i=0; i<testCase; i++){
    work();
    cout << endl;
  }
}
// @end_of_source_code
