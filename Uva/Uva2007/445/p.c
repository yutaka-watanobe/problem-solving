// @JUDGE_ID:  17051CA  445 C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

void work();

void work(){

  char c;
  char prev;
  int sum;
  
  sum = 0;
  prev = ' ';
  while( scanf("%c", &c ) != EOF ){
    if( c== '\n' && prev != '!'){
      cout << endl;
    }else if( c=='!' && prev != '!'){
      cout << endl;
    }else if( isdigit(c) ){
      sum += c -'0';
    }else{
      if( c=='b') c = ' ';
      for(int i=0; i<sum; i++) cout << c;
      sum = 0;
    }
    prev = c;
  }
  cout << endl;
}

main(){
  work();
}
// @end_of_source_code
