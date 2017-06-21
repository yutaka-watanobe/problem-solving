// @JUDGE_ID:  17051CA  10127  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

int n;

int read(){
  cin >> n;
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  int a = 1;
  int cnt = 1;

  while(1){

    if(a%n==0){
      cout << cnt << endl;
      break;
    }
    a = a*10 + 1;
    a = a%n;
    cnt++;
  }
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
