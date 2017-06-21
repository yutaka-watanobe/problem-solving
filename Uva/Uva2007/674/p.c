// @JUDGE_ID:  17051CA  674  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

int coin[5] = {1, 5, 10, 25, 50};
long long T[7500];
int cent;

int read(){
  cin >> cent;
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  cout << T[cent] << endl;
}

void init(){
  for(int i=0; i<=7499; i++) T[i] = 1;
  for(int k=1; k<5; k++){
    for(int n=coin[k]; n<=7499; n++){
      T[n] += T[n-coin[k]];
    }
  }
}

main(){
  init();
  while(read()){
    work();
  }
}

// @end_of_source_code
