// @JUDGE_ID:  17051CA  10079  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>

long long n;

int read(){
  cin >> n;
  if(n<0) return 0;
  return 1;
}

main(){
  while(read()){
    cout << n*(n+1)/2 + 1 << endl;
  }
}
// @end_of_source_code
