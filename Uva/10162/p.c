// @JUDGE_ID:  17051CA  10162  C++
// @begin_of_source_code
/* 数論 */
/* パターンを見つける */
#include<stdio.h>
#include<iostream>
#include<string>

string line;

int read(){
  cin >> line;
  if(line=="0") return false;
  return true;
}

int v[100];

void init(){
  int sum = 0;
  v[0] = 0;
  for(int i=1; i<100; i++){
    int y =1;
    for(int j=0; j<i; j++){
      y *= i;
      y = y%10;
    }
    sum += y;
    v[i] = sum%10;
  }
}

void work(){

  if(line.size()>3){
    line = line.substr(line.size()-3, 3);
  }

  int x = atoi(line.c_str());

  x = x%100;
  
  cout << v[x] << endl;
}

main(){
  init();
  while(read()){
    work();
  }
}
// @end_of_source_code
