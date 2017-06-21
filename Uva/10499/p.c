// @JUDGE_ID:  17051CA  10499  C++
// @begin_of_source_code
/* ·×»» */
/* N*PI*r*r / 4*PI*r*r = N/4 */
#include<stdio.h>
#include<iostream>
#include<string>

long long N;

int read(){
  cin >> N;
  if(N<0) return 0;
  return 1;
}

void work(){
  if(N==1){
    cout << "0%" << endl;
    return;
  }
  cout << (100*N)/4 << "%" << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
